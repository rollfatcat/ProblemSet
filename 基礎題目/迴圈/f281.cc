/* 給定Ｎ個同學的亮度和最低的亮度要求Ｌ，輸出至少要調高多少才能讓最低亮度達到要求？
 * 規則：當調高某個人的亮度時其他人的亮度會下降
 * 解題關鍵：找到最小值和次小值
 * 當最小值提高到要求時檢查次小值降低該數值後是否仍達要求？
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
int num[2];
int main(){
	int N, L, v;
 
	scanf("%d\n",&N);
	num[0]=num[1]=1e4;
	for(int i=0;i<N;i++){
		scanf("%d",&v);
		if(v<num[0]){
			num[1]=num[0];
			num[0]=v;
		}else if(v<num[1])
			num[1]=v;
	}
	scanf("%d\n",&L);
	num[1]-=L-num[0];
	(num[1]>=L)? printf("%d\n",L-num[0]): puts("You are too black!");
}