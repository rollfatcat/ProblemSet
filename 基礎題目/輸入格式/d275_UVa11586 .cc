#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string ssline, word;
  int caseT;
  cin>>caseT>>ws;
  while(caseT--){
    getline(cin,ssline);
    stringstream ss(ssline);
    map<string,int> memo;
    while(ss>>word)
      memo[word]++;
    /* Special Case："FF"="MM"=0 and ("MF"=1 or "FM"=1)
     */
    if(memo["MM"]!=memo["FF"] or memo["MM"]==0 and memo["FF"]==0 and (memo["MF"]==1 or memo["FM"]==1))
      cout<<"NO ";
    cout<<"LOOP\n";
  }
}