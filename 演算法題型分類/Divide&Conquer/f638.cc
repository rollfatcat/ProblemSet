/* 給定Ｎ個城鎮的人口和分級上限的Ｋ級，劃分行政區時挑選兩側距離差最短的城鎮設定為行政區，輸出所有行政區的人口總和？
 * 城鎮沿著一條道路分佈，劃分行政區時區域內的城鎮數量不能低於３個 且 最多只能劃分到第Ｋ級，一開始所有城鎮屬於第０級。
 * 區域內人口到行政區( m，nL<m<nR )距離的乘積總和：|∑ p[i]*(i-m)|
 * 解題關鍵：遞迴＋前綴和
 *      遞迴：模擬行政區劃分的方式，找出當下區域行政區的城鎮後將左右區域視為子問題處理
 *      前綴和：左邊數來第２個城鎮為行政區的距離需要迴圈累加，但是計算第３個時只要將剛剛算出答案扣除這個區間人口總和即可。
 *          假設目前區域為１-４，計算行政區的所有可能距離
 *          行政區＝２時，－1*p[1]＋0*p[2]＋1*p[3]＋2*p[4]
 *          行政區＝３時，－2*p[1]－1*p[2]＋0*p[3]＋1*p[4]
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e4;
const int MaxK=30;
int num[MaxN+1];
int prS[MaxN+1];
int Recursion(int nL,int nR,int K){
	if(nR-nL<=1 or K==0) return 0;
	int ans_p=nL+1;
	long now_v=-num[nL], w=1;
	for(int i=nL+2;i<=nR;i++,w++)
		now_v+=num[i]*w;
	long ans_v=abs(now_v);
	for(int pvt=nL+2; pvt<nR; pvt++){
		now_v-=prS[nR]-prS[nL-1];
		if(abs(now_v)<ans_v)
			ans_v=abs(now_v), ans_p=pvt;
	}
	return num[ans_p]+Recursion(nL,ans_p-1,K-1)+Recursion(ans_p+1,nR,K-1);
}

int main(){
	int N, K;
	scanf("%d %d\n",&N,&K);
	prS[0]=0;
	for(int i=1;i<=N;i++){
		scanf("%d",&num[i]);
		prS[i]=prS[i-1]+num[i];
    }
	printf("%d\n",Recursion(1,N,K));
}