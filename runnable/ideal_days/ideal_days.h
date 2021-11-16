
#include <bits/stdc++.h>

/*
//https://leetcode.com/discuss/interview-question/1482144/amazon-online-assessment-september-2021/1095536
Given an array of predicted rainfall for next n days, where index i presents a day and day[i] represents the amount of rainfall on that day, return a list of ideal days such that -

day[i-k] >= day[i-k+1] >= ... day[i-1] >= day[i] <= day[i+1] ... <= day[i+k-1] <= day[i+k],

where k is given as an input which represents the number of days prior and after the current day.

As index represents day, while returning, we need to return i+1 as the actual day.

Ex:
day = [3,2,2,2,3,4]
k = 2
Output:
[3,4]

Explanation:

the rainfall trend for day3 (i = 2) is day1 >= day2 >= day3 <= day4 <= day5 so day3 is ideal
the rainfall trend for day4 (i = 3) is day2 >= day3 >= day4 <= day5 <= day6 so day4 is ideal

i <= k <= n <= 2x10^5
0 <= day[i] <= 10^9

Testcase1
day = [1,0,1,0,1]
k = 1
Output:
[2,4]

Testcase2
day = [1,0,0,0,1]
k = 2
Output:
[3]

Testcase3
day = [1,1,1,1,1,1,1,1,1,1]
k = 3
Output:
[4,5,6,7]
*/
//runs in n^2
std::vector<int> ideal_days(std::vector<int> rainfall, int k)
{
    // std::cout << "From ideal_day() Input:" ;
    // for (size_t i = 0; i < rainfall.size(); i++)
    // {
    //     std::cout << rainfall[i] << " ";
    // }

    std::vector<int> ideal;
    for (int i = k; i < rainfall.size(); i++)
    {
        bool ideal_day = true;
        for (int j = i - k; j <= i + k; j++)
        {
            if (rainfall[j] < rainfall[i])
            {
                ideal_day = false;
                break;
            }
        }
        if (ideal_day)
        {
            ideal.push_back(i+1);
        }
    }

    // std::cout << "Output:" ;
    // for (size_t i = 0; i < ideal.size(); i++)
    // {
    //     std::cout << ideal[i] << " ";
    // }
    // std::cout << std::endl;
    return ideal;
}

//https://leetcode.com/discuss/interview-question/1482144/Amazon-Online-Assessment-September-2021/1094141

std::vector<int> ideal_days_linear(std::vector<int> rainfall, int k)
{
    int n = rainfall.size();
    std::vector<int> left(n,0),right(n,0);
    
    std::vector<int> &a = rainfall;
    for(int i=1;i<n;i++){
        if(a[i]<=a[i-1]){
            left[i]=left[i-1];
        }else{
            left[i]=i;
        }
    }
    
    std::cout << "Left:" ;
    for (size_t i = 0; i < left.size(); i++)
    {
        std::cout << left[i] << " ";
    }
    std::cout << std::endl;

    right[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<=a[i+1]){
            right[i]=right[i+1];
        }else{
            right[i]=i;
        }
    }
    
    std::cout << "Right:" ;
    for (size_t i = 0; i < right.size(); i++)
    {
        std::cout << right[i] << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> v;
    for(int i=k;i<n-k;i++){
        if(i-left[i]>=k&&right[i]-i>=k) v.push_back(i+1);
    }
    return v;
}