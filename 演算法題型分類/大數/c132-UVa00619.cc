/* 測資說明提到最大的情況是"zzzzzzzzzzzzzzzzzzzz"轉換值落在__int128的範圍內
 * 不過輸出格式很麻煩...特別是數字每3位元要加逗號隔開
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int ssL, outL, idx;
  char ss[50], out[50];
  while(true){
    for(ssL=0;(ss[ssL]=getchar())!='\n';ssL++);
    // 結束字串
    if(ss[0]=='*')  break;
    // 判斷輸入是數字還是字母字串
    if(ss[0]<'a'){
      __int128 num=0;
      for(int i=0;i<ssL;i++)
        num=num*10+(ss[i]-'0');
      for(outL=0;num>0;outL++){
        out[outL]=num%26+'a'-1, num/=26;
        if(out[outL]<'a') // 借位
          out[outL]+=26, num--;
      }
      // 依照格式輸出
      for(idx=0;idx<outL;idx++)
        putchar(out[outL-1-idx]);
      while(idx++<22)
        putchar(' ');
      int putidx=ssL%3;
      for(idx=0;idx<ssL;idx++){
        if(idx%3==putidx and idx)
          putchar(',');
        putchar(ss[idx]);
      }
      puts("");
    } else {
      __int128 num=0;
      for(int i=0;i<ssL;i++)
        num=num*26+(ss[i]-'a'+1);
      for(outL=0;num;outL++)
        out[outL]=(char)(num%10+'0'), num/=10;
      // 根據格式輸出
      for(idx=0;idx<ssL;idx++)
        putchar(ss[idx]);
      while(idx++<22)
        putchar(' ');
      int putidx=outL%3;
      for(idx=0;idx<outL;idx++){
        if(idx%3==putidx and idx)
          putchar(',');
        putchar(out[outL-1-idx]);
      }
      puts("");
    }
  }
}