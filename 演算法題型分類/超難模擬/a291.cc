// 數字會重複導致算比對時還要考慮這個位置的數字用過了沒有...
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int ans[4];
  int gue[4], n;
  bool use[2][4];

  while(cin>>ans[0]){
    cin>>ans[1]>>ans[2]>>ans[3]>>n;
    while(n--){
      cin>>gue[0]>>gue[1]>>gue[2]>>gue[3];
      int A=0, B=0;
      memset(use,0,sizeof(use));
      for(int i=0;i<4;i++)
        if(gue[i]==ans[i]){
          use[0][i]=use[1][i]=1;
          A++;
        }
      for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
          if(i!=j and use[1][i]==0 and use[0][j]==0 and gue[i]==ans[j]){
            use[1][i]=use[0][j]=1;
            B++;
            break;
          }
      }
      cout<<A<<'A'<<B<<'B'<<endl;
    }
  }
}