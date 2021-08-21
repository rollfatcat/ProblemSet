/* 給定Ｎ個(二維平面)點，玩家只能選擇向右或向上移動，經過指定格子時可以拾取該果實，輸出可以拾取到得最多數量？
 * 問題轉換 : dp[Yi]=max{ dp[Yj] }+1, Yj ≤ Yi
 * 解題關鍵：Sort＋LIS(Robinson-Schensted-Knuth Algorithm)時間需要壓縮到 N㏒N
 * 排序 : 點座標根據Ｘ值更新
 * LIS : Greedy(貪婪)加入(Ｙ座標)遞增數列中，考量存在不同Ｘ座標但同個Ｙ座標的情況可以涵蓋採用 upper_bound
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
const int MaxP=1e7;
 
int main(){
	int N;
 
	scanf("%d",&N);
	vector<vector<int>> node(N,vector<int>(2));
	for(int i=0;i<N;i+=1)
		scanf("%d %d",&node[i][0],&node[i][1]);
	sort(node.begin(),node.end());
	vector<int> LIS={ node[0][1] };
	for(int i=1;i<N;i+=1){
		int p=upper_bound(LIS.begin(),LIS.end(),node[i][1])-LIS.begin();
		if(p==LIS.size())
			LIS.push_back(node[i][1]);
		else
			LIS[p]=node[i][1];
	}
	printf("%lu\n",LIS.size());
}