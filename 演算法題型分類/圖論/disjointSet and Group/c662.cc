/* DisjointSet(簡單版本，每個數字只會出現一次) => 只需要用迴圈/遞迴找出循環的週期即可
 * 找出所有週期的最小公倍數(需要建立1000以內的質數表)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3;
vector<int> prime{2,3,5,7,11,13,17,19,23,29,31}; // 1000以內的質數
int main(){

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(string ss; getline(cin,ss); ){
    int x=0;
    vector<int> nxt;
    for(int i=0; ss[i]!=0; i++)
      (ss[i]==' ')? nxt.push_back(x),x=0: x=(x<<3)+(x<<1)+ss[i]-'0';
    nxt.push_back(x);
    vector<bool> vis(nxt.size(),0);
    vector<int> cycle;
    for(int len, now, i=0;i<nxt.size();i++){
      for(len=0,now=i; vis[now]==0; vis[now]=1,len++, now=nxt[now]);
      if(len>1) cycle.push_back(len);
    }
    // 取所有週期的最小公倍數
    long rhs_prime=1;
    vector<int> cnt(prime.size(),0);
    set<int> memo; // 紀錄出現過的質數(無法被1000以內的質數表偵測出來的部分)
    for(int x:cycle){
      for(int pCnt,i=0; x>1 and i<prime.size(); i++){
        for(pCnt=0;x%prime[i]==0;pCnt++,x/=prime[i]);
        cnt[i]=max(cnt[i],pCnt);
      }
      if(x>1 and memo.find(x)==memo.end())
        memo.insert(x),
        rhs_prime*=x;
    }
    long ans=1;
    for(int i=0;i<prime.size();i++)
      for(int j=cnt[i];j>0;j--)
        ans*=prime[i];
    cout<<ans*rhs_prime<<'\n';
  }
}