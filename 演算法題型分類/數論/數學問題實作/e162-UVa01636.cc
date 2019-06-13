// 機率計算問題(精確度的教學題，不過用 double 計算也可以過關計算也可以過關)
/* 已知這顆子彈是空包彈的前提下，下顆是空包彈的機率高時選擇"SHOOT"，否則就隨機轉動滾輪選擇"ROTATE"
 * 機率計算涉及精確度問題，最安全的方式需要避開『除法』互乘分母。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 102

int main(){
  char chain[MAXN];
  while(scanf("%s",chain)!=EOF){
    int len=strlen(chain);
    int Onezero_cnt=0; // 單獨一個0的個數
    int Twozero_cnt=0; // 連續兩個0的個數
    for(int i=0;i<len;i++)
      if(chain[i]=='0'){
        Onezero_cnt++;
        if(chain[(i+1)%len]=='0')
          Twozero_cnt++;
      }
    /* 因為前一次是空包彈，ROTATE後空包彈的個數不變，以下是兩者機率的一般計算
    double ROTATE=(double)Onezero_cnt/len;
    double SHOOT=(double)Twozero_cnt/Onezero_cnt;
    */
    // 將機率的除法運算轉為乘法比較大小
    int ROTATE=Onezero_cnt*Onezero_cnt;
    int SHOOT=Twozero_cnt*len;
    // printf("%d %d %lf %lf\n",Onezero_cnt,Twozero_cnt,ROTATE,SHOOT);
    if(SHOOT>ROTATE) puts("SHOOT");
    else if(SHOOT<ROTATE) puts("ROTATE");
    else puts("EQUAL");
  }
}
/*
0011
0111
000111
*/