// 題目同d716 都是求最長相異子字串，slide windows(滑動視窗)
// 這題在判斷某字元是否存在集合裡時的時間只容許O(㏒N) -> set
/* 使用L與R紀錄子字串的左右邊界，使用set記憶目前in[L]到in[R]的數字，
 * 當新加入in[R]與set中元素重複，就記錄目前的L-R的值是否比較大，
 * 依序從set中刪除in[L]往後的元素刪除直到in[R]不重複，繼續讀取in[R]以後的字元
 */
#include<iostream>
#include<vector>
#include<set> //學會使用insert/erase/count
using namespace std;

void scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9'; x=(x<<3)+(x<<1)+c-'0'); }
int main(){

  int T, N, L, R, maxL;
  for(scanInt(T); T--; ){
    vector<int> num;
    set<int> S;

    scanInt(N); L=R=maxL=0;
    for(int i=0,x; i<N; i++){
      scanInt(x), num.push_back(x);
      if(S.count(x)){
        maxL=(R-L>maxL)?(R-L):maxL;
        while(num[L]!=x)
          S.erase(num[L++]);
        S.erase(num[L++]);
      }
      S.insert(x), R++;
    }
    maxL=(R-L>maxL)?(R-L):maxL;
    printf("%d\n",maxL);
  }
}