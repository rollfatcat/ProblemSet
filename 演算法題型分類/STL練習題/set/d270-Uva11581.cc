/* 給定３×３的地圖 和 轉換規則(該格子的新值＝周圍格子和的模２＝做XOR)
 * 問經過數次轉換後產生所有的圖(不包含全部＝０和一開始給定的初始地圖)有多少張？
 * 直覺：需要用 set 紀錄出現過的地圖來判斷新地圖時是否重複？
 * 地圖只有９格且每個位置的值都是布林值＝狀態最多只有2^9個，將新地圖轉換為數值後判斷該數值是否出現過？
 */
#include<bits/stdc++.h>
using namespace std;
 
char ss[5];
bool v[2][3][3];
bool IsOn[1<<9];
inline int BoardToInt(bool now,int out=0){
	for(int x=0,B=0;B<9;x++,B+=3)
		out|=( v[now][x][0]<<B )|( v[now][x][1]<<(B+1) )|( v[now][x][2]<<(B+2) );
	return out;
}
int main(){
	int caseT;
	for(scanf("%d\n",&caseT);caseT--;){
		for(int x=0;x<3;x++){
			scanf("%s\n",ss);
			v[0][x][0]=ss[0]=='1';
			v[0][x][1]=ss[1]=='1';
			v[0][x][2]=ss[2]=='1';
		}
		fill(IsOn,IsOn+(1<<9),0);
		int now_v=BoardToInt(0);
		int cnt=0;
		
		bool pre=0, now=1;
		do{
			IsOn[now_v]=1;
			cnt++;
			v[now][0][0]=v[pre][0][1]^v[pre][1][0];
			v[now][0][1]=v[pre][0][0]^v[pre][0][2]^v[pre][1][1];
			v[now][0][2]=v[pre][0][1]^v[pre][1][2];
			v[now][1][0]=v[pre][0][0]^v[pre][1][1]^v[pre][2][0];
			v[now][1][1]=v[pre][0][1]^v[pre][1][0]^v[pre][1][2]^v[pre][2][1];
			v[now][1][2]=v[pre][0][2]^v[pre][1][1]^v[pre][2][2];
			v[now][2][0]=v[pre][1][0]^v[pre][2][1];
			v[now][2][1]=v[pre][1][1]^v[pre][2][0]^v[pre][2][2];
			v[now][2][2]=v[pre][1][2]^v[pre][2][1];
			now_v=BoardToInt(now);
			swap(now,pre);
		}while(IsOn[now_v]==0);
		printf("%d\n",cnt-2);
	}
}