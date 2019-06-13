// 加強版的c675，實際上可以當作是10進位對9進位的轉換
#include<iostream>
#include<cstring>
using namespace std;

long power9[15]={1};
int main(){
  char char9[10]="012356789";
  for(int i=0;i<=14;i++)
    power9[i+1]=power9[i]*9;
  long x; int idx,L;
  for(char ch, ss[20]; scanf("%c",&ch)!=EOF; getchar()){
    if(ch=='T'){
      scanf("%lu",&x);
      for(idx=0; x; idx++, x/=9)
        ss[idx]=char9[x%9];
      while(idx--)  putchar(ss[idx]);
      puts("");
    } else {
      scanf("%s",ss);
      for(x=idx=0,L=strlen(ss)-1; idx<=L; idx++)
        x+=power9[L-idx]*(ss[idx]-'0'-(ss[idx]>'4'));
      printf("%lu\n",x);
    }
  }
}