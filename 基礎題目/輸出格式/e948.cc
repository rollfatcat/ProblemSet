/* 給定計算公式，根據男女輸出每日所有的熱量
 * 輸出到小數點後第二位四捨五入。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20;
int main(){
	int N, gender, wgt, hgt, age;
	scanf("%d\n",&N);
	while(N--)
		scanf("%d %d %d %d\n",&gender,&age,&hgt,&wgt),
		printf("%.2lf\n",(gender==1)? (13.7*wgt+5.0*hgt-6.8*age+66):(9.6*wgt+1.8*hgt-4.7*age+655) );
}