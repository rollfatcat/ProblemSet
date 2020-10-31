#include<iostream>
#include<algorithm>
using namespace std;

struct card{
  short n;char ch;
  bool operator<(const card other)const{
    return (n==other.n)?(ch>other.ch):(n>other.n);
  }
}deck[52];
int main(){

  for(int N; cin>>N;){
    for(int i=0;i<N;i++)
      cin>>deck[i].ch>>deck[i].n;
    sort(deck,deck+N);
    cin>>N;
    cout<<deck[N-1].ch<<' '<<deck[N-1].n<<endl;
  }
}