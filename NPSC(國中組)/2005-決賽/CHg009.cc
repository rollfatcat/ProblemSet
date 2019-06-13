#include<iostream>
#include<vector>
using namespace std;

int main(){
  int m, n, C, R;
  string ss;

  while(cin>>m>>n>>C>>R){
    vector< vector<string> > monster(m);
    for(int i=0;i<m;i++)
      for(int j=0;j<R;j++)
        cin>>ss,  monster[i].push_back(ss);
    for(int iN=0; iN<n;iN++){
      vector<int> positive(m,0);
      vector<int> negative(m,0);
      for(int iR=0;iR<R;iR++){
        cin>>ss;
        for(int iC=0;iC<C;iC++)
          for(int iM=0;iM<m;iM++)
            if(monster[iM][iR][iC]!='-')
              (monster[iM][iR][iC]==ss[iC])?(positive[iM]++):(negative[iM]++);
      }
      int iM=0;
      for( ;iM<m;iM++)
        if(positive[iM]>=4*negative[iM]){
          cout<<'Y'<<endl;  break;
        }
      if(iM==m) cout<<'N'<<endl;
    }
  }
}