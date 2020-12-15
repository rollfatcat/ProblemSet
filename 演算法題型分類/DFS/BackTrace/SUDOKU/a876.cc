// 類似數獨的模擬填空題, 實作是8ms但基於判斷運算符號會一直重複發生所以最佳的0ms應該是可行的
// DFS+Cut-Branch
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MaxN 9

int n, m, N;
int PosToBlock[MaxN][MaxN]; //位置映射到Block ID
int map[MaxN][MaxN];
bool row[MaxN][MaxN+1]; // <- 這可以用狀態壓縮改善找到下一個『沒用過』的數字
bool col[MaxN][MaxN+1];
struct Block{
  int t, cnt, other;  char c;
  bool CheckNum(int num){
    if(cnt==1){
      if(c=='-')  return (other-num==t)or(num-other==t);
      if(c=='/')  return (t==other*num)or(t*other==num);
      return t==num;
    }
    if(c=='+'){ if(t>num){ t-=num; return true; } return false; }
    if(c=='x'){ if(t%num) return false;  t/=num; return true; }
    other=num; return true;
  };
  void Back(int num){
    cnt++;
    if(cnt==1)  return;
    if(c=='+') t+=num;
    if(c=='x') t*=num;
    return ;
  };
}now;
vector<Block> order;
bool HasAns;
void DFS(int r, int c){
  if(c==n){  c=0, r++; }
  if(r==n){  HasAns=true; return; }
  int pos=PosToBlock[r][c];
  for(int i=1;i<=n;i++)
    if(!row[r][i] and !col[c][i] and order[pos].CheckNum(i)){
      map[r][c]=i,
      row[r][i]=col[c][i]=1,  order[pos].cnt--;
      DFS(r,c+1);
      if(HasAns==true)  return;
      row[r][i]=col[c][i]=0,  order[pos].Back(i);
    }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  while(cin>>n>>m){
    N=n*n;
    order.clear();
    for(int i=0, cnt;i<m;i++){
      cin>>now.t>>now.c>>now.cnt, order.push_back(now);
      for(int j=0,num; j<now.cnt; j++)
        cin>>num, num--, PosToBlock[num/n][num%n]=i;
    }
    HasAns=false;
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    DFS(0,0);
    //
    for(int i=0;i<n;i++,cout<<'\n')
      for(int j=0;j<n;j++)
        cout<<map[i][j]<<' ';
  }
}