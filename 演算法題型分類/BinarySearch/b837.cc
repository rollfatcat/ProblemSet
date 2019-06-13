// 建表連續區間查巡：76ms/4.2MB
#include<iostream>
#include<vector>
using namespace std;

vector<int> fib;
vector<int> pos(1000001,0);
int main(){
  fib.push_back(0), fib.push_back(1);
  for(int i=2; fib.back()<=1000000; i++)
    fib.push_back( fib[i-1]+fib[i-2] );
  int t, Lnum, Rnum, x;
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int i, j;
  pos[0]=0, pos[1]=1, pos[2]=3;
  for(i=4; i<fib.size()-1; i++)
    for(j=fib[i-1]+1; j<=fib[i]; j++)
      pos[j]=i;
  for(j=fib[i-1]+1; j<=1000000; j++)
    pos[j]=i;
  for(cin>>t; t--; ){
    cin>>Lnum>>Rnum;
    if(Rnum<Lnum) x=Rnum, Rnum=Lnum, Lnum=x;
    int l=pos[Lnum], r=pos[Rnum], cnt=r-l;
    for(int i=l;i<r;i++)
      cout<<fib[i]<<endl;
    if(fib[r]==Rnum)
      cout<<Rnum<<endl, cnt++;
    cout<<cnt<<endl;
    if(t) cout<<"------"<<endl;
  }
}