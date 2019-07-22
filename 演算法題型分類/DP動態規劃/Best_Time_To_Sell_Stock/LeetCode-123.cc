/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // 極端例子：只存在一天的股票價格時獲利值＝0
    if(prices.size()<=1) return 0;

    // 動態規劃
    vector<int> max_left_profit;
    max_left_profit.push_back(0);
    int min_price=prices[0];
    for(int i=1;i<prices.size();i++)
      if(prices[i]>min_price)
        max_left_profit.push_back(max(max_left_profit.back(),prices[i]-min_price));
      else
        max_left_profit.push_back( max_left_profit.back() ),
        min_price=prices[i];
    int max_right_profit=0;
    int max_sum_profit=max_left_profit.back();
    int max_price=prices.back();
    for(int i=prices.size()-2;i>0;i--)
      if(max_price>prices[i])
        max_right_profit=max(max_right_profit,max_price-prices[i]),
        max_sum_profit=max(max_sum_profit,max_right_profit+max_left_profit[i-1]);
      else
        max_price=prices[i];
    return max_sum_profit;
  }
};
