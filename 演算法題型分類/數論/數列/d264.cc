// 數論變形題(不知道規律時利用暴力法找出規律)
/* 題解：https://home.gamer.com.tw/creationDetail.php?sn=4111948
 */
#include<iostream>
#include<vector>
using namespace std;

vector<long> fibonacci;
int BS(int x){
  int l=0,r=fibonacci.size()-1;
  while(l<=r){
    int m=(l+r)>>1;
    if(fibonacci[m]==x) return m;
    else if(fibonacci[m]>x) r=m-1;
    else l=m+1;
  }
  return r;
}
int main(){
  fibonacci.push_back(1),
  fibonacci.push_back(1),
  fibonacci.push_back(2);
  for(int i=3; fibonacci.back()>0; i++)
    fibonacci.push_back(fibonacci[i-2]+fibonacci[i-1]);
  fibonacci.back()=0x7fffffff;
  for(int x; cin>>x; )
    x=BS(x), cout<<fibonacci[x-1]<<' '<<fibonacci[x]<<endl;
}