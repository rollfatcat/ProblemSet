// 最大連續區間(至少選擇一個數)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int main(){
  int N, x;
  cin>>N>>x;
  int submax=x;
  int cotmax=x;
  for(int i=1;i<N;i++)
    cin>>x,
    cotmax=(cotmax<0)?x: cotmax+x,
    submax=max(cotmax,submax);
  cout<<submax<<endl;
}