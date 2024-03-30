#include <bits/stdc++.h>

using namespace std;

int get_min_spend(vector<int> products)
{
    int len = products.size();
    unordered_map<int, vector<int>> prod_index;
    unordered_map<int, int> idx_sum;
    int min_spend = numeric_limits<int>::max();
    int idx =0;
    int running_sum = 0;
    for (const auto &prod : products)
    {
        running_sum += prod;
        if (prod_index.count(prod))
        {
            int last_matching_idx = prod_index[prod].back();
            int sub_sum = running_sum;
            if (last_matching_idx != 0)
            {
                sub_sum -= idx_sum[last_matching_idx - 1];
            }
            min_spend = min(min_spend, sub_sum);
        }
        else
        {
            prod_index[prod].push_back(idx);
        }
        idx_sum[idx] = running_sum;
        idx++;
    }
    if (min_spend == numeric_limits<int>::max())
    {
        return -1;
    }
    return min_spend;
}


void print_vec(vector<int> s)
{
    cout<<"[ "; 
    for(int x: s)
    {
        cout<<x<<" "; 
    }
    cout<<" ]"; 
    cout<<endl;
}

int main()
{
    {
    vector<int> temp = {1, 2, 3, 1, 2, 1};
    print_vec(temp);
    cout << "    Expected 4. Got " << get_min_spend(temp) << endl;
    }
    {
    vector<int> temp = {1, 2, 1, 2};
    print_vec(temp);
    cout << "    Expected 4. Got " << get_min_spend(temp) << endl;
    }
    {
    vector<int> temp = {1, 100, 1, 7, 7};
    print_vec(temp);
    cout << "    Expected 14. Got " << get_min_spend(temp) << endl;
    }
    {
    vector<int> temp = {1, 3, 4, 2, 7};
    print_vec(temp);
    cout << "    Expected -1. Got " << get_min_spend(temp) << endl;
    }
    {
    vector<int> temp = {1};
    print_vec(temp);
    cout << "    Expected -1. Got " << get_min_spend(temp) << endl;
    }
    {
    vector<int> temp = {};
    print_vec(temp);
    cout << "    Expected -1. Got " << get_min_spend(temp) << endl;
    }
    return 0;
}

