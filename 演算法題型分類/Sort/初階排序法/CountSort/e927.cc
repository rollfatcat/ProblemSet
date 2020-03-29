/* CountSort
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1e6;
int cnt[256]={};
int main(){
	for(char ch;(ch=getchar())!=EOF;)
		cnt[ch]++;
	for(int i='A';i<='Z';i++)
		for(int j=0;j<cnt[i];j++)
			putchar(i);
	putchar('\n');
}
