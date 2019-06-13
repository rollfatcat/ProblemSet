#include<iostream>
using namespace std;

int main(){
  int T, N;

  cin>>T;
  while(T--){
    cin>>N;
    int max=-10000, sum=0, x;
    for(int i=0;i<N;i++){
      if(sum<0)
        sum=0;
      cin>>x;
      sum+=x;
      if(max<sum)
        max=sum;
    }
    cout<<max<<endl;
  }
}