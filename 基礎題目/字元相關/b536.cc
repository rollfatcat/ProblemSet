// 問題出在：如何處理不同格式 => 撈出所有的數字並根據數量套用不同檢查方式
// 類似身分證檢查碼，但是輸入格式不固定
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  string Check1=" 123456789X0";
  string Check2=" 1234567890";
  char ss[20];
  int N, num, i,j;

  for(cin>>N; N--; ){
    scanf("%s",ss);
    int L=0,cnt[13]={};
    for(int i=0;i<strlen(ss);i++){
      int x=ss[i]-'0';
      if(x>=0)  cnt[L++]=x;
    }
    if(L==10){
      for(num=i=0,j=10;j>1;i++,j--)
        num+=cnt[i]*j;
      cout<<( (Check1[11-num%11]==cnt[9]+'0')?'T':'F' )<<endl;
    } else {
      int val[2]={1,3};
      for(num=i=0;i<12;i++)
        num+=cnt[i]*val[i%2];
      cout<<( (Check2[10-num%10]==cnt[12]+'0')?'T':'F' )<<endl;
    }
  }
}