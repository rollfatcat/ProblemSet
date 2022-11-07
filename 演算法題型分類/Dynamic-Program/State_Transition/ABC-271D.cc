/* 給定Ｎ張卡片，正面點數Ａ背面點數Ｂ，「能否」透過翻牌調整可以讓Ｎ張牌點數和為Ｓ？
 * 解題關鍵：動態規劃 + 回朔(BackTracking)
 * 狀態定義：dp[n][x] = 在第ｎ張時點數和為ｘ時卡片為正面(A)或反面(-B)，無法形成則保留為０
 * 狀態轉移：dp[n][x] = ( on[x-1][x-A]!=0 )? A : ( on[x-1][x-B]!=0 )? -B : 0
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e2;
const int MaxS=1e4;
const int MaxA=1e2;
 
int dp[MaxN][MaxS+1]={};
int main(){
	int N, S, A, B;
	
	cin>>N>>S>>A>>B;
	dp[0][A]=A;
	dp[0][B]=-B;
	for(int n=1; n<N; n++){
		cin>>A>>B;
		for(int s=0; s<S; s++){
			if( dp[n-1][s]==0 ) continue;
			if( s+A<=S and dp[n][s+A]==0 )
				dp[n][s+A]=A;
			if( s+B<=S and dp[n][s+B]==0 )
				dp[n][s+B]=-B;
		}
	}
	//
	if( dp[N-1][S]==0 ){ cout<<"No"; return 0; }
	vector<char> ans(N); 
	for(int s=S, n=N-1; 0<=n; n--){
		ans[n]= ( dp[n][s]<0? 'T' : 'H');
		s-=abs(dp[n][s]);
	}
	cout<<"Yes\n";
	for(char c:ans)
		cout<<c;
}