// 題目給定一張地圖(任兩點之間的邊可能不只一條)問能不能一筆畫完
// Euler Route 判斷：計算每個點的 Indegree + Outdegree，總和是奇數的點數只能是2或是0
// 要一筆完成時起終點必須是奇數 degree 的點(所以最多是2個)
#include<iostream>
#include<vector>
using namespace std;

inline bool scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}
int main(){
  for(int V,E;scanInt(V) and scanInt(E);){
    vector<int> num(V+1,0);
    for(int a,b;E--;)
      scanInt(a), num[a]++,
      scanInt(b), num[b]++;
    int cnt=0;
    for(int i=1;i<=V;i++)
      if(num[i]&1)
        cnt++;
    puts( (cnt==0 or cnt==2)?"YES":"NO");
  }
}