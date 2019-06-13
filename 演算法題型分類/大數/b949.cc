// 練習使用 __int128，因為讀取和輸出格式不支援必須自己用 getchar() 處理 (1.3s/348KB)
// 這題要把輸入的數值做平方後再乘以25(極限值一定會超過unsinged long的上限，必須用到__int128)
// 輸出時因為除法很耗時以MOD為單位看是拆成兩段還是值小於Long就直接輸出(TLE的主因)
// 小測資因為最後一個字元是EOF所以會少輸出一筆，但正式測資會換行才是EOF
#include<bits/stdc++.h>
using namespace std;

const long MOD=1e18;
inline bool scanLong(__int128 &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(__int128 L;scanLong(L);){
    L*=5,
    L*=L;
    if(L<=MOD)  printf("%ld\n",(long)L);
    else        printf("%ld%018ld\n",(long)(L/MOD),(long)(L%MOD));
  }
}