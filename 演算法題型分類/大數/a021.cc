// 大數四則運算(加減乘除)
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
bool BigInt(string A,string B){ return (A.length()==B.length())?(A>=B):(A.length()>B.length()); }
int main(){
  string ssA, ssB, ssC, op;
  Bbase[0].push_back(0);
  while(cin>>ssA>>op>>ssB){
    bool swap=false;
    if(!BigInt(ssA,ssB)) ssC=ssA, ssA=ssB, ssB=ssC, swap=true;
    A.resize(ssA.length());
    for(int i=0;i<ssA.length();i++)
      A[ssA.length()-1-i]=ssA[i]-'0';
    B.resize(ssB.length());
    for(int i=0;i<ssB.length();i++)
      B[ssB.length()-1-i]=ssB[i]-'0';
    if(op=="+"){//大數加法
      int carry=0;
      for(int i=0;i<B.size();i++)
        A[i]+=(B[i]+carry), carry=A[i]/10, A[i]%=10;
      for(int i=B.size();i<A.size();i++)
        A[i]+=carry, carry=A[i]/10, A[i]%=10;
      if(carry) A.push_back(carry);
      for(int i=A.size()-1;i>=0;i--)
        cout<<A[i];
      cout<<endl;
    } else if(op=="-") { //大數減法
      if(swap)  cout<<"-";
      for(int i=0;i<B.size();i++){
        A[i]-=B[i];
        if(A[i]<0)
          A[i]+=10, A[i+1]--;
      }
      for(int i=B.size();i<A.size() and A[i]<0;i++)
        A[i]+=10, A[i+1]--;
      for(int i=A.size()-1; i>0 and A[i]==0; i--) A.pop_back();
      for(int i=A.size()-1;i>=0;i--)
        cout<<A[i];
      cout<<endl;
    } else if(op=="*") { //大數乘法
      if(ssB=="0"){ cout<<"0"<<endl; continue; }
      C.assign(A.size()+B.size(),0);
      for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
          C[i+j]+=A[i]*B[j];
      for(int i=0,carry=0;i<C.size();i++)
        C[i]+=carry, carry=C[i]/10, C[i]%=10;
      for(int i=C.size()-1; i>0 and C[i]==0; i--) C.pop_back();
      for(int i=C.size()-1;i>=0;i--)
        cout<<C[i];
      cout<<endl;
    } else { //大數除法
      if(swap){ cout<<"0"<<endl; continue; }
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