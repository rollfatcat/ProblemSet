// 字串含空白字元, 得用 getline() 不可用cin
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 101

int main(){
  int cnt[MaxN][MaxN];
  string s1, s2;

  for(int caseNum=1;getline(cin,s1) and s1!="#";caseNum++){
    getline(cin,s2);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s1.length();i++)
      for(int j=0;j<s2.length();j++)
        cnt[i+1][j+1]=(s1[i]==s2[j])?(cnt[i][j]+1):max(cnt[i+1][j],cnt[i][j+1]);
    cout<<"Case #"<<caseNum<<": you can visit at most "<<cnt[s1.length()][s2.length()]<<" cities.\n";
  }
}