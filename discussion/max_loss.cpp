/*
https://leetcode.com/discuss/interview-question/4947258/How-to-solve-this-one-oror-Amazon-OA
2. Code Question 2
You are analyzing the market trends of Amazon stocks. A financial service model returned an array of integers, PnL (Profit and Loss), 
for your portfolio representing that in the ith month, you will either gain or lose PnL[i]. All reported PnL values are positive, representing gains.
As part of the analysis, you will perform the following operation on the PnL array any number of times:
• Choose any month i (0 ≤ i<n) and multiply PnL[i] by -1
Find the maximum number of months you can afford to face a loss, i.e. have a negative PnL, 
such that the cumulative PnL for each of the n months remains strictly positive i.e. remains greater than 0.
Note: The cumulative PnL for the ith month is defined as the sum of PnL from the starting month up to the ith month. 
For example, the cumulative PnL for the PnL = [3,-2, 5, -6, 1] is [3, 1, 6, 0, 1).
Example
Consider, n = 4, and PnL = [5, 3, 1, 2]
Some of the possible arrays after performing the given operation some number of times:
Modified PnL    | Cumulative PnL | Number of negatives | Is Valid | Comments
[5, -3, -1, 2]  | [5, 2, 1, 3]   |         2           |    Yes   | The operation was performed on the second and third months (in bold). All the cumulative PnL are positive
[5, -3, -1, -2] | [5, 2, 1, -1]  |         3           |    No    | The last cumulative PnL is negative, hence this is not valid
[5, -3, 1, -2]  | [5, 2, 3, 1]   |         2           |    Yes   | All the cumulative PnL are positive
[-5, 3, 1, 2]   | [-5, -2, -1, 1]|         1           |    No    | The cumulative PnL for the first three months are negative

There are many more ways to perform the operations but the maximum number of negative PnLs there can be, maintaining a positive cumulative PnL is 2. Report 2 as the answer.

Function Description
Complete the function getMaxNegativePnL in the editor below.
getMaxNegativePnL has the following parameter:
int PnL[n]: an array of integers
Constraints
1 ≤ n ≤105
1 ≤ PnL[i]≤ 109
▼Input Format For Custom Testing
The first line contains an integer, n, the number of elements in PnL.
Each line / of the n subsequent lines (where Osi<n) contains an integer, PnL[i].
▼Sample Case 0
Sample Input For Custom Testing
STDIN   FUNCTION
5    → PnL[] size n = 4 
1    → PnL= [1, 1, 1, 1, 1]
1
1
1
1

Sample Output
2
Explanation
There are multiple possible PnLs such as [1, -1, -1, 1, 1], [-1, 1, -1, 1, -1], etc.
*/



#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

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

/*
 * Complete the 'getMaxNegativePnL' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY PnL as parameter.
 */
int getMaxNegativePnL(vector<int> PnL) {

}
int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    // ostream &fout = std::cout;
    // cout << "output path: " << getenv("OUTPUT_PATH") << endl;
    //output to stdout
    // ofstream fout(stdout);
    cout << "Input num of elements to be processed: ";
    string PnL_count_temp;
    getline(cin, PnL_count_temp);
    int PnL_count = stoi(ltrim(rtrim(PnL_count_temp)));
    cout << "Input " << PnL_count << " PnL: \n";
    vector<int> PnL(PnL_count);
    for (int i = 0; i < PnL_count; i++) {
        string PnL_item_temp;
        getline(cin, PnL_item_temp);
        int PnL_item = stoi(ltrim(rtrim(PnL_item_temp)));
        PnL[i] = PnL_item;
    }
    int result = getMaxNegativePnL(PnL);
    // fout << result << "\n";
    cout << result << "\n";
    // fout.close();
    return 0;
}
string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}
string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
