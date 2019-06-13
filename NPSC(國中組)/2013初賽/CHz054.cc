#include<iostream>
#include<cstring>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  cin>>caseT;
  while(caseT--){
    bool success=true;
    string s1, s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++)
      if(s1[i]=='?'){
        if(s2[i]=='?'){
          success=false;
          break;
        }
        else
          s1[i]=s2[i];
      }
    if(success) cout<<"Yes:"<<s1<<'\n';
    else cout<<"No\n";
  }
}