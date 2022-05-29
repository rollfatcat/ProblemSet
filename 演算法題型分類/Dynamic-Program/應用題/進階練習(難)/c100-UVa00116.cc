/* 給定ＲxＣ的矩陣，由左而右找到一條路徑，輸出加總最小的值和路徑(字典序最小)
 * 題目盲點：Backtracking 時只考慮最小化前一格的號碼 ... 最小字典序不能只考慮前一格
 * 狀態紀錄：最小成本 和 路徑(抵達這一格的最小字典序)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxR=1e1;
const int MaxC=1e2;
int R, C;
int num[MaxR][MaxC];
int  dp[MaxR][MaxC];
vector<int> fr[MaxR][MaxC]; // from which row

int main(){
	
	while(cin>>R>>C){
		// input
		for(int r=0; r<R; r++)
			for(int c=0; c<C; c++)
				cin>>num[r][c];
		// init case : c=0
		for(int r=0; r<R; r++){
			dp[r][0]=num[r][0];
			fr[r][0]={r};
		}
		//
		for(int c=1; c<C; c++){
			for(int _, r=0; r<R; r++){
				// default
				dp[r][c]=dp[r][c-1];
				fr[r][c]=fr[r][c-1];
				// from previous row
				_=(r==0)? R-1: r-1;
				if(dp[r][c]>dp[_][c-1] or dp[r][c]==dp[_][c-1] and fr[r][c]>fr[_][c-1]){
					dp[r][c]=dp[_][c-1];
					fr[r][c]=fr[_][c-1];
				}
				// from following row
				_=(r==R-1)? 0: r+1;
				if(dp[r][c]>dp[_][c-1] or dp[r][c]==dp[_][c-1] and fr[r][c]>fr[_][c-1]){
					dp[r][c]=dp[_][c-1];
					fr[r][c]=fr[_][c-1];
				}
				// 
				dp[r][c]+=num[r][c];
				fr[r][c].push_back(r);
			}
		}
		// find the minimum
		int ans=0;
		for(int r=1; r<R; r++)
			if(dp[ans][C-1]> dp[r][C-1] or dp[ans][C-1]==dp[r][C-1] and fr[ans][C-1]>fr[r][C-1])
				ans=r;
		// output
		cout<<fr[ans][C-1][0]+1;
		for(int i=1; i<fr[ans][C-1].size(); i++)
			cout<<' '<<fr[ans][C-1][i]+1;
		cout<<'\n'<<dp[ans][C-1]<<'\n';
	}
}

 
 