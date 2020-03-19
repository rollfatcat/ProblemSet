/* 給定一張地圖，地圖上的'*'代表炸彈，爆炸時會讓所在的整個 Row和 Column受到波及
 * 輸出整張地圖，會受到波及的格子'*'而不會的話是'0'
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=100+2;
char one_row[MaxN];
bool Bomb[2][MaxN];
int main(){
	for(int N;scanf("%d\n",&N)!=EOF;){
		memset(Bomb,0,sizeof(Bomb));
		for(int x=0;x<N;x++){
			scanf("%s\n",one_row);
			for(int y=0;y<N;y++)
				Bomb[0][x]|=one_row[y]=='*',
				Bomb[1][y]|=one_row[y]=='*';
		}
		for(int x=0;x<N;x++,putchar('\n'))
			for(int y=0;y<N;y++)
				putchar( (Bomb[0][x] or Bomb[1][y])? '*':'0' );
	}
}