// 題目說的不超出整數範圍指的是高度(H), 不是n
// h*(h+1)/2 >= n, 找到最小的整數h
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  for(unsigned long long int n; cin>>n; )
    cout<<(long)ceil(sqrt(2*n)-0.5)<<endl;
}