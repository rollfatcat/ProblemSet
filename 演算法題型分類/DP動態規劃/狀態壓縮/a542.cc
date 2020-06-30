/* 計算Ｎ階矩陣的行列式(N＜11)，並將答案模 1e8+7
 * 核心解法：階層降轉＋位元運算
 * 因為降階計算(依序刪去第０/1/2...個Row)的關係，過程中會重複計算子矩陣的數值。
 * 重複計算＝可以利用陣列儲存算過的狀態。
 * 觀察第Ｎ階時的行列式＝Ｎ個Ｎ-1階的子矩陣行列式的總和(正負號交替)＝狀態為只差一個位元不同的所有狀態
 * 目前用到的Column可以用二進位的代表：比如算３階時答案一定在狀態７(代表每個Column都有用到)。
 * 狀態７＝mat[0][0]x狀態６-mat[0][1]x狀態５＋mat[0][2]x狀態３
 * 狀態６/狀態５/狀態３必定由第１/２個Row組成
 * 狀態６＝mat[1][1]x狀態４-mat[1][2]x狀態２
 * 狀態５＝mat[1][0]x狀態４-mat[1][2]x狀態１
 * 狀態３＝mat[1][0]x狀態２-mat[1][1]x狀態１
 * 而觀察可以知道目前的狀態和構成需要的子狀態間必定只差一個位元(一定比目前的狀態數值還小)
 * ，所以只要讓狀態由小到大更新即可 且 初始化時狀態＝０的行列式值＝１
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=10;
const int M=1e8+7;
int mat[MaxN][MaxN];
long dp[1<<MaxN]={1};

int main(){
	int N, L, sign;
	while(scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				scanf("%d",&mat[i][j]);
		for(int now=1; now<(1<<N); now++){
            // 現在的狀態中有幾個１的位元數
			L=__builtin_popcount(now); 
            // sign代表正負號取交替, 每次都找出『只差一個位元不同』的狀態
			sign=1, dp[now]=0;
			for(int LastBit,thS=now; thS>0; thS^=LastBit,sign=-sign)
				LastBit=thS&-thS,
				dp[now]+=sign*mat[N-L][__lg(LastBit)]*dp[now^LastBit];
			dp[now]=dp[now]%M+(dp[now]<0)? M:0;
		}
		printf("%ld\n",dp[(1<<N)-1]);
	}
}