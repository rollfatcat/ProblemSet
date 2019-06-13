// 練習迴圈控制
#include<bits/stdc++.h>
using namespace std;

int main(){
  for(int budget,keep,save,tmp,month; scanf("%d",&budget)!=EOF;){
    // 第一個月份的計算
    keep=300-budget;
    save=(keep>=100)?(keep/100*100):0;
    keep-=save;
    if(keep<0){ puts("-1"); continue; }
    for(month=2;month<=12;month++){
      scanf("%d",&budget);
      keep+=300-budget;
      if(keep>=100)
        tmp=keep/100*100,
        keep-=tmp,
        save+=tmp;
      if(keep<0){
        printf("-%d\n",month); break;
      }
    }
    if(month==13)
      printf("%d\n",keep+save/5*6);
    // 把剩餘的月份輸入讀取完
    for(month++;month<=12;month++)
      scanf("%d",&budget);
  }
}
/*
290
230
280
200
300
170
340
50
90
80
200
60
*/