/* 給定Ｎ個字串(長度最多５的小寫字母組成)，接下來會有２種查詢
 * (1) 給定編號，輸出該編號的字串在排序後屬於第Ｋ大的字典序
 * (2) 給定編號，輸出該編號字串的左側有多少個小於他字典序的個數
 * 解題關鍵：(1)離線處理 (2)在線處理(需要支援單點查詢和單點更新)
 * (1)離線處理：排序後字典序由大到小計算Ｋ的值
 * (2)在線處理：將字串轉換為相對的字典序編號，由左而右用樹狀數組維護個數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;

string ss[MaxN+1];
string tag;
int ord[MaxN+1];
int ans[MaxN+1]={};
int BIT[MaxN+1]={};
int N, Q1, Q2, v;
int search(int L,int R){
	if(L+1==R) return L;
	int M=L+R>>1;
	return ( ss[ord[M]]>tag )? search(L,M): search(M,R);
}
int SUM(int v,int ret=0){
	for( ; 0<v; v-= v&-v)
		ret+=BIT[v];
	return ret;
}
void UDP(int v){
	for(int k; v<=N; v+= v&-v)
		BIT[v]+=1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N;
	for(int n=1; n<=N; n++){
		cin>>ss[n];
		ord[n]=n;
	}
	sort(ord+1,ord+1+N,[](int lhs,int rhs){
		return ss[lhs]<ss[rhs]; });
	ans[ ord[N] ]=1;
	for(int n=N-1; 0<n; n--)
		ans[ ord[n] ]=( ss[ord[n]]==ss[ord[n+1]] )? ans[ ord[n+1] ]: N-n+1;
	cin>>Q1>>Q2;
	while( Q1-->0 ){
		cin>>v; cout<<ans[v]<<' ';
	}
	cout<<'\n';
	
	for(int n=1; n<=N; n++){
		tag=ss[n];
		v=search(1,N+1);
		ans[n]=SUM(v-1);
		UDP(v);	
	}
	while( Q2-->0 ){
		cin>>v; cout<<ans[v]<<' ';
	}
	cout<<'\n';
}