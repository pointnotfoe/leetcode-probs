#include "ideal_days.h"

using namespace std;
int main()
{
    vector<int> result;
    result = ideal_days({3,2,2,2,3,4}, 2);
    // cout << "From ideal_day():" ;
    // for (size_t i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    cout << "From ideal_days_linear():" ;
    result = ideal_days_linear({3,2,2,2,3,4}, 2);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    
    cout << "From ideal_days_linear():" ;
    result = ideal_days_linear({1,2,2,2,3,4}, 2);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    cout << "From ideal_days_linear():" ;
    result = ideal_days_linear({1,1,2,2,3,0,4}, 2);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}