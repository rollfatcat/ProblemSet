/* 給定Ｎ個Row，每個Row包含Ｔ個訊號值，各自對Ｔ個訊號值做AND/OR/XOR後輸出
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=10;
const int MaxT=10;

inline int ReadBit(int T,int ths_v=0){
	for(int bit_v,j=0;j<T;j++)
		scanf("%d",&bit_v),
		ths_v|=bit_v<<j;
	return ths_v;
}
inline void PrintBit(int T,int ths_v){
	for(int i=0;i<T;i++,ths_v>>=1)
		printf(" %d",ths_v&1);
	putchar('\n');
}
int main(){
	int N, T;
	int addv, orv, xorv, ths_v;
	while(scanf("%d %d\n",&N,&T)!=EOF){
		addv=orv=xorv=ReadBit(T);
		for(int i=1;i<N;i++){
			ths_v=ReadBit(T);
			addv&=ths_v;
			orv|=ths_v;
			xorv^=ths_v;
		}
		printf("AND:"), PrintBit(T,addv);
		printf(" OR:"),  PrintBit(T,orv);
		printf("XOR:"), PrintBit(T,xorv);
	}
}