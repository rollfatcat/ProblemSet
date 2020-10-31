/* 給定Ｎ位選手的報名編號和筆試分數，錄取前 150%×Ｍ(無條件捨去) 位選手的資訊(若有其他選手與最低標同分時一併錄取)？
 * 排序規則：依照筆試分數高到低排序，同分時依據報名編號低到高。
 * 解題關鍵：排序
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e3;
int data[MaxN][2];

bool better(int a,int b){ return (data[a][1]!=data[b][1])? data[a][1]>data[b][1]: data[a][0]<data[b][0]; }
int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d %d\n",&data[i][0],&data[i][1]);
		for(int j=i-1;j>=0 and better(j+1,j);j--)
			swap(data[j+1],data[j]);
	}
	M+=M>>1;
	while(M<N and data[M-1][1]==data[M][1])
		M++;
	printf("%d %d\n",data[M-1][1],M);
	for(int i=0;i<M;i++)
		printf("%d %d\n",data[i][0],data[i][1]);
}
