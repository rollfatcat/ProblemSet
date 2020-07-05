/* 給定Ｗ×Ｈ地圖和Ｑ個謎題數量，地圖上有小寫的英文字母標示的謎題，依字母順序輸出前Ｑ個謎題的位置。
 * 當地圖上存在的謎題數量＜Ｑ個時輸出 "Mission fail."
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxW=10;
char ch;
int pos[26][2];
int main(){
	int W, H, Q, cnt=0;
	scanf("%d %d\n%d\n",&W,&H,&Q);
	memset(pos,-1,sizeof(pos));
	for(int i=0;i<W;i++)
		for(int j=0;j<H;j++){
			scanf("%c ",&ch);
			if(ch!='0')
				pos[ ch-'a' ][0]=i,
				pos[ ch-'a' ][1]=j,
				cnt++;
		}
	
	if(cnt<Q){ puts("Mission fail."); return 0; }
	for(int i=0,j=0;i<26 and j<Q;i++)
		if(pos[i][0]>=0)
			printf("%d %d\n",pos[i][0],pos[i][1]), j++;
}