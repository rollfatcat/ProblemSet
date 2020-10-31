// 統計每個字母出現次數(由多到少輸出，一樣時則依據字母的字典序)
#include<iostream>
#include<algorithm>
using namespace std;

struct Node{ char ch; int n; } cnt[26];
bool compare(Node a, Node b){ return (a.n==b.n)?(a.ch<b.ch):(a.n>b.n); }
int main(){
  int n;
  string ss;

  for(int i=0;i<26;i++)
    cnt[i].ch=(char)('A'+i), cnt[i].n=0;
  cin>>n;
  getchar();
  while(n--){
    getline(cin,ss);
    for(int i=0;i<ss.length();i++)
      if('a'<=ss[i] and ss[i]<='z')
        cnt[ss[i]-'a'].n++;
      else if('A'<=ss[i] and ss[i]<='Z')
        cnt[ss[i]-'A'].n++;
  }
  sort(cnt,cnt+26,compare);
  for(int i=0;i<26 and cnt[i].n>0;i++)
    cout<<cnt[i].ch<<' '<<cnt[i].n<<endl;
}