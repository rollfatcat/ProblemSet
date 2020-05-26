/* 給定Ｂ個站點和Ｐ位乘客上下車的站點，求哪一個人數最多和最少的站點？
 * 若有多個人數多的站點時則輸出號碼較大者，人數最少的站點則輸出號碼較小者。
 * Ｂ≤ 1e3 且 Ｐ≤ 1e3，暴力法更新區段內每個點的數列即可。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxB=1e3;
const int MaxP=1e3;
int cnt[MaxB+1]={};

int main(){
	int B, P;
	scanf("%d %d\n",&B,&P);
	
	for(int L, R;P--;){
		scanf("%d %d\n",&L,&R);
		if(L>R) swap(L,R);
		for(int i=L;i<=R;i++)
			cnt[i]++;
	}
	int Nmin=1, Nmax=1;
	for(int i=1;i<=B;i++){
		if(cnt[i]<cnt[Nmin]) Nmin=i;
		if(cnt[i]>=cnt[Nmax]) Nmax=i;
	}
	printf("%d %d\n",Nmin,Nmax);
}