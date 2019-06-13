#include<iostream>
using namespace std;
int main(){
  int N;
  while(cin>>N && N){
    int cost=0, pre, nxt, tmp;
    cin>>pre;
    for(int i=1; i<N; pre=nxt,i++){
      cin>>nxt;
      tmp=pre-nxt;
      cost+=( (tmp>0)?(10*tmp):(-20*tmp) );
    }
    cout<<cost<<endl;
  }
}
