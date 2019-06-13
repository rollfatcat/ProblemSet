#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, build_h, up, down;
  cin>>caseT;
  while(caseT--){
    cin>>build_h>>up>>down;
    if(build_h<=up) cout<<1<<endl;
    else if(up>down)cout<<ceil( (double)(build_h-up)/(up-down) )+1<<endl;
    else cout<<"Poor Snail"<<endl;
  }
}