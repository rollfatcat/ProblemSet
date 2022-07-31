/* 給定Ｎ對數字(１到Ｎ而且每一對都是２個)，輸出每組數字範圍內小於該數字的個數？
 * 解題關鍵：BIT - 逆數對
 * 每組數字範圍小於該數字的個數 = ２個數字的逆數對差值
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;

int N, v, p;
int num[MaxN<<1|1];
int cnt[MaxN+1];
int BIT[MaxN+1]={};
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
	long ans=0;
	cin>>N;
	for(int n=1; n<=(N<<1); n++)
		cin>>num[n];
	fill(cnt+1,cnt+1+N,-1);
	for(int n=N<<1; 1<=n; n--){
		p=num[n];
		BIT_Update(p,1);
		v=BIT_Query(p-1);
		(cnt[p]==-1)? cnt[p]=v: ans+=v-cnt[p];
	}	
	cout<<ans;
}