// 題目保證不會重複數字
// 當數字會重複時需要判斷的情況會變得複雜許多-> a291
// https://zerojudge.tw/ShowProblem?problemid=a291
#include<iostream>
using namespace std;

bool isIn[10]={0};
int main(){
  string s1, s2;
  int times;

  cin>>s1;
  isIn[s1[0]-'0']=isIn[s1[1]-'0']=isIn[s1[2]-'0']=isIn[s1[3]-'0']=1;
  cin>>times;
  while(times--){
    cin>>s2;
    int A=0, B=0;
    for(int i=0;i<4;i++)
      if(s2[i]==s1[i])  A++;
      else if(isIn[s2[i]-'0'])  B++;
    cout<<A<<"A"<<B<<"B"<<endl;
  }
}