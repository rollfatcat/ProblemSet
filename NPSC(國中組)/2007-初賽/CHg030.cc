// 算平均+比大小, 注意相除時的精確度問題
#include<iostream>
using namespace std;

int main(){
  int cnt, num[1000], n;

  while(cin>>n and n){
    double stand=0;
    for(int i=0;i<n;i++)
      cin>>num[i],  stand+=num[i];
    stand/=n;
    cnt=0;
    for(int i=0;i<n;i++)
      if(num[i]<stand)
        cnt++;
    cout<<cnt<<endl;
  }
}