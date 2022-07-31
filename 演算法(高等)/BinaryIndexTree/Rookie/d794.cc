/* 每次給定一個數字Ｍ加入數列中，加入時輸出該數字在數列是第Ｋ大？
 * 解題關鍵：每次輸入成績時，統計(1,M)前有幾個人，名次=全部人數減掉目前成績前的總人數
 * 		離散化：轉換為相對的名次 ... 因為輸入的數字範圍很大但是個數有限
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=20;
const int MaxN=1e5;
 
int N;
long org[MaxN];
long srt[MaxN];

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
		for(int n=0; n<N; n++){
			cin>>org[n];
			srt[n]=org[n];
		}
		sort(srt,srt+N);
		
		fill(BIT+1,BIT+1+N,0);
		for(int n=0; n<N; n++){
			int x=N-( lower_bound(srt,srt+N,org[n])-srt );
			// update
			BIT_Update(x,1);
			// query
			cout<< BIT_Quary(x) <<'\n';
		}
	}
}