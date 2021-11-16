/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/combination-sum/
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]
*/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        candidates.erase( remove (candidates.begin(), candidates.end(), 0), candidates.end() );
        vector<vector<int>> comb_sets;
        if (candidates.size() <= 0)
        {
            return comb_sets;
        }

        std::sort (candidates.begin(), candidates.end());
        //map<vector<int>,int> set_map;

        int size2_count = 0;//With the following approach there should only be one size two combi.
        for (int base_index = 0; base_index < candidates.size(); base_index++)
        {
            int base_count = 0;
            int sum = 0;
            vector<int> set;
            while(1)//first gather maximum possible sum from this index
            {
                if ((sum + candidates[base_index]) <= target)
                {
                    sum += candidates[base_index];
                    set.push_back(candidates[base_index]);
                    base_count++;
                    if (sum == target)
                    {
                        comb_sets.push_back(set);//one set is complete
                        set.pop_back();//then remove the last element
                        sum -= candidates[base_index];
                        base_count--;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            int base_sum = sum;
            while (base_count > 0)
            {
                vector<int> set_fill = set;
                for (int next = 0; next < candidates.size(); next++)
                {
                    if(next == base_index)
                    {
                        continue;
                    }

                    if ((sum + candidates[next]) <= target)
                    {
                        sum += candidates[next];
                        set_fill.push_back(candidates[next]);
                        //base_count++;
                        if (sum == target)
                        {
                            std::sort (set_fill.begin(), set_fill.end());
                            if (set_fill.size() == 2)
                            {
                                size2_count++;
                            }
                            if (size2_count < 2 || set_fill.size() != 2)
                            {
                                comb_sets.push_back(set_fill);//one set is complete
                                //set_map[set_fill]++;
                            }

                            set_fill.pop_back();//remove the last element
                            sum -= candidates[next];
                        }
                        else if(((next + 1) < candidates.size()) &&
                                ((sum + candidates[next+1]) > target))
                        {
                            sum -= candidates[next];
                            set_fill.pop_back();
                        }
                    }
                    //if this element is
                   /* else if (set_fill.size() > set_fill.size())
                    {
                        set_fill.pop_back();
                        next--;
                        //break; //since all other will be greater.
                    }
                    else
                    {
                       break;
                    }*/
                }
                base_count--;
                if (set.size() > 0)
                {
                    base_sum = base_sum - set.front();
                    sum = base_sum;
                    //set.erase(set.begin());
                    set.pop_back();

                }
                else
                {
                    break;
                }

            }
        }
/*        for (std::map<vector<int>,int>::iterator it=set_map.begin(); it!=set_map.end(); ++it)
        {
            for(int i = 0; i < it->second; i++)
            {
                comb_sets.push_back(it->first);
            }
        }*/

        return comb_sets;
    }
};


int main()
{
    Solution comb_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    int target = 5;
    vector<vector<int>> comb_sets = comb_sum.combinationSum(test_data, target);

    cout << "For array :" << endl;
    for (auto i : test_data)
    {
        cout << i << " ";
    }

    cout <<endl<< "Possible combinations that can sum up to " << target << " are " << comb_sets.size() << endl;
    for (const auto& v : comb_sets)
	{
			for (auto i : v)
			{
					cout << i ;
			}
			cout << endl;
	}

    return 0;

}