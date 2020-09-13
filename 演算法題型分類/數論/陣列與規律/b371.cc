/* 題目給定邊長Ｎ(Ｎ必定是４的倍數)的矩陣和位置Ｒ、Ｃ，輸出該矩陣那格位置的數字？
 * 矩陣規則：如題
 * 解題關鍵：二維矩陣和二元一次方程式描述斜率
 *      若Ｒ＋Ｃ模４的餘數是１ 或是 Ｒ-Ｃ是４的倍數時則依照"反向"規則推測填入的數字
 *      否則只要依照"順向"規則推測數字
 */
#include<bits/stdc++.h>
using namespace std;

int MaxCaseT=99;
int MaxN=2147483640;
int main(){
	int caseT;
	long N, R, C;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%ld %ld %ld\n",&N,&R,&C);
		printf("%ld\n", ((R-C)%4==0 or (R+C)%4==1)? (N-R+1)*N-C+1: (R-1)*N+C);
	}
}