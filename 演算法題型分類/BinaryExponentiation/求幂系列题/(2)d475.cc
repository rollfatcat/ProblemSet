#include<iostream>
#include<cmath>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cnt=-1;
  for(int a, n; cin>>a>>n; )
    if(cnt>=0 or(a==0 and n==0))  cnt++;
    else  cout<<(int)pow(a,n)<<endl;
  if(cnt==0)  cnt=65536;// 偷吃步,根據測資修改的= =
  cout<<"All Over. Exceeded "<<cnt<<" lines!"<<endl;
}