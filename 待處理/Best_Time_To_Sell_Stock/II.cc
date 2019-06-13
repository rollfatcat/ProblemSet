/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like
 * (i.e., buy one and sell one share of the stock multiple times).
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 */
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sum_profit=0;
    for(int i=1;i<prices.size();i++)
      if(prices[i]-prices[i-1]>0)
        sum_profit+=prices[i]-prices[i-1];
    return sum_profit;
  }
};