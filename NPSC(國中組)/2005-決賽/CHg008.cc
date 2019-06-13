// 任意連續區段內的組合長度
#include<iostream>
#include<cstring>
using namespace std;

int cnt, maxL, DP[20][20];
int main(){
  while(cin>>cnt and cnt){
    memset(DP,0,sizeof(DP));  maxL=0;
    for(int i=0;i<cnt;i++)
      cin>>DP[i][i],  maxL+=DP[i][i];
    if(cnt==maxL or maxL>cnt*cnt){  cout<<"NO"<<endl; continue; }
    bool isIn[maxL+1];
    memset(isIn,0,sizeof(isIn));
    for(int i=0;i<cnt;i++){
      isIn[DP[i][i]]=1;
      for(int j=i+1;j<cnt;j++)
        DP[i][j]=DP[i][j-1]+DP[j][j],
        isIn[DP[i][j]]=1;
    }
    int idx=1;
    for(;idx<=maxL and isIn[idx];idx++);
    if(idx==maxL+1) cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
  }
}