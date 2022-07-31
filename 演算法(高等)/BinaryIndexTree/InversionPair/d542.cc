/* 給定Ｎ個數字，輸出逆數對的數量
 * 解題關鍵：BIT
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
int N;
int org[MaxN];
int srt[MaxN];

int BIT[MaxN+1];
int LowBit(int x){ return x&-x; }
void BIT_Update(int p,int v){
	for(; p<=N; p+=LowBit(p))
		BIT[p]+=v;
}
int BIT_Query(int p,int ret=0){
	for(; 0<p; p-=LowBit(p))
		ret+=BIT[p];
	return ret;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	while( cin>>N and N>0 ){
		for(int n=0; n<N; n++){
			cin>>org[n];
			srt[n]=org[n];
		}
		sort(srt,srt+N);
		fill(BIT+1,BIT+1+N,0);
		long ans=0;
		for(int n=N-1; 0<=n; n--){
			int x=lower_bound(srt,srt+N,org[n])-srt+1;
			// update
			BIT_Update(x,1);
			// query
			ans+=BIT_Query(x-1);
		}
		cout<<ans<<'\n';
	}
}