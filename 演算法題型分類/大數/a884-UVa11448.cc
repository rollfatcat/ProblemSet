// 大數減法
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool SScompare(string &a, string &b){ //1代表a大或相同, 0代表b大
  if(a.length()!=b.length())
    return a.length()>b.length();
  for(int i=0;i<a.length();i++)
    if(a[i]!=b[i])
      return a[i]>b[i];
  return true;
}
string SSsub(string &a, string &b){
  string ans="";
  vector<int> A, B;
  int i;
  for(i=a.length()-1;i>=0;i--)
    A.push_back(a[i]-'0');
  for(i=b.length()-1;i>=0;i--)
    B.push_back(b[i]-'0');
  for(i=0;i<b.length();i++){
    A[i]-=B[i];
    if(A[i]<0)
      A[i+1]--, A[i]+=10;
  }
  for(i=b.length(); i<a.length() and A[i]<0; i++)
    A[i+1]--, A[i]+=10;
  for(i=a.length()-1;i>0 and A[i]==0;i--);
  for( ;i>=0;i--)
    ans+=(char)(A[i]+'0');
  return ans;
}
int main(){
  string ssA, ssB;
  int n;

  for(cin>>n; n--; ){
    cin>>ssA>>ssB;
    bool condition=SScompare(ssA,ssB);
    string ssC=(condition)?SSsub(ssA,ssB):('-'+SSsub(ssB,ssA));
    cout<<ssC<<endl;
  }
}