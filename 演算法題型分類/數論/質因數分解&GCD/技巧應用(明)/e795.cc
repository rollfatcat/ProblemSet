/* 給定Ｄ個數字，若該數字和他的"子數字"都得符合是質數。
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxD=10;
const int MaxN=29991231;
const int sN=sqrt(MaxN); // sN=5476
bool NotP[sN]={};
vector<int> prime={2};
int EasyCheck[7]={2,3,5,7,13,17,23};

inline bool CheckPrime(int x,int idx=0){
	if(x<sN) return NotP[x]==0;
	for( ; idx<prime.size() and prime[idx]*prime[idx]<=x and x%prime[idx];idx++);
	return idx==prime.size() or prime[idx]*prime[idx]>x;
}

int main(){
    // 建立範圍內的質數表
	for(int i=4;i<sN;i+=2)
		NotP[i]=1;
	for(int i=3;i<sN;i+=2)
		if(NotP[i]==0){
			prime.push_back(i);
			for(int j=3*i;j<sN;j+=(i<<1))
				NotP[j]=1;
		}
	// 根據輸入的數值判斷是否符合題目要求的規定
	for(int D,N;scanf("%d\n",&D)!=EOF;){
		while(D--){
			scanf("%d\n",&N);
			printf("%d ",N);
			
			bool IsP=binary_search(EasyCheck,EasyCheck+7,N%100);
			int B=1e3;
			for(;IsP and B<1e9;IsP=CheckPrime(N%B),B*=10);
			puts((IsP and B==1e9)?"is a Prime Day!":"isn't a Prime Day!");
		}
	}
}