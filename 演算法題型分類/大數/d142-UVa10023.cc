// 想法：大數開方法，但實際上要用牛頓逼近法
// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4153409
#include<iostream>
#include<vector>
using namespace std;

vector<int> ss;
bool compare(int stA,int edA,vector<int> &B){
  if((edA-stA+1)==B.size())
    for(int i=0;i<B.size();i++)
      if(ss[stA+i]!=B[i])
        return ss[stA+i]>B[i];
  return (edA-stA+1)>=B.size();
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T;
  for(cin>>T;T--; ){
    string ans;
    cin>>ans;
    ss.clear();
    vector<int> sideNum;
    for(int i=0;i<ans.length();i++)
      ss.push_back(ans[i]-'0');
    int st=0,ed=1-(ss.size()%2);
    for(ans=""; ed<ss.size(); ed+=2){
      // 測試最後一個位數
      vector<int> tryNum;
      int last_bit, carry;
      for(last_bit=1; last_bit<=9 ;last_bit++){
        tryNum=sideNum,  tryNum.push_back(last_bit);
        carry=0;
        for(int i=tryNum.size()-1; i>=0;i--)
          tryNum[i]=tryNum[i]*last_bit+carry, carry=tryNum[i]/10, tryNum[i]%=10;
        if(carry) tryNum.insert(tryNum.begin(),carry);
        if(compare(st,ed,tryNum)==0)
          break;
      }
      last_bit--, sideNum.push_back(last_bit), ans+=(char)(last_bit+'0');
      // 大數減法
      tryNum=sideNum, carry=0;
      for(int i=tryNum.size()-1; i>=0;i--)
        tryNum[i]=tryNum[i]*last_bit+carry, carry=tryNum[i]/10, tryNum[i]%=10;
      if(carry) tryNum.insert(tryNum.begin(),carry);
      for(int i=0;i<tryNum.size();i++){
        ss[ed-i]-=tryNum[tryNum.size()-1-i];
        if(ss[ed-i]<0)
          ss[ed-i-1]--, ss[ed-i]+=10;
      }
      while(st<=ed and ss[st]==0) st++;
      // 大數加法
      sideNum.back()+=last_bit, carry=0;
      for(int i=sideNum.size()-1; i>0 and sideNum[i]>9;i--)
        sideNum[i-1]++, sideNum[i]-=10;
      if(sideNum[0]>9) sideNum[0]-=10,  sideNum.insert(sideNum.begin(),1);
    }
    cout<<ans<<endl;
  }
}