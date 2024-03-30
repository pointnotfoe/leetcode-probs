/*

Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

/*
Runtime: 194 ms, faster than 57.40% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.3 MB, less than 89.63% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int days = prices.size();
        if (days <= 1)
            return max_profit;
        int min_buy = prices[0];
        for (int i = 1; i < days; i++)
        {
            max_profit = max(max_profit, prices[i] - min_buy);
            min_buy = min(min_buy, prices[i]);
        }
        return max_profit;
    }
};