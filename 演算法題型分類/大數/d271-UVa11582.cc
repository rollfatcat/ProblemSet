// 需要想一下的有趣題目，取模後導致的狀態循環偵測+快速幕次法
// (輸入優化 20ms -> 16ms)
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void scanInt(unsigned long &x){//輸入：後面會多吃一個不屬於數字的字元後跳開
  x=0;
  for(char ch; (ch=getchar())>='0' and ch<='9'; )
    x=(x<<3)+(x<<1)+ch-'0';
}
void printInt(int x){
  int len=0;
  char ss[100];
  if(x==0) //避免數字是0時，沒有輸出
    ss[len++]='0';
  for(; x>0; x/=10)
    ss[len++]=(char)(x%10+'0');
  while(len--)
    putchar(ss[len]);
  puts("");
}
int main(){
  // 取模導致的循環偵測
  vector<int> cycle[1001];
  for(int now=2; now<=1000; now++){
    bool map[now][now];
    memset(map,0,sizeof(map));
    map[0][1]=map[1][1]=1;
    cycle[now].push_back(0),
    cycle[now].push_back(1),
    cycle[now].push_back(1);
    for(int idx=3; true;idx++){
      int to=(cycle[now][idx-1]+cycle[now][idx-2])%now;
      if(!map[ cycle[now][idx-1] ][ to ])
        cycle[now].push_back(to), map[ cycle[now][idx-1] ][ to ]=1;
      else
        break;
    }
  }
  //
  unsigned long a, b, n, T;
  scanInt(T);
  while(T--){
    scanInt(a), scanInt(b), scanInt(n);
    if(n==1){ puts("0"); continue; }
    int num=1, CY=cycle[n].size()-1;
    for(int base=a%CY; b; base=(base*base)%CY, b/=2)
      if(b%2)
        num=(num*base)%CY;
    printInt(cycle[n][num]);
  }
}