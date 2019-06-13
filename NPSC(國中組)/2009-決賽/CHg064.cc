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
    string ss;
    cin>>ss;
    int stk[100], stkLen=0;
    bool flag=false;
    for(int i=0;i<ss.length();i++){
      if(ss[i]>='0'){
        string tmp="";
        while(ss[i]>='0')
          tmp+=ss[i++];
        stk[stkLen++]=SSToInt(tmp);
      }
      if(ss[i]==')'){
        if(stk[stkLen-1]==stk[stkLen-2])
          stk[stkLen-2]*=2, stkLen--;
        else{
          flag=true;
          break;
        }
      }
    }
    //
    if(flag)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  }
}
