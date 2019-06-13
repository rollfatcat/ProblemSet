#include<iostream>
using namespace std;
string ss;
int map[4][2]={ {1,2},{3,0},{0,3},{3,3} };
int DFS(int status,int idx){
  if(idx==ss.length())
    return status;
  return DFS(map[status][ ss[idx]-'0' ], idx+1);
}
int main(){
  int N;
  cin>>N;
  while(N--){
    cin>>ss;
    int status=DFS(0,0);
    if(status==0)
      cout<<"q0: Accept"<<endl;
    else
      cout<<"q"<<status<<": Reject"<<endl;
  }
}