#include<iostream>
#include<cmath>
using namespace std;

int Len=7000;
bool N[7000]={};
int SUM[7000]={};
void SetArr(){
  for(int i=0;i<Len;i++){
    N[i]=1;
    SUM[i]=0;
  }
}
void Prime(){
  N[0]=N[1]=0;
  for(int i=2;i<pow(Len,0.5);i++){
    if(N[i]!=0){
      for(int j=2;j*i<Len;j++){
        N[j*i]=0;
      }
    }
  }
}
void SetSUM(){
  SUM[0]=0;
  for(int i=1;i<=Len;i++){
    SUM[i]=SUM[i-1]+( (!N[i])?i:0 );
  }
}
int main(){
  SetArr();
  Prime();
  SetSUM();
  int k=0;
  cin>>k;
  while(k--){
    int n,m;
    cin>>n>>m;
    cout<<SUM[m]-SUM[n-1]<<endl;
    //cout<<SUM[n]<<" "<<SUM[m];
  }
  // SUM[x]=1+..+x
  // 4 6 => SUM[6]-SUM[4-1]
}