#include<iostream>
using namespace std;

int main(void){
  int M, N, sum;
  int Max_Num[30], temp;
  int output[30], len;
  while(cin>>N>>M){
    sum=0;
    for(int i=0;i<N;i++){
      Max_Num[i]=0;
      for(int j=0;j<M;j++){
        cin>>temp;
        if(Max_Num[i]<temp)
          Max_Num[i]=temp;
      }
      sum+=Max_Num[i];
    }
    len=0;
    for(int i=0;i<N;i++)
      if(sum%Max_Num[i]==0)
        output[len++]=Max_Num[i];
    //
    cout<<sum<<endl;
    if(len>0)
      cout<<output[0];
    else
      cout<<-1;
    for(int i=1;i<len;i++)
      cout<<' '<<output[i];
    cout<<endl;
  }
}