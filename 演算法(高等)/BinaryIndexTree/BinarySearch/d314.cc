/* 給定Ｑ次操作，輸出對應的答案
 * 操作(1) - Given X : 將數字Ｘ加入數列中
 * 操作(2) - Find K ：輸出數列中第Ｋ大(保證Ｋ≤ 數列的個數 )的數字
 * 解題關鍵：二分法猜測數列中第Ｋ大的數字，檢測小於猜測值的個數低於Ｋ
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1e7;
int num[MaxN+1]={};
int BIT[MaxN+1]={};
 
int lowbit(int x){ return x&-x;}
 
void Update(int p,int x){
	num[p]+=x;
	for(; p<=MaxN; p+=lowbit(p))
		BIT[p]+=x;
}
int Query(int x,int ret=0){
	for(; 0<x; x-=lowbit(x))
		ret+=BIT[x];
	return ret;
}
int main() {
	string ss;
	int N;
	int cnt=0;
	while(cin>>ss and ss!="END"){
		cin>>N;
		if(ss=="GIVE"){
			Update(N,1);
			cnt++;
		}else{
			N=cnt+1-N;
			int L=1;
			int R=MaxN+1;
			while( L+1<R ){
				int M=L+R>>1;
				( Query(M-1)<N )? L=M: R=M;
			}
			cout<<L<<'\n';
		}
	}
}