/* 給定Ｎ個石頭，石頭上刻有數字，依照規定的前提下先手最多可以贏後手幾分？
 * 規定：可以一次拿走數個石頭(不需要按照給予的順序)但該次的分數會以拿取石頭中分數最低者。
 * 解題關鍵：排序＋Nim
 * 排序：因為每次都是以拿走石頭中最低分者為主，所以將石頭排序，分數越低一定是順序越後才拿。
 * 枚舉Ｎ=１,２,３時最佳解
 *      N=1, dp(1)=num[0]
 *      N=2, dp(2)=max(num[0], num[1]-num[0]) 
 *                      先手拿走第２個和第１個，因為dp(1)時先手必定有拿第１個 
 *                      先手只拿走第２個，後手會參考dp(1)勢必會拿走第１個 ... Nim的策略
 *      N=3, dp(3)=max( dp(2), num[2]-dp(2) )
 *                      先手至少拿走第３個和第２個，因為dp(2)時先手必定有拿第２個 
 *                      先手這次只拿走第３個，後手並定會參考dp(2)拿較高者 ... Nim的策略
 * 更新時只和前一刻的狀態有關，所以仿造滾動陣列的概念 dpv 只需要一個變數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxV=1e9;
int N;
int num[MaxN];
int main(){
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&num[i]);
	/* 分數越低越後拿，所以從結束往回推時要優先更新＝數字越小越先討論 */
    sort(num,num+N);
    /* dpv代表拿了Ｎ-1個石頭時的最佳解，討論拿第Ｎ個石頭時的情況 */
	int dpv=num[0];
	for(int i=1;i<N;i++)
		dpv=max(dpv,num[i]-dpv);
	printf("%d\n",dpv);
}

