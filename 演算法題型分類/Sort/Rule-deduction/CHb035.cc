#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 10000

int main(){
  long long int ans;
  int baby[MaxN], N;
  while(cin>>N){
    for(int i=0;i<N;i++)
      cin>>baby[i];
    sort(baby,baby+N);
    ans=0;
    for(int i=0;i<N;i++)
      ans+=baby[i]*(N-1-i);
    cout<<ans*100<<endl;
  }
}