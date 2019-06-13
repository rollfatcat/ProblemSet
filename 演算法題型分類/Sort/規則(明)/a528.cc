// 大數(字串)排序
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 1002

bool Ncompare(string a, string b){ return (a.length()==b.length())?(a>b):(a.length()>b.length()); }
bool Pcompare(string a, string b){ return (a.length()==b.length())?(a<b):(a.length()<b.length()); }
int main(){
  string Pss[MaxN], Nss[MaxN], str;
  int N, Pnum, Nnum;

  while(cin>>N){
    Pnum=Nnum=0;
    for(int i=0;i<N;i++){
      cin>>str;
      if(str[0]=='-')
        Nss[Nnum++]=str;
      else
        Pss[Pnum++]=str;
    }
    sort(Nss,Nss+Nnum,Ncompare);
    sort(Pss,Pss+Pnum,Pcompare);
    for(int i=0;i<Nnum;i++)
      cout<<Nss[i]<<endl;
    for(int i=0;i<Pnum;i++)
      cout<<Pss[i]<<endl;
  }
}