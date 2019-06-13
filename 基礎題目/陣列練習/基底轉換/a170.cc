// 8進位轉10進位, 10進位轉16進位 => 0.8s
#include<iostream>
#include<vector>
using namespace std;

int main(){
  char Cx[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

  int N, i;
  string ss;
  long num1, num2;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for( cin>>N; N--;){
    num1=num2=0;
    for(cin>>ss, i=0;i<ss.length();i++)
      num1=8*num1+(ss[i]-'0');
    for(cin>>ss, i=0;i<ss.length();i++)
      num2=8*num2+(ss[i]-'0');
    num1+=num2;
    for(ss=""; num1>0; num1/=16)
      ss=Cx[num1%16]+ss;
    cout<<ss<<endl;
  }
}