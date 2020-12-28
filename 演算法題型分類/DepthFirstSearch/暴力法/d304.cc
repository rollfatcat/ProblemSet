// DFS暴搜：3.8s, 但實際上是有規律可循的請參照 d741 的加強版
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, Mintimes;
char sym[2]={'C','V'};
vector< vector<bool> > ans;
vector<bool>op;

bool compare(vector<bool>a, vector<bool>b){
  for(int i=0;i<a.size();i++)
    if(a[i]!=b[i])
      return a[i]<b[i];
}
void DFS(int Done, int Store, int times){
  if(Done==N){
    if(times<Mintimes){
      Mintimes=times;
      ans.clear();
      ans.push_back(op);
    }
    else if(times==Mintimes)
      ans.push_back(op);
  }
  if(Done>=N or Store>=N or times>=Mintimes) return;
  // 選擇 Ctrl C, 不應該會有連續兩個C, 沒意義
  if(Done!=Store){
    op.push_back(0);
    DFS(Done,Done,times+1);
    op.pop_back();
  }
  // 選擇 Ctrl V
  op.push_back(1);
  DFS(Done+Store,Store,times+1);
  op.pop_back();
}
int main(){
  while(cin>>N){
    Mintimes=0x7fffffff;
    ans.clear();
    DFS(2,1,2);
    // Output
    cout<<"min : "<<Mintimes<<"\nway : "<<ans.size()<<endl;
    sort(ans.begin(),ans.end(),compare);
    for(int i=0;i<ans.size();i++){
      cout<<"Ctrl C + V";
      for(int j=0;j<ans[i].size();j++)
        cout<<" + "<<sym[ans[i][j]];
      cout<<endl;
    }
  }
}