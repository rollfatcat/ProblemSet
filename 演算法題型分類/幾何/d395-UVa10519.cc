// 先完成 a042 推導出公式解再做這題
// 輸入是大數的計算
#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  for(string Nss; cin>>Nss;){
    if(Nss=="0"){ puts("1"); continue; }
    vector<int> A,B,C;
    for(int i=Nss.length()-1;i>=0;i--)
      A.push_back(Nss[i]-'0');
    B=A,  B[0]-=1;
    for(int i=0;i<B.size() and B[i]<0;i++)
      B[i]+=10, B[i+1]-=1;
    if(B.back()==0) B.pop_back();
    C.assign(A.size()+B.size(),0);
    for(int i=0;i<A.size();i++)
      for(int j=0;j<B.size();j++)
        C[i+j]+=A[i]*B[j];
    int carry=2;
    for(int i=0;i<C.size();i++)
      C[i]+=carry, carry=C[i]/10, C[i]%=10;
    if(carry) C.push_back(carry);
    while(C.back()==0) C.pop_back();
    for(int i=C.size()-1;i>=0;i--)
      putchar(C[i]+'0');
    puts("");
  }
}