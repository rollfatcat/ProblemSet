#include<iostream>
using namespace std;
int SSToInt(string ss){
  int out=0;
  for(int i=0;i<ss.length();i++)
    out*=10,  out+=(ss[i]-'0');
  return out;
}
int main(){
  int N;
  cin>>N;
  while(N--){
    string ss,syb="";
    int num[100],numCnt=0;
    cin>>ss;
    ss+='+';
    // 將字串轉換成數字 但是運算符號
    for(int i=0;i<ss.length();i++){
      string tmp="";
      while(ss[i]>='0')
        tmp+=ss[i++];
      num[numCnt++]=SSToInt(tmp);
      syb+=ss[i];
    }
    int stkNum[100], stkLen=0;
    for(int i=0;i<syb.length();i++)
      if(syb[i]=='+')
        stkNum[stkLen++]=num[i];
      else
        num[i+1]*=num[i];
    int total=0;
    for(int i=0;i<stkLen;i++)
      total+=stkNum[i];
    cout<<total<<endl;
  }
}