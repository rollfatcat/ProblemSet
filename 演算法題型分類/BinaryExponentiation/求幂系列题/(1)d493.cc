// 題目沒有保證 0≤n, 所以快速乘方法並不適用
#include<iostream>
#include<cmath>
using namespace std;

int main(){

  for(long a, b, n; cin>>a>>n; )
    cout<<(long)pow(a,n)<<endl;
}