// 小數版本的大數加法：對齊小數點後分成整數和小數兩部分處理
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
  string ssA, ssB, ans="";
  cin>>ssA>>ssB;
  int fixA=ssA.find('.'), fixB=ssB.find('.');
  if(fixA==-1) fixA=ssA.length();
  if(fixB==-1) fixB=ssB.length();
  vector<int> numA, numB;
  // 小數
  for(int i=fixA+1;i<ssA.length();i++)
    numA.push_back(ssA[i]-'0');
  for(int i=fixB+1;i<ssB.length();i++)
    numB.push_back(ssB[i]-'0');
  int carry=0;
  if(ssA.length()-fixA>=ssB.length()-fixB){
    for(int i=ssB.length()-fixB-1;i>=0;i--)
      numA[i]+=(numB[i]+carry), carry=numA[i]/7, numA[i]%=7;
    int end=ssA.length()-fixA-1;
    while(end>=0 and !numA[end]) end--;
    if(end>=0) ans=".";
    for(int i=0;i<=end;i++)
      ans+=(char)(numA[i]+'0');
  }else{
    for(int i=ssA.length()-fixA-1;i>=0;i--)
      numB[i]+=(numA[i]+carry), carry=numB[i]/7, numB[i]%=7;
    int end=ssB.length()-fixB-1;
    while(end>=0 and !numB[end]) end--;
    if(end>=0) ans=".";
    for(int i=0;i<=end;i++)
      ans+=(char)(numB[i]+'0');
  }
  // 整數
  numA.clear();
  for(int i=fixA-1;i>=0;i--)
    numA.push_back(ssA[i]-'0');
  numB.clear();
  for(int i=fixB-1;i>=0;i--)
    numB.push_back(ssB[i]-'0');
  if(fixA>=fixB){
    for(int i=0;i<fixB;i++)
      numA[i]+=(numB[i]+carry), carry=numA[i]/7, numA[i]%=7, ans=(char)(numA[i]+'0')+ans;
    for(int i=fixB;i<fixA;i++)
      numA[i]+=carry, carry=numA[i]/7, numA[i]%=7, ans=(char)(numA[i]+'0')+ans;
    if(carry) numA.push_back(carry), ans=(char)(numA.back()+'0')+ans;
  }else{
    for(int i=0;i<fixA;i++)
      numB[i]+=(numA[i]+carry), carry=numB[i]/7, numB[i]%=7, ans=(char)(numB[i]+'0')+ans;
    for(int i=fixA;i<fixB;i++)
      numB[i]+=carry, carry=numB[i]/7, numB[i]%=7, ans=(char)(numB[i]+'0')+ans;
    if(carry) numB.push_back(carry), ans=(char)(numB.back()+'0')+ans;
  }
  cout<<ans<<endl;
}