// 如何定義"Cover"再寫
#include<iostream>
using namespace std;

int main(){
  int T,N;
  char ch;

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  cin>>T;
  for(int caseNum=1; caseNum<=T; caseNum++){
    cin>>N;
    int cnt=0, pos=-1;
    for(int i=0;i<N;i++){
      cin>>ch;
      if(ch=='.' and i>pos)
        cnt++, pos=i+2;
    }
    cout<<"Case "<<caseNum<<": "<<cnt<<endl;
  }
}