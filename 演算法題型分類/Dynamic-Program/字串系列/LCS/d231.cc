/* 給定兩個基因字串(Ａ/Ｔ/Ｃ/Ｇ組成)，輸出最長共同子序列(保證唯一)，若不存在則輸出"E"
 * 基因字串長度不超過50。
 * 解題關鍵：因為題目保證唯一解答，所以當『字元不同且上左長度相等』時預設的方向不受影響。
 *         動態規劃時同時紀錄該格子是來自於哪個狀態？『回朔』還原共同序列時用的。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=50+1;
char ss[3][MaxL];
int LCS[MaxL][MaxL][2]={};

int main(){
	scanf("%s\n%s\n",ss[0],ss[1]);
  int L0=strlen(ss[0]);
  int L1=strlen(ss[1]);
	for(int i=0;ss[0][i];i++)
		for(int j=0;ss[1][j];j++){
			if(ss[0][i]==ss[1][j])
				LCS[i+1][j+1][0]=LCS[i][j][0]+1;
			else if(LCS[i+1][j][0]>LCS[i][j+1][0])
				LCS[i+1][j+1][0]=LCS[i+1][j][0],
				LCS[i+1][j+1][1]=1;
			else
				LCS[i+1][j+1][0]=LCS[i][j+1][0],
				LCS[i+1][j+1][1]=2;
		}
	if(LCS[L0][L1][0]==0){ puts("E"); return 0; }
	
	ss[2][LCS[L0][L1][0]]='\0';
	for(int x=L0,y=L1,L=LCS[L0][L1][0]-1; x>0 and y>0; )
		if(LCS[x][y][1]==0)
			ss[2][L--]=ss[0][x-1], x--, y--;
		else if(LCS[x][y][1]==1)
			y--;
		else
			x--;
	puts(ss[2]);
}