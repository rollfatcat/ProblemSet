#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int cnt[52], i;
  string ss;

  while(true){
    getline(cin,ss);
    if(ss=="=====")
      break;
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<ss.length();i++)
      if('a'<=ss[i])
        cnt[ss[i]-'a'+26]++;
      else if('A'<=ss[i])
        cnt[ss[i]-'A']++;
    getline(cin,ss);
    for(i=0;i<ss.length();i++)
      if('a'<=ss[i]){
        if(cnt[ss[i]-'a'+26]>0) cnt[ss[i]-'a'+26]--;
        else break;
      } else if('A'<=ss[i]){
        if(cnt[ss[i]-'A']>0) cnt[ss[i]-'A']--;
        else break;
      }
    bool flag=(i==ss.length());
    if(flag){ //數量要一樣多
      for(i=0;i<52 and cnt[i]==0;i++);
      flag=(i==52);
    }
    if(flag)  cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}