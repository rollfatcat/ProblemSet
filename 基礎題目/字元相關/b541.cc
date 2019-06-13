// 數字的字串和字元的相互轉換，據說原考題是台積的面試題
#include<iostream>
using namespace std;

string ss[40];
inline string NumToStr(int x){
  string out="";
  for(;x>0;x/=10)
    out=(char)(x%10+'0')+out;
  return out;
}
int main(){
  ss[0]="1";
  for(int idx=1;idx<40;idx++){
    ss[idx]="";
    int pre=idx-1, cnt=1; char ch=ss[idx-1][0];
    for(int i=1;i<ss[pre].length();i++)
      if(ch==ss[pre][i]) cnt++;
      else ss[idx]+=(NumToStr(cnt)+ch), ch=ss[pre][i], cnt=1;
    ss[idx]+=(NumToStr(cnt)+ch);
  }
  cout<<ss[39].length()<<endl;
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int n;cin>>n;)
    cout<<ss[n-1]<<'\n';
}
/*
1
11
21
1211
111221
*/