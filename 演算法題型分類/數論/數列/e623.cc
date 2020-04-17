/* 觀察一下發放物品的序列。第一輪有四個物品、第二輪有八個物品、……、第 K 輪有 4K 個物品。
 * 所以可以找到最小的某一輪 K 使得 4 ＋ 8 ＋ …… ＋ 4K ≧ N ，
 * 此即代表第 N 個人得到的物品必定坐落於第 K 輪之中。
 * 然後再做一些計算，因為每種物品佔該輪的四分之一， Ｎ扣除掉前面Ｋ－1的數量後除以Ｋ的商數即可知道其對應到的物品為何了。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
char ss[4][20]={"Pen","Pineapple","Apple","Pineapple pen"};
int main(){
	for(int N,D;scanf("%d\n",&N)!=EOF;){
		N--;
		D=sqrt(N>>1);
		D-= (N>>1)<D*(D+1);
		puts( ss[(N-(D*(D+1)<<1))/(D+1)] );
	}
}