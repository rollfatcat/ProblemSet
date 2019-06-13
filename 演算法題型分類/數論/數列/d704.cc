// 費波那契數列的進位運算版本
#include<iostream>
#include<vector>
using namespace std;

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){

  vector<int> FIB;
  FIB.push_back(2),
  FIB.push_back(3);
  for(int i=1;FIB.back()>0;i++)
    FIB.push_back(FIB[i-1]+FIB[i]);
  FIB.pop_back();
  for(int n; scanInt(n); ){
    vector<int>ans;
    for(int i=0;n>=FIB[i];i++)
      ans.push_back(n%FIB[i]), n/=FIB[i];
    printf("%d",n);
    for(int i=ans.size()-1;i>=0;i--)
      printf(",%d",ans[i]);
    puts("");
  }
}