#include<iostream>
using namespace std;

int main(){
  int n, sum, max, num;
  while(cin>>n and n){
    sum=max=0;
    while(n--){
      cin>>num;
      sum+=num;
      if(max<sum) max=sum;
      if(sum<0) sum=0;
    }
    if(max>0)
      cout<<"The maximum winning streak is "<<max<<".\n";
    else
      cout<<"Losing streak.\n";
  }
}