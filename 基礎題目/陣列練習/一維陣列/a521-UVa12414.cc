// 將輸入的字串轉換成一串位數，比如JYFTYR 則以 90/105/86/100/105/98 => 901058610010598
// 根據題目規則一層一層轉換

#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(string ss; cin>>ss; ){
    int ST=1;
    for(; ST<=10000; ST++){
      vector<short> num;
      for(int i=0;i<ss.length();i++){
        vector<short> oneN;
        for(int N=ss[i]-'A'+ST; N; N/=10)
          oneN.push_back(N%10);
        for(int j=oneN.size()-1; j>=0; j--)
          num.push_back(oneN[j]);
      }
      for(int len=num.size(); len>3; len--)
        for(int i=1;i<len;i++)
          num[i-1]=(num[i-1]+num[i])%10;
      if(num[0]==1 and num[1]==0 and num[2]==0)
          break;
    }
    if(ST>10000)
      cout<<":("<<endl;
    else
      cout<<ST<<endl;
  }
}