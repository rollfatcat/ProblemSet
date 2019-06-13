// 二分搜尋+費波那契數列
#include<iostream>
#include<vector>
using namespace std;

vector<int> fib;
int BS(int x){
  int l=0, r=fib.size()-1, m;
  while(l<=r){
    m=(l+r)/2;
    if(fib[m]==x) return m;
    else if(fib[m]>x) r=m-1;
    else l=m+1;
  }
  return l;
}
int main(){
  fib.push_back(0), fib.push_back(1);
  for(int i=2; fib.back()<=1000000; i++)
    fib.push_back( fib[i-1]+fib[i-2] );
  int t, Lnum, Rnum, x;
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

  for(cin>>t; t--; ){
    cin>>Lnum>>Rnum;
    if(Rnum<Lnum) x=Rnum, Rnum=Lnum, Lnum=x;
    int l=BS(Lnum), r=BS(Rnum), cnt=r-l;
    for(int i=l;i<r;i++)
      cout<<fib[i]<<endl;
    if(fib[r]==Rnum)
      cout<<Rnum<<endl, cnt++;
    cout<<cnt<<endl;
    if(t) cout<<"------"<<endl;
  }
}