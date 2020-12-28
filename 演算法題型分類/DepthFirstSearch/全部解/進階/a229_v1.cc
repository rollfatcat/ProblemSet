// DFS暴力法+加速輸入=> 0.9s
// TLE的問題出在 cout<<endl, 換成"\n" 就變0.3s...
#include<iostream>
using namespace std;

int N;
string Rss[14]={
  "",")","))",")))","))))",")))))","))))))",")))))))","))))))))",")))))))))",
  "))))))))))",")))))))))))","))))))))))))",")))))))))))))"};
void DFS(int Ln,int Rn,string ss){
  if(Ln<Rn) return;
  if(Ln==N){  cout<<ss+Rss[Ln-Rn]<<"\n"; return;  }
  DFS(Ln+1,Rn,ss+'(');
  DFS(Ln,Rn+1,ss+')');
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  while(cin>>N)
    DFS(0,0,"");
}