// 練習自己寫一個set功能，自定義 operator 和 initialize()
#include<iostream>
#include<vector>
using namespace std;

struct CustomSet{
public:
  CustomSet(string ss): content(ss){
    for(int i=0;i<content.length();i++)
      inChar[content[i]]=1;
    content="";
    for(int i=0;i<=255;i++)
      if(inChar[i])
        content+=(char)(i);
  }
  string get_contnet(){ return content; }
  bool query_inChar(int idx){ return inChar[idx]; }
  string operator+(CustomSet other){
    string outStr="";
    for(int i=0;i<=255;i++)
      if(inChar[i] or other.query_inChar(i))
        outStr+=(char)(i);
    return outStr;
  }
  string operator*(CustomSet other){
    string outStr="";
    for(int i=0;i<=255;i++)
      if(inChar[i] and other.query_inChar(i))
        outStr+=(char)(i);
    return outStr;
  }
  string operator-(CustomSet other){
    string outStr="";
    for(int i=0;i<=255;i++)
      if(inChar[i] and !other.query_inChar(i))
        outStr+=(char)(i);
    return outStr;
  }
  bool operator>=(CustomSet other){
    for(int i=0;i<=255;i++)
      if(other.query_inChar(i) and !inChar[i])
        return false;
    return true;
  }
private:
  bool inChar[256]={};
  string content;
};
int main(){
  for(int N,caseN=1; cin>>N and N; caseN++){
    cout<<"Test Case "<<caseN<<":"<<endl;
    vector<CustomSet> S;
    string ss;
    for(int i=0;i<N;i++){
      cin>>ss;  CustomSet newOne(ss); S.push_back(newOne);
      cout<<(char)('A'+i)<<": {"<<newOne.get_contnet()<<"}"<<endl;
    }
    // union
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++)
        cout<<(char)('A'+i)<<"+"<<(char)('A'+j)<<": {"<<S[i]+S[j]<<"}"<<endl;
    // intersection
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++)
        cout<<(char)('A'+i)<<"*"<<(char)('A'+j)<<": {"<<S[i]*S[j]<<"}"<<endl;
    // difference
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        if(i!=j)
          cout<<(char)('A'+i)<<"-"<<(char)('A'+j)<<": {"<<S[i]-S[j]<<"}"<<endl;
    // contain
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        if(i!=j)
        if(S[i]>=S[j])  cout<<(char)('A'+i)<<" contains "<<(char)('A'+j)<<endl;
        else cout<<(char)('A'+i)<<" does not contain "<<(char)('A'+j)<<endl;
  }
}