class Solution {
public:
    // 動態規劃(因為現在的位置有會由左邊或者上面的格子走到)
    //  m and n will be at most 100.
    int uniquePaths(int m, int n) {
        vector<int> cnt(m,1);
        for(int t=1;t<n;t++)
            for(int i=1;i<m;i++)
                cnt[i]+=cnt[i-1];
        return cnt[m-1];
    }
};