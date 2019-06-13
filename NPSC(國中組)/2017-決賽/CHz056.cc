// 跟當前密碼最相近且六位數均相異的密碼
// 貪婪法找最短的調動次數＋暴力法找出全部的答案後排序輸出
// 觀察後可以發現：每個密碼轉動的情況不超過3步，全部的步數總和不會超過9步

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int way[10][9]={ {1,9,2,8,3,7,4,6,5},
               {0,2,3,9,4,8,5,7,6},
               {1,3,0,4,5,9,6,8,7},
               {2,4,1,5,0,6,7,9,8},
               {3,5,2,6,1,7,0,8,9},
               {4,6,3,7,2,8,1,9,0},
               {5,7,4,8,3,9,0,2,1},
               {6,8,5,9,0,4,1,3,2},
               {7,9,0,6,1,5,2,4,3},
               {0,8,1,7,2,6,3,5,4}};
string pass;
vector<string> ans;
vector<short> cnt(10,0);
void DFS(string nowss,int rem){
  int pos=nowss.length();
  if(pos>6 or pos==6 and rem) return;
  if(rem==0){
    for(int i=pos;i<=5;i++){
      for(int j=0;j<nowss.length();j++)
        if(pass[i]==nowss[j])
          return;
      nowss+=pass[i];
    }
    ans.push_back(nowss);
    return;
  }

  int now=pass[pos]-'0';
  if(cnt[now]==0)
    cnt[now]=pos+1,
    DFS(nowss+pass[pos],rem),
    cnt[now]=0;
  for(int i=0;i<=5;i++)
    if(cnt[ way[now][i] ]==0 and rem-(i>>1)-1>=0)
      cnt[ way[now][i] ]=pos+1,
      DFS(nowss+(char)(way[now][i]+'0'),rem-(i>>1)-1),
      cnt[ way[now][i] ]=0;
}

int main(){
  //
  cin>>pass;
  for(int i=0;i<6;i++)
    cnt[ pass[i]-'0' ]++;
  // 找出最少的調動次數
  int step=0;
  for(int i=0;i<6;i++)
    for(int j,now=pass[i]-'0';cnt[now]>1;cnt[now]--){
      for(j=0;j<9 and cnt[ way[now][j] ];j++);
      cnt[ way[now][j] ]++;
      step+=(j>>1)+1;
    }
  // 暴力法找出所有可能的字串
  for(int i=0;i<=9;i++)
    cnt[i]=0;
  DFS("",step);
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<' '<<step<<endl;
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<' ';
}