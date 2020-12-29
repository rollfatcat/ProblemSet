/* 給定Ｎ組括號，依照字典序輸出合法的排列？
 * 解題關鍵：枚舉法
 * 括號的合法配對：左括號的數量不能低於右括號 且 左括號的數量不能多於Ｎ
 * 遞迴時需要紀錄：左括號/ 右括號/ 目前的字元數量
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=13;
int N;
char ss[MaxN<<1|1];
void Enumerate(int nL,int nR,int depth){
	if(depth==(N<<1)){ 
        puts(ss); 
        return; 
    }
	if(nL<N){ 
		ss[depth]='(';
		Enumerate(nL+1,nR,depth+1);
	}
	if(nL>nR){
		ss[depth]=')';
		Enumerate(nL,nR+1,depth+1);
	}
}
int main(){
	while(scanf("%d\n",&N)!=EOF){
		ss[N<<1]='\0';
		Enumerate(0,0,0);
		putchar('\n');
	}
}