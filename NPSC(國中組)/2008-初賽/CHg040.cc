// 以'#'為分界, 只有前半段和後半段的子字串相同就輸出"可能"
// 所以 '#' 遮住的部分可能沒有字元也是對的
#include<iostream>
using namespace std;

int main(){
  int T, times;
  string s1, s2;

  cin>>T;
  for(int caseNum=1;caseNum<=T;caseNum++){
    cin>>s1>>times;
    int idx=s1.find('#');
    cout<<"DATA SET #"<<caseNum<<":"<<endl;
    while(times--){
      cin>>s2;
      bool isSUB=true;
      if(isSUB){
        int i, j;
        for(i=0;i<idx and s1[i]==s2[i];i++);
        isSUB &= (i==idx);
        for(i=s1.length()-1, j=s2.length()-1; i>idx and s1[i]==s2[j];i--,j--);
        isSUB &= (i==idx);
      }
      if(isSUB) cout<<"POSSIBLE\n";
      else  cout<<"IMPOSSIBLE\n";
    }
  }
}