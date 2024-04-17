class Solution {
public:
    void getRowRecr(int rowIndex, vector<int> &result, vector<int> &prev) {
        if (rowIndex < 0)
            return;
        // if (rowIndex == 0 || rowIndex == 1)
        // {
        //     result.push_back(1);
        // }
        getRowRecr(rowIndex - 1, result, prev);
        result.clear();
        int len = prev.size();
        // cout << rowIndex << " size " << len<< " result " << result.size() << endl;
        for (int col = 0; col <= len; col++)
        {
            if (col == 0 || col == len)
            {
                result.push_back(1);
            }
            else
            {
                result.push_back(prev[col - 1] + prev[col]);
            }
        }
        // cout <<"   result " << result.size() << " \n";
        prev = result;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> prev;
        getRowRecr(rowIndex, result, prev);
        return result;
    }
};