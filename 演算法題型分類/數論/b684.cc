// 很有趣的思考題，不用任何數論但是要思考規律
// 數字很多，不可能模擬來回掃描數列 => 每次考慮現在的方向與現在和下一個號碼之間的關係
/* 掃第一列時必定先找到#1，這時考慮#2在#1前面or#1後面
 * #2在#1後面且方向是順向時 or #2在#1前面且方向是反向時：此時方向不變(折返數不會增加)
 * #2在#1前面且方向是順向時 or #2在#1後面且方向是反向時：此時方向改變(折返數+1)，
 * 再考慮#2和#3位置的關係 => 位置更新成#2位置
 */
#include<iostream>
using namespace std;
#define MaxN 1000001

int main(){
  ios::sync_with_stdio(0), 
  cin.tie(0), cout.tie(0);
  int pos[MaxN], n;

  cin>>n;
  for(int i=0, x;i<n;i++)
    cin>>x, pos[x]=i;
  int cnt=0, now=pos[1];
  bool dir=0;
  for(int i=1; i<n; now=pos[++i]){
    if(now>pos[i+1] and !dir)
        cnt++, dir^=1;
    else if(now<pos[i+1] and dir)
        cnt++, dir^=1;
  }
  cout<<cnt<<endl;
}