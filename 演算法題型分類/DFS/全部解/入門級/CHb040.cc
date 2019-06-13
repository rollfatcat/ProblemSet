// 因為要找到所有的解法, 所以要透過TD
#include<iostream>
#include<vector>
using namespace std;
#define MaxNum 20

int N, M ,v[MaxNum];
vector< vector<int> > ans;
vector<int>bag;
void DFS(int now,int rem){
  if(rem==0)
    ans.push_back(bag);
  if(rem<=0)
    return;
  for(int i=now;i<N;i++){
    bag.push_back(v[i]);
    DFS(i,rem-v[i]);
    bag.pop_back();
  }
}
int main(){
  cin>>N>>M;
  for(int i=0;i<N;i++)
    cin>>v[i];
  //
  ans.clear();
  DFS(0,M);
  if(ans.size()==0)
    cout<<"NO"<<endl;
  else
    for(int i=0;i<ans.size();i++){
      cout<<ans[i][0];
      for(int j=1;j<ans[i].size();j++)
        cout<<' '<<ans[i][j];
      cout<<endl;
    }
}