class Solution {
public:
    // m and n will be at most 100.
    // 有障礙物的版本
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> cnt(obstacleGrid[0].size(),0);
        cnt[0]=1;
        for(int i=0;i<obstacleGrid.size();i++){
            cnt[0]=(cnt[0])? 1-obstacleGrid[i][0]: 0;
            for(int j=1;j<obstacleGrid[i].size();j++)
                cnt[j]=(obstacleGrid[i][j])? 0: cnt[j]+cnt[j-1];
        }
        return cnt.back();
    }
};