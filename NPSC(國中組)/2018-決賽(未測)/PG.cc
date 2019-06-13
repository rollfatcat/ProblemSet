// 1 ≤ N ≤ 200，Ｋ={0,1,13}，且題目的不同牌面＝某一張牌位置不同即可
// 多種解，輸出其一即可

#include<bits/stdc++.h>
using namespace std;

int N, K, cnt=0;
string one[13]={"1m","9m","1p","9p","1s","9s","1z","2z","3z","4z","5z","6z","7z"};
string non[13]={"7z","7z","2m","3m","4m","5m","6m","7m","2p","3p","4p","5p","6p"};
void DFS13(int turn){
  if(turn==13){
    for(int i=0;i<13;i++)
      cout<<one[i]<<((i==12)?'\n':' ');
    cnt++;
    return;
  }
  DFS13(turn+1);
  if(cnt==N) return;
  swap(one[turn-1],one[turn]);
  DFS13(turn+1);
}
void DFS00(int turn){
  if(turn==13){
    for(int i=0;i<13;i++)
      cout<<non[i]<<((i==12)?'\n':' ');
    cnt++;
    return;
  }
  DFS00(turn+1);
  if(cnt==N) return;
  swap(non[turn-1],non[turn]);
  DFS00(turn+1);
}
int main(){
  cin>>N>>K;
  if(K==13)
    DFS13(1);
  else if(K==1)
    one[0]=one[1],
    DFS13(1);
  else
    DFS00(1);
}