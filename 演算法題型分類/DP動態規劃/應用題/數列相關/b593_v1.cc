// 題目輸入一個字串，判斷該字串的編號(有效字串依據長度且按照字典序嚴格遞增來編碼)
// 排列組合的一種題型，但利用到 DP 枚舉字串長度和現在字元的狀態可以形成的方法數
// 第一種做法是利用 DP 算帕斯卡三角形，而這題的 DP 則是由我們自己定義的方式
// 類似題：d209，加強題：c543
#include<bits/stdc++.h>
using namespace std;

const int MAXL=26;
int cnt[MAXL+1]={0,26};    // cnt[len]：字串長度達 len 前個數的前綴和
int DP[MAXL+1][MAXL+1]={}; // DP[len][char]：[字串長度][目前字元是...]的個數
int main(){
  // init
  for(int i=1;i<=MAXL;i++)
    DP[1][i]=1;
  for(int len=2;len<=MAXL;len++){
    for(int i=1;i<=MAXL;i++){
      for(int j=i+1;j<=MAXL;j++)
        DP[len][i]+=DP[len-1][j];
      cnt[len]+=DP[len][i];
    }
    cnt[len]+=cnt[len-1];
  }
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
    /* 以下部分以"bdfg"為例
     * 長度＝４，需要前綴和３以前的總量
     * 'a'＋xxx 開頭的總數是：DP[3]['a'-'a'+1]
     * 'bc'＋xx 開頭的總數是：DP[2]['c'-'a'+1]
     * 'bde'＋x 開頭的總數是：DP[1]['e'-'a'+1]
     * 'bdfg' 自己也要算一個所以+1
     */
    int number=cnt[len-1];

    char last='a';
    for(idx=0;idx<len;idx++,last++) // <- 字串採嚴格遞增所以每一輪結束的last還要+1
      for(;last<ss[idx];last++)
        number+=DP[len-idx][last-'a'+1];
    printf("%d\n",number+1);
  }
}
// ace
// abcdefguvwxyz