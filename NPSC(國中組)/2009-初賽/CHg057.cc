// 簡單題
#include<iostream>
using namespace std;

int LifeNumber(int x){
  for(int nxt;x>=10;x=nxt)
    for(nxt=0; x; x/=10)
      nxt+=(x%10);
  return x;
}
int main(){
  int caseNum, x;

  cin>>caseNum;
  while(caseNum--){
    cin>>x, x=LifeNumber(x),
    cout<<x<<", "<<((x==2)?"Yes":"No")<<endl;
  }
}