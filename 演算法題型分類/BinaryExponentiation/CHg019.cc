// 利用Fib規則 做進位 => 抓規律超難...
// 1個bit為單位，同時利用連續兩個1必定不相連
#include<iostream>
using namespace std;
#define MaxNum 1005

int main(){
  string ss;
  int bit[MaxNum];
  while(cin>>ss){
    if(ss=="0")  break;
    // 處理輸入
    fill(bit,bit+MaxNum,0);
    for(int i=0;i<ss.length();i++)
      bit[i]+=(ss[i]-'0');
    // 根據每輸入一個bit就做相加和進位
    cin>>ss;
    for(int i=0;i<ss.length();i++)
      if(ss[i]-'0'){
        bit[i]+=1;
        if(bit[i]==1){
          if(bit[i+1])
            for(int j=i+1;bit[j];j+=2)
              bit[j+1]=1, bit[j]=bit[j-1]=0;
          else if(i>0 and bit[i-1])
            for(int j=i;bit[j];j+=2)
              bit[j+1]=1, bit[j]=bit[j-1]=0;
        }
        else if(bit[i]==2){
          bit[i+1]=1, bit[i]=0;
          bool keppToBound=true;
          for(int j=i-2;j>=0;j-=2){
            bit[j]+=1;
            if(bit[j]==1){
              keppToBound=false;
              if(j>0 and bit[j-1]==1)
                bit[j+1]=1 ,bit[j]=bit[j-1]=0;
              break;
            }
            // bit[j]==2
            bit[j+1]=1;
            bit[j]=0;
          }
          if(keppToBound){
            if(i%2) bit[2]=1, bit[1]=0, bit[0]=1;
            else  bit[1]=1, bit[0]=0;
          }
          for(int j=i+2;bit[j];j+=2)
            bit[j+1]=1, bit[j]=bit[j-1]=0;
        }
      }

    // 輸出
    int len=MaxNum-1;
    for( ;len>=0 and bit[len]==0; len--);
    for(int i=0;i<=len;i++)
      cout<<bit[i];
    cout<<endl;
  }
}
