/* 給定Ｎ代表數列由１到Ｎ組成，利用堆疊(Stack)作為暫存區改變順序，輸出所有能夠達成的排列數量？
 * 改變順序：參考 c123-UVa00514 的圖解
 * 解題關鍵：卡塔蘭數(動態規劃求第Ｎ項，狀態轉移：ƒ(Ｎ)＝ Σ ƒ(i)×ƒ(Ｎ-i-1) )
 * ƒ(３)＝１×２＋１×１＋２×１＝５
 *  第１個位置放１，Stack is {} and {２３} is subproblem：１２３,１３２
 *  第１個位置放２，Stack is {１} and {３} is subproblem：２３１,２１３
 *  第１個位置放３，Stack is {１２} and {} is subproblem：３２１
 * ƒ(４)＝１×５＋１×２＋２×１＋５×１＝１４
 *  第１個位置放１，Stack is {} and {２３４} is subproblem：１２３４,１２４３,１３４２,１３２４,１４３２
 *  第１個位置放２，Stack is {１} and {３４} is subproblem：２１３４,２１４３,２３１４,２３４１,２４３１
 *  第１個位置放３，Stack is {１２} and {４} is subproblem：３４２１,３２４１,３２１４
 *  第１個位置放４，Stack is {１２３} and {} is subproblem：４３２１
 *  討論３４２１：其實第１個位置放３後，再第２個位置放４可以視為ƒ(３)時第１個位置放３...。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=18;
long dpv[MaxN+1]={1,1,2,5};
int main(){
	for(int i=4;i<=MaxN;i++)
		for(int j=0;j<i;j++)
			dpv[i]+=dpv[j]*dpv[i-j-1];
	int N;
	while(scanf("%d\n",&N)!=EOF)
		printf("%ld\n",dpv[N]);
}
