#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int w, n;
  int num[30000];

  while(cin>>w>>n){
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num,num+n);
    int cnt=0;
    for(int front=0, back=n-1;front<=back;cnt++,back--)
      if(num[front]+num[back]<=w)
        front++;
    cout<<cnt<<endl;
  }
}