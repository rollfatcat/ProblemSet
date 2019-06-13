#include<iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for(int L, R; cin>>L>>R;){
    int cnt=0;
    for(int i=L;i<=R;i++)
      for(int n=i;n>0;n/=10)
        if(n%10==2)
          cnt++;
    cout<<cnt<<endl;
  }
}