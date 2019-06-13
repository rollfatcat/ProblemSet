#include<iostream>
#include<stack>
using namespace std;

int main(){
  int st[1000000];
  int T, Do;
  cin>>T;
  int len=0;
  while(T--){
    cin>>Do;
    switch(Do){
      case 1:
        if(len>0)
          len--;
        break;
      case 2:
        cout<<st[len-1]<<endl;
        break;
      case 3:
        cin>>st[len++];
        break;
      default:
        break;
    }
  }
}