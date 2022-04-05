/* 給定６個整數代表方程式由高到低的係數項，依"情況"由小到大輸出該函數的所有根？
 * (1) 若存在無限組解輸出「Too many... = ="」
 * (2) 若在給定的範圍內不存在實根輸出「N0THING! >\\\<」
 * (3) 若某個根介於２個連續整數間則輸出２個整數
 * (4) 若根剛好是整數則將該整數輸出２次。
 * 解題關鍵：堪根定理實作
 * 根據題目提到的"某個跟是否存在連續整數間"只需要由小到大枚舉左端點的整數做勘根。
 * 題目保證的範圍：-2147483647 ≦ x^6 ≦ 2147483647，推導ｘ的範圍介於，-35.9 ≦ ｘ ≦ 35.9。
 */
#include<bits/stdc++.h>
using namespace std;

int coff[6];
inline long get_func(long x){
  return coff[5]*x*x*x*x*x+coff[4]*x*x*x*x+coff[3]*x*x*x+coff[2]*x*x+coff[1]*x+coff[0];}
int main(){
  
    scanf("%d %d %d %d %d %d\n",&coff[5],&coff[4],&coff[3],&coff[2],&coff[1],&coff[0]);
    int zeroCnt=0;
    for(int i=0;i<=5;i++)  
      zeroCnt+=(coff[i]==0);
    /* 存在無限多組解的唯一情況：方程式＝Ｘ軸 */
    if(zeroCnt==6){ puts("Too many... = =\""); return 0; }
    /* -2147483647 ≦ x^6 ≦ 2147483647
     * 因此，我們可以推出ｘ的範圍介於，-35.9 ≦ ｘ ≦ 35.9。
     * 所以從 -36 代值到函數裡，直到 ｘ=36 為止，這樣就可以跑遍所有可能的範圍了。
     */
    int rootCnt=0, idx=-36;
    long pre_v, now_v;
    /* 勘根時需要左端點帶入函數後的值，初始化左端點：找到一個非零的值 */
    while(idx<=36 and (pre_v=get_func(idx))==0){
      printf("%d %d\n",idx,idx);
      idx++, rootCnt++;
    }
    for(idx++;idx<=36;idx++){
      now_v=get_func(idx);
      if(now_v==0)  
        printf("%d %d\n",idx,idx), rootCnt++;
      else if((pre_v<0 and now_v>0) or (pre_v>0 and now_v<0)) 
        printf("%d %d\n",idx-1,idx), rootCnt++;
      pre_v=now_v;
    }
    /* 不存在實數根 */
    if(rootCnt==0) puts("N0THING! >\\\\\\<");
  
}