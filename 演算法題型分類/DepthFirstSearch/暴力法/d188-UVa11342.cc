#include<iostream>
#include<vector>
using namespace std;
#define SQU(a) a*a

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> num[50001];
  for(int i=0; 3*SQU(i)<=50000;i++){
    for(int j=i; SQU(i)+2*SQU(j)<=50000;j++){
      for(int k=j; true;k++){
        int n=SQU(i)+SQU(j)+SQU(k);
        if(n>50000) break;
        if(!num[n].size())
        num[n].push_back(i),
        num[n].push_back(j),
        num[n].push_back(k);
      }
    }
  }
  int T, n;
  for(cin>>T;T--;){
    cin>>n;
    if(num[n].size()) cout<<num[n][0]<<' '<<num[n][1]<<' '<<num[n][2]<<endl;
    else  cout<<-1<<endl;
  }
}