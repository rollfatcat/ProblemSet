// 大數乘法和除法
#include<iostream>
#include<vector>
using namespace std;

vector<int> A,B,C,Bbase[10];
bool compare(int Ast,int Aed,int iB){
  if(Aed-Ast+1!=Bbase[iB].size())  return Aed-Ast+1>Bbase[iB].size();
  for(int i=Bbase[iB].size()-1;i>=0;i--)
    if(A[Ast+i]!=Bbase[iB][i])
      return A[Ast+i]>Bbase[iB][i];
  return true;
}
int main(){
  string ssA, ssB, op;
  Bbase[0].push_back(0);
  while(cin>>ssA>>op>>ssB){
    A.resize(ssA.length());
    for(int i=0;i<ssA.length();i++)
      A[ssA.length()-1-i]=ssA[i]-'0';
    B.resize(ssB.length());
    for(int i=0;i<ssB.length();i++)
      B[ssB.length()-1-i]=ssB[i]-'0';
    if(op=="*"){ //大數乘法
      C.assign(A.size()+B.size(),0);
      for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
          C[i+j]+=A[i]*B[j];
      for(int i=0,carry=0;i<C.size();i++)
        C[i]+=carry, carry=C[i]/10, C[i]%=10;
      if(!C.back()) C.pop_back();
      for(int i=C.size()-1;i>=0;i--)
        cout<<C[i];
      cout<<endl;
    } else { //大數除法
      if(ssA=="0"){ cout<<"0"<<endl; continue; }
      Bbase[1]=B;
      for(int idx=2;idx<=9;idx++){
        int carry=0; Bbase[idx]=B;
        for(int j=0;j<B.size();j++)
          Bbase[idx][j]=Bbase[idx][j]*idx+carry,
          carry=Bbase[idx][j]/10,
          Bbase[idx][j]%=10;
        if(carry) Bbase[idx].push_back(carry);
      }
      C.clear();
      int Ast=A.size()-B.size(), Aed=A.size()-1;
      if(!compare(Ast,Aed,1))  Ast--;
      for(int iB ; Ast>=0; Ast--){
        for(iB=1; iB<=9 and compare(Ast,Aed,iB); iB++);
        iB--, C.push_back(iB);
        for(int i=0;i<Bbase[iB].size();i++){
          A[Ast+i]-=Bbase[iB][i];
          if(A[Ast+i]<0)
            A[Ast+i]+=10, A[Ast+i+1]--;
        }
        while(Aed>=0 and !A[Aed] ) Aed--;
      }
      for(int i=0;i<C.size();i++)
        cout<<C[i];
      cout<<endl;
    }
  }
}
/*
1219416097850959788293446112635269
/
12346587987654321
*/
