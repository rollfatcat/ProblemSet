// 簡單數學: 判斷三角形類型
// __int128要自己寫讀取/輸出 => 順便教優化輸入和輸出
// 盡量用 getchar()/putchar()/puts()
// long double則不用
#include<iostream>
#include<algorithm>
using namespace std;

void scan(__int128 &x){//输入
  x=0;
  int f=1;
  char ch;
  if((ch=getchar())=='-') f=-f;
  else x=x*10+ch-'0';
  while((ch=getchar())>='0' && ch<='9')
      x=x*10+ch-'0';
  x*=f;
}
int main(){
  __int128 L[3];
  int T;
  for(cin>>T,getchar();T--;){
    scan(L[0]), scan(L[1]), scan(L[2]);
    sort(L,L+3);
    if( (L[0]*L[0]+L[1]*L[1])>(L[2]*L[2]) ) puts("acute triangle");
    else if((L[0]*L[0]+L[1]*L[1])<(L[2]*L[2])) puts("obtuse triangle");
    else puts("right triangle");
  }
}