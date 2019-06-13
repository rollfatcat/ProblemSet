// 根據位置反推現在是第幾天
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(long pos; cin>>pos; )
    cout<<((pos>0)?2*pos-1:-2*pos)<<'\n';
}