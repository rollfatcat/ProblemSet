// DFS 窮舉所有的組合，最後輸出第一組符合校正的答案即可
#include<iostream>
using namespace std;

int check[6][7], bag[6], N=6;
bool hasAns=0, use[6];
void DFS(int deep){
  if(deep==N){
    bool checkAns=1;
    for(int i=0;i<6 and checkAns;i++){
      int cnt=0;
      for(int j=0;j<6;j++)
        if(bag[j]==check[i][j])
          cnt++;
      checkAns &=(cnt==check[i][6]);
    }
    if(checkAns)
      cout<<bag[0]<<' '<<bag[1]<<' '<<bag[2]<<' '<<bag[3]<<' '<<bag[4]<<' '<<bag[5]<<endl,
      hasAns=1;
    return;
  }
  for(int i=0;i<6;i++)
    if(!use[i]){
      bag[deep]=i+1, use[i]=1;
      DFS(deep+1);
      if(hasAns)  return;
      use[i]=0;
    }
}
int main(){
  for(int i=0;i<6;i++)
    for(int j=0;j<7;j++)
      cin>>check[i][j];
  DFS(0);
}