// 練習轉換字串格式轉換成數字(時間格式和記憶體的轉換)
// 輸入時必須用 getline(cin,ss) 讀取部分得還蓋空白部分
// 輸出部分有判斷順序( 善用continue )
#include<bits/stdc++.h>
using namespace std;

string ss;
inline double StrToTime(int idx=0,double rsp=0.0){
  for(idx=0;idx<ss.length();idx++){
    if(ss[idx]>='0' and ss[idx]<='9')
      rsp=10*rsp+ss[idx]-'0';
    if(ss[idx]=='.')
      rsp+=0.1*(ss[++idx]-'0'), idx++;
    if(ss[idx]=='m'){
      if((idx+1)==ss.length() or ss[idx+1]=='i')
        return rsp*100;
      if(ss[idx+1]=='s')
        return rsp*0.001;
    }
  }
  return rsp;
}
inline double StrToMemory(int idx=0,double rsp=0.0){
  for(idx=0;ss[idx]>='0' and ss[idx]<='9';idx++)
    rsp=10*rsp+ss[idx]-'0';
  if(ss[idx]=='.')
    rsp+=0.1*(ss[++idx]-'0'), idx++;
  if(ss[idx]=='M')
    rsp*=1000;
  return rsp;
}
int main(){
  // 2.6s vs 0.3s
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  double usr_time, usr_memory, limit_time, limit_memory;
  for(int caseN=1;cin>>ss;caseN++){
    usr_time=StrToTime();
    cin>>ss, usr_memory=StrToMemory();

    cin>>ss, limit_time=StrToTime();
    cin>>ss, limit_memory=StrToMemory();

    vector<string> input, ans;
    getline(cin,ss);
    while(getline(cin,ss) and ss!="(This is the end of the user's output.)")
      input.push_back(ss);
    while(getline(cin,ss) and ss!="(This is the end of the correct answer.)")
      ans.push_back(ss);

    if(usr_time>limit_time){ cout<<"TLE\n"; continue; }
    if(usr_memory>limit_memory){ cout<<"MLE\n"; continue; }
    if(input.size()>ans.size()){ cout<<"OLE\n"; continue; }
    bool correct=true;
    for(int i=0;i<input.size() and correct;i++){
      correct&=(input.size()==ans.size());
      for(int j=0;j<input[i].size() and correct;j++)
        if(input[i][j]!=ans[i][j])
          correct=false;
    }
    cout<<( (correct)?"AC\n":"WA\n" );
  }
}
/*
0ms 292KB
1s 512MB
Number  1
(This is the end of the user's output.)
Number 1
(This is the end of the correct answer.)
*/