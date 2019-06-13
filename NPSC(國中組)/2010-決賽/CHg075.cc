#include<iostream>
using namespace std;

int T, N, x;
int a[7], *num=&a[3];
void Merge(int a, int b){
  x=min(num[a],num[b]);
  num[a]-=x;  num[b]-=x;  num[a+b]+=x;
}

int main(){
  cin>>T;
  while(T--){
    cin>>N;
    fill(a,a+7,0);
    int total=0;
    while(N--)
      cin>>x, num[x]++, total+=x;
      if(total>3 or total<0){
          cout<<"NO"<<endl;
      continue;
      }
    //
    Merge(3,-3);
    Merge(2,-1);
    Merge(-3,1);
    if(num[-3]>0){
      cout<<"NO"<<endl;
      continue;
    }
    // num[-3]==0的前提下才會繼續
    Merge(-2,1);
    Merge(3,-1);
    if(num[3]>1)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }
}