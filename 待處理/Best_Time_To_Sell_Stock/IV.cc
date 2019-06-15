class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        int n=prices.size();
        // 當「可獲利的區段」和最大的交易次數取最少值
        int positive=0;
        int sumv=0;
        for(int i=1;i<n;i++)
            if(prices[i]-prices[i-1]>0)
                sumv+=prices[i]-prices[i-1],
                positive++;
        if(positive<k) return sumv;
        // 滾動陣列模擬狀態轉移
        int l[k+1][2]={0};
        int g[k+1][2]={0};
        for(int i=1;i<n;i++){
            int diff=prices[i]-prices[i-1];
            int now=i&1, pre=now^1;
            for(int j=1;j<=k;j++)
                l[j][now]=max(g[j-1][pre]+max(diff,0),l[j][pre]+diff),
                g[j][now]=max(g[j][pre],l[j][now]);
        }
        return g[k][(n&1)^1];
    }
};