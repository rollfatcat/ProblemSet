/* 給定Ｄ(間隔寬)和Ｎ個切點位置(輸入時會按照由小到大)，
 * 只能在切點位置做分割，必須保證每段的長度不超過規定的間隔寬，輸出最少分割的段數？
 * 解題核心：爬行法，類似線段覆蓋問題。
 * 目前切點的超過容許範圍時，需要"多一段"且更新容許的範圍(前一個位置＋Ｄ)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxT=3e3;
const int MaxN=1e4;
const int MaxP=1e8;

int pos[MaxN]; // sorted
int main(){
	int T, N, P;
	
	while(cin>>T>>N){
		for(int n=0; n<N; n+=1)
			cin>>pos[n];
		int ans=0;
		int pre=0;
		for(int n=0; n<N; ){
			if(pos[n]-pre<=T){
				n+=1;
			}else{
				pre=pos[n-1];
				ans+=1;
			}
		}
		cout<<ans+1<<'\n';
	}
}