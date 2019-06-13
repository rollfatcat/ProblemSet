// 預備題： a134-UVa00948
// 題目保證字串長度不會超過 100
// 費波那契數列的成長幅度小於2的指數成長(換句話說轉換後的數值落在 __int128 的範圍內)
// 作弊法：將輸入的兩個字串各自轉為數值相加後再轉回費波那契數列進位的格式輸出即可
// 費波那契數列的轉換方式就是用二分法找到最大但小於目前數字的值，扣除並在該位數上紀錄1
#include<bits/stdc++.h>
using namespace std;

const short MAXN=105;
int main(){
  __int128 FIB[105]={1,2};
  for(int i=2;i<=100;i++)
    FIB[i]=FIB[i-1]+FIB[i-2];

  char ss[MAXN];
  short ssL, pos, L;
  for(int caseN=0;scanf("%s",ss)!=EOF;caseN++){
    if(caseN) puts("");
    // 處理輸入並且用 __int128 的型態儲存加總值
    ssL=strlen(ss);
    __int128 sum=0;
    for(int i=0;i<ssL;i++)
      if(ss[i]=='1')
        sum+=FIB[ssL-1-i];
    scanf("%s",ss);
    ssL=strlen(ss);
    for(int i=0;i<ssL;i++)
      if(ss[i]=='1')
        sum+=FIB[ssL-1-i];
    // 換成費波那契數列的進位格式
    memset(ss,0,sizeof(ss));
    for(;sum; ss[pos]=1,sum-=FIB[pos])
      pos=upper_bound(FIB,FIB+101,sum)-FIB-1;

    // 輸出
    L=MAXN-1;
    for(;ss[L]==0 and L;L--);
    for(;L>=0;L--)
      putchar(ss[L]+'0');
    puts("");
  }
}
