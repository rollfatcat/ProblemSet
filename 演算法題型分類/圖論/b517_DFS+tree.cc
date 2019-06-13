// 測資讀取很麻煩
// Tree的架構介紹
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MaxN 81

vector<int>node[MaxN];
bool vis[MaxN];
void DFS(int now){
  vis[now]=true;
  for(int i=0;i<node[now].size();i++)
    if(!vis[ node[now][i] ])
      DFS(node[now][i]);
}

int main(){
  int T, a, b, eNum;
  string ss;
  //cout<<int(',')<<' '<<int(' ')<<endl;
  cin>>T;
  getchar();
  while(T--){
    for(int i=0;i<=MaxN;i++)
      node[i].clear();
    eNum=0;

    getline(cin,ss);
    for(int i=0; i<ss.length(); i++){
      if(ss[i]>='0'){
        eNum++;
        a=ss[i++]-'0';
        while(ss[i]>='0')
          a=a*10+(ss[i++]-'0');
        i++;
        b=ss[i++]-'0';
        while(i<ss.length() and ss[i]>='0')
          b=b*10+(ss[i++]-'0');
        //cout<<a<<','<<b<<'|'<<i<<endl;
        node[a].push_back(b);
        node[b].push_back(a);
      }
    }
    int nNum=0;
    for(int i=0;i<=MaxN;i++)
      nNum+=(node[i].size()>0);
    if(eNum==nNum-1){
      fill(vis,vis+MaxN+1,false);
      int idx=0;
      while(node[idx].size()==0)  idx++;
      DFS(idx++);
      while(idx<=MaxN and (vis[idx] or node[idx].size()==0) ) idx++;
      if(idx==MaxN+1){
        cout<<'T'<<endl;
        continue;
      }
    }
    cout<<'F'<<endl;

  }
}