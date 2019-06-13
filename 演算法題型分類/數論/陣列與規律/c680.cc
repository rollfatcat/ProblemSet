// 比對學生的答案和正確答案(字串比較)，根據答對比率輸出得分(滿分100)
// 題目的數量保證是100的因數(不需考慮浮點數問題)，注意學生的字串長度不等於答案長度
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int problem_cnt, student_cnt;
  string ans, test;

  cin>>problem_cnt>>ans>>student_cnt;
  int point=100/problem_cnt;
  for(int i=0;i<student_cnt;i++){
    cin>>test;
    int score=0;
    for(int i=0;i<test.length() and i<ans.length();i++)
      if(test[i]==ans[i])
        score+=point;
    cout<<score<<'\n';
  }
}