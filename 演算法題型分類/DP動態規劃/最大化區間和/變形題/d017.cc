// 題目答案的(1,2)代表字串包含陣列位置從1開始一直到2(不包含2這個位置)所構成的子字串
/* DP＋數學解法 (32ms)
 * 只要知道A的個數，以及B的個數即可
 * 假設起始點是i，那麼終點的就是i+min(CA,CB)  or i+max(CA,CB)
 * ss[i]～ss[j]這個子字串有 x個A 和 j-i+1-x個B，另個子字串有 CA-x個A 和 CB-j+i-1+x個B
 * (1) x＝CB-j+i-1+x => j=CB+i-1;
 * (2) j-i+1-x＝CA-x => j=CA+i-1;
 * (1)或(2) 推算出來的切點必須落在字串長度內才是合理的
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXL=1001;
int main(){
  char ss[MAXL];

  for(int caseN=1;scanf("%s",ss)!=EOF;caseN++){
    if(caseN>1) puts("");
    int len=strlen(ss);
    int Acnt=0, Bcnt=0;
    for(int i=0;i<len;i++)
      (ss[i]=='a')?Acnt++:Bcnt++;
    printf("AB Circle #%d:\n",caseN);
    if(Acnt==Bcnt){
      for(int i=0;i+Acnt<len;i++)
        printf("%d,%d\n",i,i+Acnt);
    }else{
      for(int i=0;i+min(Acnt,Bcnt)<len;i++){
        printf("%d,%d\n",i,i+min(Acnt,Bcnt));
        if(i+max(Acnt,Bcnt)<len)
          printf("%d,%d\n",i,i+max(Acnt,Bcnt));
      }
    }
  }
}