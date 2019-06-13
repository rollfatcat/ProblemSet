#include<iostream>
using namespace std;
int main(){
  int T;
  cin>>T;
  while(T--){
    string ss;
    cin>>ss;
    int sslen=ss.length();
    bool flag=true;
    for(int i=0; i<sslen/2; i++)
      if(ss[i]!=ss[sslen-1-i]){
        flag=false;
        break;
      }
    if(flag)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
}