/* 給定Ｎ個客人的怒氣值和完成指定料理的等待時間，如何安排順序讓怒氣值的總和最小化？
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int data[2][MaxN];
int ord[MaxN];
bool compare(int a,int b){ 
	return data[0][a]*data[1][b]>data[1][a]*data[0][b]; }
int main(){
	int N; scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d %d\n",&data[0][i],&data[1][i]),
		ord[i]=i;
	sort(ord,ord+N,compare);
	long mul_sum=0, add_sum=0;
	for(int i=0;i<N;i++)
		add_sum+=data[1][ord[i]],
		mul_sum+=data[0][ord[i]]*add_sum;
	printf("%ld\n",mul_sum);
}