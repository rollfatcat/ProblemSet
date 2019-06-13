// 大數乘法=以bit為單位做大數加法
// 會發生250*250次的進位過程 => 28ms
#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(string ss; cin>>ss; ){
    vector<int> num[10];
    int end=0;
    while(end<ss.length() and ss[end]=='0') end++;
    num[0].push_back(0);
    for(int i=ss.length()-1;i>=end;i--)
      num[1].push_back(ss[i]-'0');
    for(int idx=2;idx<=9;idx++){
      int carry=0;
      for(int i=0;i<num[1].size();i++)
        num[idx].push_back(num[1][i]*idx+carry),
        carry=num[idx][i]/10,
        num[idx][i]=num[idx][i]%10;
      if(carry) num[idx].push_back(carry);
    }
    cin>>ss;
    int len=ss.length();
    for(end=0;end<len and ss[end]=='0';end++);
    vector<int>ans;
    ans.push_back(0);
    for(int idx=len-1;idx>=end;idx--){
      int bit=ss[idx]-'0';
      int anslen=ans.size(), carry=0;
      for(int i=0, shift=len-1-idx; i<num[bit].size(); i++, shift++)
        if(shift<anslen)
          ans[shift]+=(num[bit][i]+carry),
          carry=ans[shift]/10,
          ans[shift]=ans[shift]%10;
        else
          ans.push_back(num[bit][i]+carry),
          carry=ans[shift]/10,
          ans[shift]=ans[shift]%10;
      if(carry) ans.push_back(carry);
    }
    //
    for(int i=ans.size()-1;i>=0;i--)
      cout<<ans[i];
    cout<<endl;
  }
}