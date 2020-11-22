/* 給定邊長Ｎ(題目保證Ｎ為２的次方)的布林陣列，根據二維黑白影像壓縮的編碼方式輸出字串？
 * 解題關鍵：Divide and Conquer
 * 遞迴直到該區域不存在或是區域內只剩下一格時，考量合併區域時4塊區域是否都屬於同一個顏色
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1<<7;
char color[MAXN][MAXN+2];

string CDQ(int Lx,int Ly,int Rx,int Ry){
  /* 題目保證輸入的邊長是2的次方 ... 不需考慮『超過邊界』的問題，若邊長不屬於2的次方則需要 */
  if(Lx>Rx  or  Ly>Ry ) return ""; // 該區域不存在故回傳空字串
  if(Lx==Rx and Ly==Ry) return (color[Lx][Ly]=='0')?"w":"b"; // 區域內只存在一格時...
  int Mx=Lx+Rx>>1;
  int My=Ly+Ry>>1;
  string RU=CDQ(  Lx,Mx,My+1,Ry);
	string LU=CDQ(  Lx,Mx,  Ly,My);
	string LD=CDQ(Mx+1,Rx,  Ly,My);
	string RD=CDQ(Mx+1,Rx,My+1,Ry);
  /* 區域合併：考慮範圍內4個區塊的顏色
   * (1)相同時，就回傳 屬於該地區的顏色字串
   * (2)不同時，就回傳 "g"+屬於4個地區的顏色字串相加(注意順序)
   */
  string ss=(RU=="")? (LU=="")? (LD=="")? RD:LD :LU: RU ;
  return( (RU=="" or ss==RU) and (LU=="" or ss==LU) and (LD=="" or ss==LD) and (RD=="" or ss==RD))? ss: "g"+RU+LU+LD+RD;
}
int main(){
  int N;
  while(scanf("%d\n",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%s\n",color[i]);
    string ans=CDQ(0,N-1,0,N-1);
    for(char c:ans)
      printf("%c ",ch);
    putchar('\n');
  }
}