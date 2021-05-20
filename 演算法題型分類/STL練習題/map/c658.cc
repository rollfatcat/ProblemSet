/* 題目有提到沒辦法用next_permutation過關，所以想法改由平方數來推導(可以和DFS的Brute-Force比較)
 * 4~10位數 => range(34,99999)產生所有的平方數且不包含字元0
 * 建立hash_table+2D vector ( key=排序後的最小數, value=指向的vector ID  )
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<long> > ans;
  map<long,int> table;
  int Tidx=0;
  for(long i=34;i<=99999;i++){
    if(i%10==0) continue;
    long x=i*i;
    vector<long> n;
    while(x and x%10)
      n.push_back(x%10), x/=10;
    if(x==0){
      sort(n.begin(),n.end());
      x=0;
      for(int i=0;i<n.size();i++)
        x=(x<<3)+(x<<1)+n[i];
      n.assign(1,i*i);
      map<long,int>::iterator it=table.find(x);
      if(it==table.end())
        table[x]=Tidx++, ans.push_back(n);
      else
        ans[it->second].push_back(i*i);
    }
  }
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(string ss; cin>>ss;){
    sort(ss.begin(),ss.end());
    long x=0;
    for(int i=0;i<ss.length();i++)
      x=(x<<3)+(x<<1)+ss[i]-'0';
    map<long,int>::iterator it=table.find(x);
    if(it==table.end()) puts("0");
    else{
      for(auto i:ans[it->second])
        cout<<i<<' ';
      cout<<'\n';
    }
  }
}
/*
44    -> 40
512   -> 400
4046  -> 2470
32440 -> 12345
*/