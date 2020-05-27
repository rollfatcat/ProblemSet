/* 給定一星期每天４個時段的降雨量，輸出降雨量最多的星期和時段
 */
#include<bits/stdc++.h>
using namespace std;

const char ss[4][15]={"morning","afternoon","night","early morning"};
double sum[4]={};

int main(){
	double M, A, N, E, MaxSum=0.0;
	int MaxD=0, MaxT=0;
	for(int nowD=1;nowD<=7;nowD++){
		scanf("%lf %lf %lf %lf\n",&M,&A,&N,&E);
		sum[0]+=M, sum[1]+=A, sum[2]+=N, sum[3]+=E;
		if(MaxSum<M+A+N+E)
			MaxD=nowD,
			MaxSum=M+A+N+E;
	}
	
	MaxSum=sum[0];
	for(int i=1;i<=3;i++)
		if(MaxSum<sum[i])
			MaxT=i,
			MaxSum=sum[i];
	printf("%d\n%s\n",MaxD,ss[MaxT]);
}