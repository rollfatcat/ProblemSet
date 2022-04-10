/* 給定Ｎ個數字，輸出兩個最「接近」查詢數字的和
 * 解題關鍵：枚舉每個數字，搜尋另一個補數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxQ=25;

int num[MaxN];
int main(){
	int N, Q, s, p, v; 
	
	for(int caseI=1; cin>>N and N>0; caseI++){
		for(int n=0; n<N; n++)
			cin>>num[n];
		sort(num,num+N);
		cin>>Q;
		cout<<"Case "<<caseI<<":\n";
		while(Q-->0){
			cin>>s;
			int ans=num[0]+num[1];
			for(int n=2; n<N; n++){
				p=lower_bound(num,num+n,s-num[n])-num;
				// 往前一格：搜尋到第ｎ格或是存在前一個數字且差值較小
				p-=(p==n or 0<p and s-num[n]-num[p-1]<num[n]+num[p]-s);
				if( abs(num[n]+num[p]-s)<abs(ans-s) ) 
					ans=num[n]+num[p];
			}
			cout<<"Closest sum to "<<s<<" is "<<ans<<".\n";
		}
	}
}