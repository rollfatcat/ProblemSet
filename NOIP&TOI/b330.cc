#include<iostream>
using namespace std;

int main(){
  int n, x;
  while(cin>>n>>x){
    int cnt=0;
    for(int i=1;i<=n;i++)
      for(int num=i;num>0;num/=10)
        if(num%10==x)
          cnt++;
    cout<<cnt<<endl;
  }
}