// 類似 CHg018-達文西密碼
#include<iostream>
#include<cstring>
using namespace std;

int CharToNum(char c){
  if(c>='a')  return c-71;
  if(c>='A')  return c-'A';
  if(c==' ')  return 52;
  if(c==',')  return 53;
  return 54;
}
int main(){
  int caseNum, cnt[2][55];
  string s1, s2;

  cin>>caseNum; getchar();
  while(caseNum--){
    getline(cin,s1);
    getline(cin,s2);
    if(s1.length()!=s2.length()){
      cout<<"impossible"<<endl; continue;
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s1.length();i++)
      cnt[0][ CharToNum(s1[i]) ]++,
      cnt[1][ CharToNum(s2[i]) ]++;
    int idx=0;
    for( ;idx<55 and cnt[0][idx]==cnt[1][idx];idx++);
    if(idx==55) cout<<"possible"<<endl;
    else cout<<"impossible"<<endl;
  }
}