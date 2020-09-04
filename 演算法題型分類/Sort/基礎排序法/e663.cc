/* 給定１０個數字當作５位小朋友中任選２位的體重和，最後由小到大輸出５小朋友的體重
 * 解題關鍵：
 * １０個數字的和＝所有小朋友體重和的４倍
 * 中間小朋友的體重＝所有小朋友體重和−最大值(體重最大和次大的和)−最小值(體重最小和次小的和)
 * 體重最小＝次小值(中間小朋友和體重最小值的和)-中間小朋友的體重
 * 體重最大＝次大值(中間小朋友和體重最大值的和)-中間小朋友的體重
 * 代表需要將１０個數字做排序。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=10;
int num[MaxN];
int main(){
	int sum=0;
	for(int i=0;i<MaxN;i++)
		scanf("%d",&num[i]), 
		sum+=num[i];
	sort(num,num+MaxN);
	int mid=(sum>>2)-num[MaxN-1]-num[0];
	
	printf("%d %d %d %d %d\n",num[1]-mid,num[0]-(num[1]-mid),mid,num[MaxN-1]-(num[MaxN-2]-mid),num[MaxN-2]-mid);
}
