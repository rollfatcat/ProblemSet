#include<iostream>
using namespace std;

int main(){
  for(int N; cin>>N; ){
    int maxN=0;
    for(int x,nowN=0; N--; ){
      cin>>x;
      if(nowN<0)  nowN=0;
      nowN+=x;
      if(maxN<nowN) maxN=nowN;
    }
    cout<<maxN<<endl;
  }
}