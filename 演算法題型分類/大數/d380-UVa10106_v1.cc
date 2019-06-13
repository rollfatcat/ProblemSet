// 大數乘法=兩個數以bit為單位 累加到相對的位置
// 由小到大一次完成所有的進位, 只發生 500次的進位 => 8ms
// 最長的累加部分是250*99*99*2< 2^31-1, 時間壓縮到4ms=> 猜測是base=100的版本
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ans[500], end, base, l1, l2, n[2][250];
  for(string s1, s2; cin>>s1>>s2; ){
    // 題目會惡意輸入0開頭的數字, 避免該情況發生就從頭往下數到沒有0,但要注意當數字=0時
    for(end=0;end<s1.length() and s1[end]=='0';end++);
    l1=s1.length()-end;
    for(int i=s1.length()-1, j=0; i>=end; i--,j++)
      n[0][j]=s1[i]-'0';
    for(end=0;end<s2.length() and s2[end]=='0';end++);
    l2=s2.length()-end;
    for(int i=s2.length()-1, j=0; i>=end; i--,j++)
      n[1][j]=s2[i]-'0';

    memset(ans,0,sizeof(ans));
    for(int i=0;i<l1;i++)
      for(int j=0;j<l2;j++)
        ans[i+j]+=(n[0][i])*(n[1][j]);
    int len=s1.length()+s2.length();
    for(int i=0;i<len;i++)
      ans[i+1]+=ans[i]/10,  ans[i]=ans[i]%10;

    for(; len>0 and ans[len]==0;len--);
    for(int i=len;i>=0;i--)
      cout<<ans[i];
    cout<<endl;
  }
}