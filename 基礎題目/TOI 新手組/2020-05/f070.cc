/* 給定３組的模數(倆倆互值且數值小於300)和餘數，輸出最小符合條件的數。
 * 題目保證存在一個答案，且答案的數值小於2e6。
 * 題解：
 * 暴力法：因為題目保證存在一個答案Ｍ且Ｍ<2e6，枚舉每個數字。
 * 中國餘式定理(乘法反元素)：sum(餘數*乘法反元素)
   http://jianiau.blogspot.com/2014/05/chinese-remainder-theorem.html
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxM=2e6;
int A[3]; // 保證任意兩個數是互值
int B[3];
inline long InvMul(int c,int M){ // ck ≡ 1(mod M)
	int num[2]={c%M,M}, mat[2][2]={{1,0},{0,1}};
	bool now=1, nxt=0;
	for(int k; num[nxt]>1; swap(now,nxt)){
		k=num[now]/num[nxt];
		mat[now][0]=mat[now][0]-k*mat[nxt][0];
		mat[now][1]=mat[now][1]-k*mat[nxt][1];
		num[now]%=num[nxt];
	}
	return (mat[nxt][0]+M)%M;
}
int main(){
 
	while(scanf("%d %d\n",&A[0],&B[0])!=EOF){
		scanf("%d %d\n",&A[1],&B[1]);
		scanf("%d %d\n",&A[2],&B[2]);
		/* 暴力法枚舉
		 * int ans=B[0];
		 * for( ; ans%A[1]!=B[1] or ans%A[2]!=B[2];ans+=A[0]);
		 */
		 /* 中國餘式定理：sum(餘數*乘法反元素)
		  * 題目保證分母倆倆互質，４個數字的乘積可能超過int範圍
		  * 所以計算反元素時回傳的單位改為long。
		  */
		printf("%d\n",(B[0]*A[1]*A[2]*InvMul(A[1]*A[2],A[0])+
		               B[1]*A[0]*A[2]*InvMul(A[0]*A[2],A[1])+
		               B[2]*A[0]*A[1]*InvMul(A[0]*A[1],A[2]))%(A[0]*A[1]*A[2]));
	}
}