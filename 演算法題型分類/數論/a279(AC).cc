/* 難題(無法依照表面敘述的規則完成要求)
 * f(x)=4x+3=4(x+1)-1
 * g(x)=8x+7=8(x+1)-1
 * 迭代後可以發現規律：次方項的指數成長 和 交換律
 * 	 f(f(x))=4(4(x+1))-1=16(x+1)-1 => Ｎ次f(x)＝4^N*(x+1)-1
 *   g(g(x))=8(8(x+1))-1=64(x+1)-1 => Ｎ次g(x)＝8^N*(x+1)-1
 *   f(g(x))=4(8(x+1))-1=8(4(x+1))-1=g(f(x))
 *   
 * 在最少次數Ｃ時發生Ａ次f(x)＋Ｂ次g(x)的轉換
 * 	2^(2Ａ+3Ｂ)*(Ｎ+1) ≡ 1(mod Ｍ) 且 Ａ+Ｂ=Ｃ≦Ｅ
 * 2^(2Ａ+3Ｂ)為(Ｎ+1)在模Ｍ時乘法反元素(檢驗是否存在)
 * 假設2Ａ+3Ｂ=Ｐ，已知Ｐ時求最小化Ｃ則Ｃ=(P+2)//3，再枚舉Ｐ
 */

#include<bits/stdc++.h>
using namespace std;

const int MaxN=20111021;
const int MaxE=314159;

inline int MulInv(int N,int M){
	if(__gcd(N,M)!=1) return -1;
	int pre=0, now=1, P;
	int num[2]={M,N%M};
	int mat[2][2]={{1,0},{0,1}};
	for(; num[pre]%num[now]>0 ;swap(pre,now))
		P=num[pre]/num[now],
		 num[pre]%=num[now],
		mat[pre][0]-=P*mat[now][0],
		mat[pre][1]-=P*mat[now][1];
	return (mat[now][1]>0)? mat[now][1]: mat[now][1]+M;
}
int main(){
	
	int N, M, E, P, C, TwoBase;
	while(scanf("%d %d %d\n",&N,&M,&E)!=EOF){
		// Ｅ=0時的 Case
        if(N==0 or M==1 or N%M==0){ puts("0"); continue; }
		// 存在乘法反元素(才能)
		N=MulInv(N+1,M);
		if(N==-1){ puts("-1"); continue; }
		// 2^(2Ａ+3Ｂ) ≡ (Ｎ+1)^-1 (mod Ｍ)
		P=2, C=1, TwoBase=4;
		for( ; C<=E and TwoBase!=N; P++,C+=(P%3==1)){
			TwoBase=(TwoBase<<1);
			if(TwoBase>=M)
				TwoBase-=M;
		}
		printf("%d\n",(TwoBase==N)? C:-1 );
	}
	
}
