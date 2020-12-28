#include<iostream>
using namespace std;

int N, M;
string ans;
void DFS(int idx){
  if(idx==N){
    cout<<ans<<endl; return;
  }
  for(int i=0;i<=M;i++){
    ans+=char(i+'0');
    DFS(idx+1);
    ans=ans.substr(0,ans.length()-1);
  }
}
int main(){
  cin>>N>>M;
  ans="";
  DFS(0);
}