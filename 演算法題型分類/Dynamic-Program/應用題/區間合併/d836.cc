/* 給定Ｎ個數字(必須)拆分成Ｍ組，將每組數字總和模１０後相乘的極值(最大＋最小)？
 * 分組規則：數字只能和相鄰的歸類為同一組並且頭尾相接(環狀架構)
 * 解題關鍵：(區間合併類型)動態規劃＋前綴和
 * 動態規劃：目標Ｍ組時確保Ｍ-1組的所有組合(起點×終點)已經完成更新，透過乘以新增的"一組"。
 * 狀態定義：[最大/最小][拆分組數１-Ｍ][起點][終點]
 * 狀態轉移：TopDown(最大/最小，拆分組數１-Ｍ，起點，終點)，枚舉中間的點作為切割出新一組
 *         dpv[0][g][nL][nR]=max(dpv[0][g][nL][nR],dpv[0][g-1][nL][nM]*((prS[nR]-prS[nM])%10) )
 *	       dpv[1][g][nL][nR]=min(dpv[1][g][nL][nR],dpv[1][g-1][nL][nM]*((prS[nR]-prS[nM])%10) )
 */
#include<bits/stdc++.h>
using namespace std;
 
int MaxN=50;
int MaxM=9;
int MaxV=1e4;
int N, M, v;
int prS[105]={};
int dpv[2][10][105][105];
 
int main(){
	scanf("%d %d\n",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&prS[i]);
		prS[N+i]=prS[i]=(prS[i]<0)? prS[i]%10+10: prS[i]%10;
	}
	/* 處理狀態轉移時，會透過新增"一組"的方式利用「前綴和」Ｏ(1)算出區間內的總和 */
	for(int i=1;i<=(N<<1);i++)
		prS[i]+=prS[i-1];
	/* 初始化：當Ｍ＝１時，利用「前綴和」計算區間內的值 */
	for(int nL=1; nL<N; nL++)
		for(int nR=nL; nR<=nL+N; nR++)
			dpv[0][1][nL][nR]=dpv[1][1][nL][nR]=(prS[nR]-prS[nL-1])%10;
	/* 狀態轉移：枚舉(起點)nL和(終點)nR以及(中間的切點)nM
	 * 初始化目前狀態的值，最大＝INT_MIN 最小＝INT_MAX
	 * 過程中需要保持上述的區間落在「合法範圍」：nR-nL+1 ≥ g 且 nM-nL+1 ≥ g-1
	 * 因為是環狀架構，所以終點位置和起點位置必定差距Ｎ
	 */
	for(int g=2;g<=M;g++)
		for(int nL=1;nL<N;nL++)
			for(int nR=nL+g-1; nR<=nL+N; nR++){ // nR-nL+1 ≥ g
				dpv[0][g][nL][nR]=INT_MIN;
				dpv[1][g][nL][nR]=INT_MAX;
				for(int nM=nL+g-2;nM<nR;nM++)   // nM-nL+1 ≥ g-1
					dpv[0][g][nL][nR]=max(dpv[0][g][nL][nR],dpv[0][g-1][nL][nM]*((prS[nR]-prS[nM])%10) ),
					dpv[1][g][nL][nR]=min(dpv[1][g][nL][nR],dpv[1][g-1][nL][nM]*((prS[nR]-prS[nM])%10) );
			}
	/* 比對時取極值 */
	int max_ans=INT_MIN;
	int min_ans=INT_MAX;
	for(int i=1;i<N;i++)
		max_ans=max(max_ans,dpv[0][M][i][i+N-1]),
		min_ans=min(min_ans,dpv[1][M][i][i+N-1]);
	printf("%d\n%d\n",min_ans,max_ans);
}
