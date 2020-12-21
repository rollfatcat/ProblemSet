/* 大數＋動態規劃
 * 狀態轉換：Num[i]=2*Num[i-1]+Num[i-2]+Num[i-3]
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int base=10;
vector<int> Num[MaxN+1];

inline void ADD(vector<int> &A,vector<int> &B,int carry=0){
	for(int i=0;i<B.size();i++){
		A[i]=A[i]+B[i]+carry;
		carry=A[i]/base;
		A[i]%=base;
	}
	for(int i=B.size();carry>0 and i<A.size();i++){
		A[i]+=carry;
		carry=A[i]/base;
		A[i]%=base;
	}
	if(carry>0)
		A.push_back(carry);
}
int main(){
	// 建表, 狀態轉換：Num[i]=2*Num[i-1]+Num[i-2]+Num[i-3]
	Num[0]={0};
	Num[1]={2};
	Num[2]={5};
	Num[3]={3,1};
	for(int i=4;i<=MaxN;i++){
		// Num[i]=2*Num[i-1];
		Num[i]=Num[i-1];
		ADD(Num[i],Num[i-1]);
		ADD(Num[i],Num[i-2]);
		ADD(Num[i],Num[i-3]);
	}
	//
	for(int N;scanf("%d",&N)!=EOF;){
		for(int i=Num[N].size()-1;i>=0;i--)
			putchar(Num[N][i]+'0');
		putchar('\n');
	}
}