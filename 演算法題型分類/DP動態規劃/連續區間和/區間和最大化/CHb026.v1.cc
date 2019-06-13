#include<iostream>
using namespace std;

int main(){
  int N;

  while(cin>>N){
    int max=0, sum=0, x;
    for(int i=0;i<N;i++){
      cin>>x;
      sum+=x;
      if(max<sum)
        max=sum;
      if(sum<0)
        sum=0;
    }
    cout<<max<<endl;
  }
}