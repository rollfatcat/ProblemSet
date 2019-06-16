#include<bits/stdc++.h>
using namespace std;

/* 設置頭指針p1和尾指針p2，fread()一次讀入 1<<21 個字符存在buf裡，然後用p1来調用；
 * 當p1撞到p2時再次用fread()讀入 1<<21 個字符，優化原理就是讓fread()一次性讀入大量數據，
 * 再讓 getchar() 直接調用内存，若剛開始讀的不夠多那就再調用fread()讀入數據，直到文件的末尾。
 */
char buf[1<<21],*p1=buf,*p2=buf;
inline int getch(){ return p1==p2 and (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++; }
/* template <typename T>前缀表示一個類型。
 * 換句話說，傳入的 type 是int類型變量，T就表示int；
 * 假若傳入的 type 是long long類型的，T就是long long
 */
template<typename T>inline bool readnumber(T &_){
  register int c=getch(); register T __= 1; _=0;
  while(!isdigit(c) and c!=EOF) c=getch();
  if(c==EOF) return false;
  while(isdigit(c)) _=(_<<3)+(_<<1)+c-'0', c=getch();
  _*=__;
  return true;
}
// 第二個函數是第一個函數的重载。主要是typename... Args的問题吧，這個表示不定参數(不确定#参數)
template <typename T,typename... Args> inline bool readnumber(T& t, Args&... args){
  return readnumber(t) and readnumber(args...);
}
// 利用getchar()實現加速讀取
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
// 利用putchar()實現加速輸出
inline void printInt(int x,int base=10){
  while(base<=x) base*=10;
  while(base>1)  base/=10,putchar(x/base+'0'),x%=base;
  putchar(' ');
}

int main(){
  int n, x;
  while(readnumber(n)){
    for(int i=1;i<n;i++)
      readnumber(x),
      printInt(x*(n-i));
    readnumber(x);
    // 當只有一項時作微分應該要印出0，多於一項時則不需要輸出這個0
    if(n==1) putchar('0');
    putchar('\n');
  }
}