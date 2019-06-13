// 題目輸入一個字串，判斷該字串的編號(有效字串依據長度且按照字典序嚴格遞增來編碼)
// 排列組合的一種題型，但利用到 DP 建巴斯卡三角塔來做個數加總
// 類似題：d209，加強題：c543
#include<bits/stdc++.h>
using namespace std;

const int MAXL=26;
int DP[MAXL+1][MAXL+1]={}; // DP[A][B]=Ｃ(A+B)取B
int main(){
  // init : 解法是依照『斜率』去填格子，我自己是由上到下左到右填
  for(int i=0;i<=MAXL;i++)
    DP[0][i]=DP[i][0]=1;
  for(int i=1;i<=MAXL;i++)
    for(int j=1;j<=MAXL-i;j++)
      DP[i][j]=DP[i-1][j]+DP[i][j-1];
  //
  int idx, len;
  char ss[30];
  while(scanf("%s",ss)){
    if(ss[0]=='0') break;
    len=strlen(ss);
    for(idx=1;idx<len and ss[idx-1]<ss[idx];idx++);
    // 非法字串：字元未依照字典序嚴格遞增
    if(idx<len){ puts("0"); continue; }

    // 合法字串才做編碼計算
    // 以下部分以"bdfg"為例
    int number=0;
    // 長度-1的個數總和 => 當長度=4時，Ｃ26取1＋Ｃ26取2＋Ｃ26取3
    for(idx=1;idx<len;idx++)
      number+=DP[MAXL-idx][idx];

    /* 'a'  開頭的總數是Ｃ25取3，根據DP定義：DP[22][3]
     * 'bc' 開頭的總數是Ｃ23取2，根據DP定義：DP[21][2]
     * 'bde'開頭的總數是Ｃ21取1，根據DP定義：DP[20][1]
     * 'bdfg' 自己也要算一個所以+1
     */
    char last='a';
    for(idx=0;idx<len;idx++,last++)
      for(;last<ss[idx];last++)
        number+=DP[MAXL-(last-'a')-(len-idx)][len-1-idx];
    printf("%d\n",number+1);
  }
}
// abcdefguvwxyz