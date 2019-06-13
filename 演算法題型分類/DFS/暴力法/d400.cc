// 暴力解DFS, 填滿背包時再檢查有沒有符合規格
// 簡單優化：填字母時順便記錄該字母在背包的位置, 檢查規格時就能省時, 注意還原時位置的重置
//
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define MaxN 11

int cnt, m, n;
string ss;
struct Node{ int a, b; };
vector<Node> bound;
int pos[26];
bool vis[MaxN];
char bag[MaxN];

bool cmp(char a, char b){ return a<b; }
void DFS(int deep){
  if(cnt>10)  return;
  if(deep==n){
    int i=0;
    while(i<m and pos[ bound[i].a ]<pos[ bound[i].b ]) i++;
    if(i==m)
      cout<<bag<<endl, cnt++;
    return;
  }
  char last='\0';
  for(int i=0;i<n;i++)
    if(vis[i]==0 and last!=ss[i]){
        bag[deep]=ss[i], last=ss[i];
        if(pos[ ss[i]-'a' ]==-1) pos[ ss[i]-'a' ]=deep;
        vis[i]=1;
        DFS(deep+1);
        if(cnt>10)  return;
        if(pos[ ss[i]-'a' ]==deep) pos[ ss[i]-'a' ]=-1;
        vis[i]=0;
    }
}
int main(){
  int T;
  char a, b;

  cin>>T;
  while(T--){
    cin>>ss>>m;
    n=ss.length();
    sort(ss.begin(),ss.end(),cmp);

    bound.clear();
    for(int i=0;i<m;i++)
      cin>>a>>b,  bound.push_back({a-'a',b-'a'});

    memset(vis,0,sizeof(vis));
    memset(pos,0xff,sizeof(pos));
    cnt=0;
    bag[n]='\0';
    DFS(0);
    if(cnt==0)  cout<<"NANJ你唬我\n";
  }
}