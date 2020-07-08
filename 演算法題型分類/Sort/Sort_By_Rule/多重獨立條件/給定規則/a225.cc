#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b){ return (a%10!=b%10)?(a%10<b%10):(a>b); }
int main(){
  int num[1000];
  int n;
  while(cin>>n){
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num, num+n, compare);
    for(int i=0; i<n; i++)
      cout<<num[i]<<" ";
    cout<<endl;
  }
}