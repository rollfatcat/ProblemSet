// 找出最大『嚴格遞增的』矩形面積 O(n^4)
// 枚舉方式的做法類似 b123 的最大矩形，只是需要再處理『直行』的遞增要求
#include<bits/stdc++.h>
using namespace std;

const short MAXN=100;
int org[MAXN][MAXN];
int contR[MAXN][MAXN];
int contC[MAXN][MAXN];

int main(){
  int R, C;
  scanf("%d %d",&R,&C);
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      scanf("%d",&org[i][j]);
  //DP ----------------
	for(int i=0;i<C;i++){
		contR[0][i]=1 ;
		for(int j=1;j<R;j++)
			contR[j][i]=(org[j][i]>org[j-1][i])?(contR[j-1][i]+1):1;
	}
	for(int i=0;i<R;i++){
		contC[i][0]=0;
		for(int j=1;j<C;j++)
		  contC[i][j]=contC[i][j-1]+(org[i][j]<=org[i][j-1]);
	}
  int ans=0;
  /* 枚舉每一個 Row，
   * 再枚舉起點和終點，當起點和終點都屬於同一個嚴格遞增序列才做矩形判定
   * (1) 找出這段區間中最短的 Row 高度代表這個區段內以 Row 為單位維持嚴格遞增的性質
   * (2) 以最短高度為上限，往上檢查同樣區段內的左右點是不是也屬於同一個區段
   */
	for(int i=0;i<R;i++){
		for(int nL=0;nL<C;nL++){
			for(int nR=nL;nR<C and contC[i][nL]==contC[i][nR];nR++){
				// 這個區間中『直行』『嚴格遞增』的最短高度
				int minh=contR[i][nL];
				for(int k=nL+1;k<=nR;k++)
				  minh=min(minh,contR[i][k]);
				// 枚舉每個高度並往上檢驗落在同個區間內的左右點是不是也屬於同個嚴格遞增數列
				// 挑戰失敗就跳開，並記錄挑戰成功的最佳紀錄
				for(int k=1;k<=minh;k++){
					if(contC[i-k+1][nL]!=contC[i-k+1][nR]){
						minh=k-1 ;
						break ;
					}
				}
				ans=max(ans,minh*(nR-nL+1));
			}
		}
	}
	printf("%d\n",ans);
}
/*
5 5
2 1 4 3 5
2 4 3 3 1
3 1 2 4 5
2 3 4 5 1
3 4 2 6 5
3 5
1 2 3 4 5
1 1 2 5 6
2 3 4 5 7
2 4
1 2 7 8
6 7 8 9
*/