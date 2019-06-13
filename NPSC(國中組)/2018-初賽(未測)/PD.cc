// 簡單代數問題，注意測資範圍是1e15
#include<iostream>
using namespace std;

int main(){
  long long n[9];
  for(int i=0;i<9;i++)
    cin>>n[i];
  long long side=(n[0]+n[2]+n[3]+n[5]+n[6]+n[8])>>1;
  cout<<(n[0]+n[1]+n[2]-side)<<endl;
}