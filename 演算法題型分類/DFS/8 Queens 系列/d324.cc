// 8 Queens 排序以column為順序的DFS
#include<iostream>
#include<vector>
using namespace std;

int cnt=0;
int pos_y[8], map[92][8];
bool Lslash[17]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool Rslash[17]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool col[8]={1,1,1,1,1,1,1,1};
bool *ls=&Lslash[0];  // /  範圍變化：x+y =  0 ~ 16
bool *rs=&Rslash[8];  // \  範圍變化：x-y = -8 ~  8
void DFS(int x){
  if(x==8){
    for(int i=0;i<8;i++)
      map[cnt][i]=pos_y[i];
    cnt++;
    return;
  }
  for(int i=0;i<8;i++)
    if(col[i] and ls[x+i] and rs[x-i]){
      pos_y[x]=i+1;
      ls[x+i]=rs[x-i]=col[i]=false;
      DFS(x+1);
      ls[x+i]=rs[x-i]=col[i]=true;
    }
}
int main(){
  int T, a, b;
  // 先產生八皇后的92種答案
  DFS(0);
  cin>>T;
  for(int caseN=0; caseN<T; caseN++){
    vector<int> ans;
    cin>>a>>b;
    b--;
    int total=0;
    for(int t=0;t<cnt;t++)
      if(map[t][b]==a)
        ans.push_back(t);
    cout<<"SOLN       COLUMN"<<endl;
    cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
    for(int i=0;i<ans.size();i++){
      printf("%2d     ",i+1);
      for(int j=0;j<8;j++)
        printf(" %d",map[ ans[i] ][j]);
      printf("\n");
    }
    if(caseN!=T-1)
      printf("\n");
  }
}