/* 模擬二維黑白影像壓縮的編碼方式
 * 標準 Divide and Conquer 題目(簡易)
 * 遞迴直到該區域不存在或是區域內只剩下一格時...
 * 考量合併區域時4塊區域是否都屬於同一個顏色
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=(1<<7)+1;
char color[MAXN][MAXN];

string DFS(int Lx,int Ly,int Rx,int Ry){
  /* 題目保證輸入的邊長是2的次方 => 不需考慮『超過邊界』的問題
   * 若邊長不屬於2的次方則需要
   */
  if(Rx-Lx<=0 or Ry-Rx<=0) return ""; // 該區域不存在故回傳空字串
  if(Rx-Lx==1 and Ry-Ly==1)return (color[Lx][Ly]=='0')?"w":"b"; // 區域內只存在一格時...
  int Mx=Lx+Rx>>1, My=Ly+Ry>>1;
  string RU=DFS(Lx,My,Mx,Ry);
  string LU=DFS(Lx,Ly,Mx,My);
  string LD=DFS(Mx,Ly,Rx,My);
  string RD=DFS(Mx,My,Rx,Ry);
  /* 區域合併：考慮範圍內4個區塊的顏色
   * (1)相同時，就回傳 屬於該地區的顏色字串
   * (2)不同時，就回傳 "g"+屬於4個地區的顏色字串相加(注意順序)
   */
  bool TheSame=(RU.length()==1 and LU.length()==1 and LD.length()==1 and RD.length()==1);
  TheSame&=(RU==LU and RU==LD and RU==RD);
  return (TheSame)? RU: "g"+RU+LU+LD+RD;
}
int main(){
  int N;
  while(scanf("%d\n",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%s",color[i]);
    string ans=DFS(0,0,N,N);
    for(char c:ans)
      putchar_unlocked(c),
      putchar_unlocked(' ');
    putchar_unlocked('\n');
  }
}