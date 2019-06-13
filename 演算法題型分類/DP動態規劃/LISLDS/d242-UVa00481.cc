// 這題的輸入數量很大(500000) 時間必須壓在 N㏒N
// Robinson-Schensted-Knuth Algorithm : http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html#3
#include<iostream>
#include<vector>
using namespace std;

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
vector<int> LIS;
int BS(int x){
  if(x>LIS.back())  return LIS.size();
  int l=0,r=LIS.size()-1,m;
  while(l<=r){
    m=(l+r)>>1;
    if(LIS[m]==x) return m;
    else if(LIS[m]>x) r=m-1;
    else l=m+1;
  }
  return l;
}
int main(){

  int cnt, num[500000], pos[500000];
  // 先推一個到LIS才能方便比對時呼叫LIS.back()不會出錯
  scanInt(num[0]),
  LIS.push_back(num[0]),
  pos[0]=0;
  for(cnt=1; scanInt(num[cnt]);cnt++){
    pos[cnt]=BS(num[cnt]);
    if(pos[cnt]==LIS.size()) LIS.push_back(num[cnt]);
    else LIS[pos[cnt]]=num[cnt];
  }
  // 反向把找到的位置推到vec
  int len=LIS.size()-1;
  for(int i=cnt-1;i>=0;i--)
    if(pos[i]==len)
      LIS[len--]=num[i];
  printf("%lu\n-\n",LIS.size());
  for(auto n:LIS)
    printf("%d\n",n);
}