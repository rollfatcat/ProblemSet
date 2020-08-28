/* 輸出 40755 後第一個皆存在３個數列內的數字？
 * 解題關鍵：狀態展開
 * 若３個數列的每個值只要一個不一樣就進迴圈
 *    每次從３個數列中取最小值，若該數列當前的數字是最小值時則需要依照數列定義計算下一個數字
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	long Ti=286, Pi=166, Hi=144;
	long number[3]={ Ti*(Ti-1)/2, Pi*(3*Pi-1)/2, Hi*(2*Hi-1) };
	while(number[0]!=number[1] or number[1]!=number[2]){
		long minv= min(min(number[0],number[1]),number[2]);
		if(minv==number[0]) Ti+=1, number[0]=Ti*(Ti-1)/2;
		if(minv==number[1]) Pi+=1, number[1]=Pi*(3*Pi-1)/2;
		if(minv==number[2]) Hi+=1, number[2]=Hi*(2*Hi-1);
	}
	printf("%ld\n",number[0]);
}