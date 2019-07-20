/* Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction
 * (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 */
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int min_price=1<<30;
    int max_profit=0;
    for( int now_price: prices )
      (min_price>now_price)? min_price=now_price: max_profit=max(max_profit,now_price-min_price);
    return max_profit;
  }
};