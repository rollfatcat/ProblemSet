// 假裝是零錢問題實際上不需要這麼複雜... GCD(a,b)=1 and c>(a*b-a-b)
// 初步構想是當作一種零錢問題, 暴力法測0~10000 時間是4ms
// 剪枝可以讓時間降為0ms (1)GCD (2)從c往後測試a個就可以
#include<iostream>
#include<cstring>
using namespace std;

int GCD(int x, int y){ return(x%y)?GCD(y,x%y):y; }
int main(){
  int a, b, c, x;

  while(cin>>a>>b>>c){
    if(b>a) x=a, a=b, b=x;
    if(GCD(a,b)!=1){  cout<<"No\n"; continue; }
    if(c>=(a*b-a-b)){  cout<<"Yes\n"; continue; }
    int idx, bound=(c+a>10000)?10000:(c+a);
    bool isNum[bound+1];
    memset(isNum,0,sizeof(isNum));
    for(int i=0;b*i<=bound;i++)
      isNum[b*i]=1;
    for(idx=c; idx<bound and isNum[idx] ;idx++);
    if(idx==bound)  cout<<"Yes\n";
    else cout<<"No\n";
  }
}