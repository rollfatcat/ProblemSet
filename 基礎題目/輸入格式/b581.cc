#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  string line;
  int caseT, num;
  cin>>caseT>>ws;
  while(caseT-- and getline(cin,line)){
    long sum=0;
    stringstream ss(line);
    while(ss>>num)
      sum+=num;
    cout<<sum<<'\n';
  }
}