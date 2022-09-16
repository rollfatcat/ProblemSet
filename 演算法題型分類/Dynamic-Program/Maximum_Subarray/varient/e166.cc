/* 『環狀』的連續區間和最大化(至少要選擇一個數字)
 * 初始想法：更新最大區間時紀錄起終點，盡量選擇起點號碼越後面的(X)
 * 暴力法：數量不多(1e3)，利用前綴和枚舉所有的起終點並計算端點內連續和和端點外的
 * 正解：
 * 動態規劃，順向處理時一並紀錄[1,N]在位置Ｎ時和『左端點連接』的連續區間最大和
 * 之後逆向枚舉和『右端點連接』的連續區間最大和＋『左端點連接』的連續區間最大和
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxP=1e4;
int num[MaxN+1];
int prS[MaxN+1];
int mnv[MaxN+1];
int main(){
	int N;
	while( cin>>N and N>0 ){
		// input
		for(int n=1; n<=N; n++)
			cin>>num[n];
		// maximum subarray
		int ans=num[1];
		int minv=0;
		for(int n=1; n<=N; n++){
			prS[n]=prS[n-1]+num[n];
			ans=max(ans,prS[n]-minv);
			minv=min(minv,prS[n]);
		}
		// circular = left + right
		mnv[N]=prS[N];
		for(int n=N-1; 0<=n; n--)
			mnv[n]=min(mnv[n+1],prS[n]);
		for(int n=1; n<=N; n++)
			ans=max(ans,prS[n]+prS[N]-mnv[n]);
		cout<<ans<<'\n';
	}
}