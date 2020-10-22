// 題目答案的(1,2)代表字串包含陣列位置從1開始一直到2(不包含2這個位置)所構成的子字串
// 前綴和＋暴力法(嘗試每組的起點/終點) (84ms)

#include<bits/stdc++.h>
using namespace std;

const int MAXL=1001;
char ss[MAXL];
int A[MAXL];
int B[MAXL];
int main(){
  for(int caseN=1;scanf("%s",ss)!=EOF;caseN++){
    if(caseN>1) puts("");
    int len=strlen(ss);
    for(int i=0;i<len;i++)
      A[i+1]=A[i]+(ss[i]=='a'),
      B[i+1]=B[i]+(ss[i]=='b');
    printf("AB Circle #%d:\n",caseN);
    for(int st=0;st<len;st++)
      for(int ed=st+1;ed<len;ed++)
        if( A[ed]-A[st]==B[len]-B[ed]+B[st] or
            B[ed]-B[st]==A[len]-A[ed]+A[st] )
          printf("%d,%d\n",st,ed);
  }
}