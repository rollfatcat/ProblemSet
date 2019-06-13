// 不同基底的進位制轉換，不需考慮加總後的值會超過 int 範圍
#include<stdio.h>

int main(){
  char ch[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  for(char ss[20]; scanf("%s",ss)!=EOF;){
    int A, B, C=0, i;
    scanf("%d %d",&A,&B);
    for(i=0;ss[i]!='\0';i++)
      C=C*A+ss[i]-((ss[i]>='A')?('A'-10):'0');
    for(i=0;C;i++)
      ss[i]=ch[C%B], C/=B;
    if(i>7) puts("  ERROR");
    else{
      for(C=6;C>=i;C--) putchar(' ');
      while(i--)  putchar(ss[i]);
      puts("");
    }
  }
}