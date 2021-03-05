/* 給定Ｎ個數字，輸出連續子序列最大的總和？
 * 解題關鍵：Divide&Conquer + PrefixSum
 * 將原題轉換為兩數相減(右側數字減左側): maximize{ prS[i]-prS[j] }, j<i
 * 過程需要維護左右子樹的極值(最大/最小值)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
int num[MaxN];
int CDQ(int nL,int nR,int* part){
	if(nL==nR){
		part[0]=part[1]=part[2]=num[nL];
		return num[nL];
	}
	int nM=nL+nR>>1;
	int data[2][3]; // {sum, contL, contR}
 
	int out=max( CDQ(nL,nM,data[0]), CDQ(nM+1,nR,data[1]));
	part[0]=data[0][0]+data[1][0];
	part[1]=max(           data[0][1],data[1][1]+data[0][0]);
	part[2]=max(data[0][2]+data[1][0],            data[1][2]);
	return max(out,data[0][2]+data[1][1]);
}
int main(){
	int N;
	while(scanf("%d\n",&N) and N>0){
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		int data[3];
		int ans=CDQ(0,N-1,data);
		(ans<=0)?puts("Losing streak."):printf("The maximum winning streak is %d.\n",ans);
	}
}