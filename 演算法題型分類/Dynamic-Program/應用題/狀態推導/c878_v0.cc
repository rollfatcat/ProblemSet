// 正規題解：https://home.gamer.com.tw/creationDetail.php?sn=4215885
// DP解：根據狀態(3種) => 初始條件要3個
// 範圍在120000以內 => 可以線性推導
// 先寫一個DFS找出前10個3種狀態確認推導的規律
#include<iostream>
using namespace std;
#define mod 100000007

int cnt[120001][3]={};
int main(){
  // 建立前3個初始條件
  cnt[1][0]=1, cnt[1][1]=1, cnt[1][2]=1,
  cnt[2][0]=3, cnt[2][1]=3, cnt[2][2]=2,
  cnt[3][0]=8, cnt[3][1]=7, cnt[3][2]=4;
  // 讀取數字，輸出結果
  int N;  cin>>N;
  for(int idx=4;idx<=N; idx++){
    cnt[idx][0]=(cnt[idx-1][0]+cnt[idx-1][1]+cnt[idx-1][2])%mod;
    cnt[idx][1]=(cnt[idx][0]-cnt[idx-3][0]-cnt[idx-3][2])%mod;
    while(cnt[idx][1]<0) cnt[idx][1]+=mod;
    cnt[idx][2]=(cnt[idx-1][2]+cnt[idx-2][2]+cnt[idx-3][2])%mod;
  }
  cout<<(cnt[N][0]+cnt[N][1]+cnt[N][2])%mod<<endl;
}
/*  由前10個推導出規律
   3 :    1    1    1
   8 :    3    3    2
  19 :    8    7    4
  43 :   19   17    7
  94 :   43   38   13
 200 :   94   82   24
 418 :  200  174   44
 861 :  418  362   81
1753 :  861  743  149
3536 : 1753 1509  274
*/