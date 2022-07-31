/* 每次給定一個數字Ｍ加入數列中，加入時輸出該數字在數列的第Ｋ大？
 * 題目限制：題目保證成績介於 1 ≤ M ≤ N ，且每個人的成績都不重複
 * 解題關鍵：每次輸入成績時，統計(1,M)前有幾個人，名次=全部人數減掉目前成績前的總人數
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=20;
const int MaxN=1e5;
 
int N, x;
int BIT[MaxN+1];
int LowBit(int x){ return x&-x; }
void BIT_Update(int p,int v){
	for(; p<=N; p+=LowBit(p))
		BIT[p]+=v;
}
int BIT_Quary(int p,int ret=0){
	for(; 0<p; p-=LowBit(p))
		ret+=BIT[p];
	return ret;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	while( cin>>N ){
		fill(BIT+1,BIT+1+N,0);
		for(int n=1; n<=N; n++){
			cin>>x;
			x=N+1-x;
			// update
			BIT_Update(x,1);
			// query
			cout<< BIT_Quary(x) <<'\n';
		}
	}
}