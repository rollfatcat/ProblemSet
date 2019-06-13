// BubbleSort，計算交換次數
#include<iostream>
using namespace std;

int main(){
  for(int n,num[1000]; cin>>n;){
    for(int i=0;i<n;i++)
      cin>>num[i];
    int cnt=0;
    for(int i=1;i<n;i++)
      for(int j=i;j>0 and num[j]<num[j-1]; j--,cnt++)
        num[j]^=num[j-1]^=num[j]^=num[j-1];
    cout<<"Minimum exchange operations : "<<cnt<<endl;
  }
}