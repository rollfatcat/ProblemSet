// fgets() 版本

#include<bits/stdc++.h>
using namespace std;

int len;
char buf1[1<<12];
char buf2[1<<12];
void printInt(int x,int base=10){
  while(base<=x) base*=10;
  while(base>1)  base/=10,buf2[len++]=(x/base+'0'),x%=base;
  buf2[len++]=' ';
}

int main(){
  int n, x;
  while(scanf("%d\n",&n)!=EOF){
    n--;
    len=0;
    int x=0;
    for(char *p=fgets(buf1,sizeof(buf1),stdin); *p!=0; ++p){
       if(*p<'0'){
          if(n)
            printInt(x*n);
          x=0;
          --n;
       }
       else
        x=(x<<3)+(x<<1)+*p-'0';
    }
    if(len)
      buf2[len]=0,
      puts(buf2);
    else
      puts("0");
  }
}