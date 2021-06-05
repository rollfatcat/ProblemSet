// 以數字為單位考量, 非二項展開的寫法：1.5s
// 不用 to_string(int) 可以讓時間縮減到 1s
// 但是前幾名的時間都是0.1s～0.3s 不確定有沒有剪枝？
#include<iostream>
#include<cmath>
using namespace std;

int n;
bool noAns;
string numToss[29]={"0","1","2","3","4","5","6","7","8","9",
                    "10","11","12","13","14","15","16","17","18","19",
                    "20","21","22","23","24","25","26","27","28"};
void DFS(string ss, int score, int now){
  if(score==n)  noAns=false,  cout<<ss<<'\n';
  if(score>=n)  return;
  ss+=(" + "+numToss[now]);
  DFS(ss,score+now,now+1);
  for(int i=2*(score+now);i<=n;i*=2)
    ss+=" * 2", DFS(ss,i,now+1);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>n and n){
    noAns=true;
    string ss="1";
    DFS(ss,1,2);
    for(int i=2;i<=n;i*=2)
      ss+=" * 2", DFS(ss,i,2);
    if(noAns)
      cout<<"cheat!\n";
  }
}