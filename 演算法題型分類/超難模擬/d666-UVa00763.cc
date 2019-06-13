// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4296810
// 解法：確保維護費波那契數列的規則(連續兩個1必定不相連)從頭檢查起，回傳『不合法的位數』
/* 先處理這個位數的『進位調整』，而後再根據位置調整後確保保持合法狀態的最後位置
 * 規律觀察：
 * (1) 如果最右邊的位數值＞１，則把它左邊的位數值＋１，自己－2
 * (2) 如果從右邊數來第二個位數值＞１，則把它左、右的位數值＋１，自己－２
 * (3) 如果其他位數值＞１，則把它左邊＋１、右邊第二個＋１，自己－２
 * 因為有可能會更動到前面已經判斷過的位數，因此要檢查是否合費氏進位制的定義。
 * 如果為非，繼續進行上面的加法規則，直到符合定義。
 */
#include<bits/stdc++.h>
using namespace std;

const short MAXN=105;
char ss[MAXN];
short bit[MAXN], ssL, L;
/* 從頭檢查一次到目前為止是否合法
 * YES, 就往下一位數挑戰
 * NO,  回傳不合法的位置
 */
inline int Check(int end){
  if(bit[0]>1) return 0;
  for(int i=1;i<=end;i++)
    if(bit[i]>1 or bit[i]==1 and bit[i-1])
      return i-1;
  return end+1;
}
int main(){

  for(int caseN=0;scanf("%s",ss)!=EOF;caseN++){
    if(caseN) puts("");
    // 處理輸入
    fill(bit,bit+MAXN,0);
    ssL=strlen(ss);
    for(int i=0;i<ssL;i++)
      bit[ssL-i-1]=(ss[i]=='1');
    scanf("%s",ss);
    ssL=strlen(ss);
    for(int i=0;i<ssL;i++)
      bit[ssL-i-1]+=(ss[i]=='1');
    // 進位調整
    for(int carry,now=0;now<MAXN;now=Check(now)){
      // (先)進位調整
      carry=min(bit[now],bit[now+1]);
      bit[now]-=carry;
      bit[now+1]-=carry;
      bit[now+2]+=carry;
      // 根據位置把這個位數調整到合法狀態
      if(now==0 and bit[0]>1){
        carry=bit[0]>>1,
        bit[1]+=carry,
        bit[0]&=1;
      }else if(now==1 and bit[1]>1){
        carry=bit[1]>>1,
        bit[0]+=carry,
        bit[2]+=carry,
        bit[1]&=1;
      }else{
        carry=bit[now]>>1,
        bit[now-2]+=carry,
        bit[now+1]+=carry,
        bit[now]&=1;
      }
    }
    // 輸出
    L=MAXN-1;
    for( ;L>=0 and bit[L]==0;L--);
    for( ;L>=0;L--)
      putchar(bit[L]+'0');
    puts("");
  }
}
// 11011
// 100