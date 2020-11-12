/* 每行給定Ｎ個數字(數字間以空白隔開)，答案數列必定是１-Ｎ剛好有一個的組合？
 * 位置０的數字代表數字１在答案數列中的位置前有多少個數字比自己大。
 * 解題關鍵：順序性更新。
 * 每次查詢數列中第一個"前面大於自己的個數＝０"的數字，並更新這個數字前的所有數字"""
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=50;
int num[MaxN]; 
int main(){
	int N, pvt;
	while(scanf("%d",&num[0])!=EOF and num[0]!=-1){
		/* input */
        for(N=1;getchar()==' ';N++)
			scanf("%d",&num[N]);
        /* main */
		for(int t=0;t<N;t++){
			/* 找到數列當中第一個０ */
            for(pvt=0; num[pvt]>0; pvt++);
			printf("%d ",pvt+1);
            /* 改動這個數字之前的個數都減１，代表其他數字(這個數字之前)要放入數列時要等候的個數減１ */
			for(num[pvt--]=INT_MAX; pvt>=0; num[pvt--]-=1);
		}
		putchar('\n');
	}
}