// 不做TD的話是2.7s, 用陣列存會縮短到16ms
// 解法：N is prime or 4, MinStep=N, way=1(except for 4)
// 質因數分解, MinStep+=底數*次方項
// way=TD(x)
#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
// sqrt(2147483647)<46350, CV.size()=4794

bool isCV[46351]={0};
vector<int> CV, base, power;
map<int,int> fac;
int N, facNum;

bool IsCV(int x){
  if(x<=46350)  return (isCV[x]==0);
  int idx=0;  for(;idx<4794 and x%CV[idx];idx++);
  return (idx==4794);
}
void DFS(int r, int mul){
  if(r==facNum)  return;
  DFS(r+1,mul);
  for(int i=1; i<=power[r]; i++)
    mul*=base[r], fac[mul]=1, DFS(r+1,mul);
}
int TD(int x){
  for(int i=0;i<facNum;i++) //如果是底數就回傳1
    if(x==base[i])
      return 1;
  if(fac[x]==1){ //如果沒算過就展開去算
    fac[x]=(x%4==0)?TD(x/4):0;
    for(int i=0;i<facNum;i++)
      if(x%base[i]==0)
        fac[x]+=TD(x/base[i]);
  }
  return fac[x];
}
int main(){
  // 產生質數表, 找出小於46350的質數
  for(int i=2;i<=sqrt(46350);i++)
    if(isCV[i]==0)
      for(int j=2;i*j<=46350;j++)
        isCV[i*j]=1;
  isCV[4]=0;
  for(int i=2;i<=46350;i++)
    if(isCV[i]==0)
      CV.push_back(i);
  //
  while(cin>>N){
    if(IsCV(N)){  cout<<"min : "<<N<<endl<<"way : "<<((N==4)?2:1)<<endl;  continue; }
    base.clear(); power.clear();
    int num=N, p;
    for(int i=0;i<4794 and num>1;i++)
      if(num%CV[i]==0){
        base.push_back(CV[i]);
        for(p=0;num%CV[i]==0;num/=CV[i])  p++;
        power.push_back(p);
      }
    if(num>1) base.push_back(num),  power.push_back(1);
    int MinStep=0;
    facNum=base.size();
    for(int i=0;i<facNum;i++)
      MinStep+=base[i]*power[i];
    //
    fac.clear();
    DFS(0,1);
    if(N%4==0)  fac[4]=2;
    TD(N);
    cout<<"min : "<<MinStep<<endl<<"way : "<<fac.rbegin()->second<<endl;
  }
}