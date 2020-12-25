/* 給定２個長度Ｌ的中文字串，輸出最長的共同子序列長度？
 * 解題關鍵：UTF-8＋LongestCommonString
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxL=100;
char ss[2][MaxL][4];
int LCS[MaxL+1][MaxL+1]={};
 
inline bool IsSame(int a,int b){ 
	return ss[0][a][0]==ss[1][b][0] and ss[0][a][1]==ss[1][b][1] and ss[0][a][2]==ss[1][b][2];
}
int main(){
	for(int L;scanf("%d\n",&L) and L>0; ){
		for(int i=0;i<L;i++)
			scanf("%s",ss[0][i]);
		for(int i=0;i<L;i++)
			scanf("%s",ss[1][i]);
        /* 動態規劃：LCS */
		for(int i=0;i<L;i++)
			for(int j=0;j<L;j++)
				LCS[i+1][j+1]=IsSame(i,j)? LCS[i][j]+1: max(LCS[i+1][j],LCS[i][j+1]);
		printf("%d\n",LCS[L][L]);
	}
}