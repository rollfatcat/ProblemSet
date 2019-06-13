//  練習fgets()，注意自己手動輸入時會多一個'\n'
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  char ss[1000005];
  fgets(ss,sizeof(ss),stdin);
  int l=strlen(ss);
  if(ss[l-1]=='0') putchar('0');
  else{
    if(l%2==0) putchar('-');
    putchar(ss[l-1]);
  }
}