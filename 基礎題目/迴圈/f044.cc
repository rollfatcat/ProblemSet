/* 史萊姆王只有初始時給定的１隻，因此題目給定的"比例"化簡後就是小史萊姆的數量
 * 小史萊姆的數量＝前一天的兩倍(每隻小史萊姆都可以分裂出一個新的)＋1(史萊姆王分裂)
 * 小史來母的數量＋1後取log()即可知道經過的天數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
const int MaxT=40950;

int main(){
	for(int N,T;scanf("%d %d\n",&N,&T)!=EOF;)
		printf("%d\n",__lg(T/N+1));
}