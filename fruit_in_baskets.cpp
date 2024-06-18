/*https://leetcode.com/problems/fruit-into-baskets/description/
904. Fruit Into Baskets
Solved
Medium
Topics
Companies
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/
/*
Runtime
71
ms
Beats
97.34%
of users with C++
Memory
68.42
MB
Beats
98.05%
of users with C++
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fruit_num = fruits.size();
        int max_fruit = fruit_num;
        if (fruit_num < 3)
        {
            return max_fruit;
        }
        max_fruit = 2;
        int selected[2] = {fruits[0],-1};
        int count[2] = {1,0};
        if (fruits[1] != selected[0])
        {
            selected[1] = fruits[1];
            count[1] = 1;
        }
        else
        {
            count[0]++;
        }

        int left = 0;
        for (int right = 2; right < fruit_num; ++right)
        {
            if (fruits[right] == selected[0] || -1 == selected[0])
            {
                count[0]++;
                selected[0] = fruits[right];
            }
            else if (fruits[right] == selected[1] || -1 == selected[1])
            {
                count[1]++;
                selected[1] = fruits[right];
            }
            else
            {
                max_fruit = max(max_fruit, count[0] + count[1]);
                while (left < right)
                {
                    if (fruits[left] == selected[0])
                    {
                        count[0]--;
                    }
                    else if (fruits[left] == selected[1])
                    {
                        count[1]--;
                    }
                    left++;
                    if (count[0] == 0 || count[1] == 0)
                    {
                        if (count[0] == 0)
                        {
                            count[0] = 1;
                            selected[0] = fruits[right];
                        }
                        else// (count[0] == 0)
                        {
                            count[1] = 1;
                            selected[1] = fruits[right];
                        }
                        break;
                    }
                }
            }
        }
        max_fruit = max(max_fruit, count[0] + count[1]);
        return max_fruit;
    }
};

/*https://leetcode.com/problems/fruit-into-baskets/solutions/170740/java-c-python-sliding-window-for-k-elements/
[Java/C++/Python] Sliding Window for K Elements

lee215
206618
72168
Sep 15, 2018
Problem
"Start from any index, we can collect at most two types of fruits. What is the maximum amount"


Translation
Find out the longest length of subarrays with at most 2 different numbers?


Explanation
Solve with sliding window,
and maintain a hashmap counter,
which count the number of element between the two pointers.
Find more infinite similar prolems in the end.


Complexity
Time O(n)
Space O(1)


https://leetcode.com/problems/fruit-into-baskets/solutions/170740/JavaC++Python-Sliding-Window-for-K-Elements/comments/273402/
xingHong
May 09, 2019
[i,j] is the sliding window, and it's the current longest window.
Suppose we found current longest window [i, j], then this length will be kept, because,
as j++, if the sliding window contains more than 2, then also we will do i++, so that is to say, the current longest length will be kept the same,
in another word, when [i,j] reached a maximum, it will not become smaller
on the other side, when j++, if the current window contains less than two, then i will not increase(because the if statement), in this way, the longest length of sliding window will get updated
*/
    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            count[tree[j]]++;
            if (count.size() > 2) {
                if (--count[tree[i]] == 0)count.erase(tree[i]);
                i++;
            }
        }
        return j - i;
    }