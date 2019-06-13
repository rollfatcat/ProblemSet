/* 種類：NPSC 國中組類似題(題目未提及解法但可以從測資觀察出方法)
 * 題目要求必須達到翻牌次數後最大化牌面的總和
 * 每張牌的分數 Xi，正面向上是正的，背面則是負的，n ≦ 1e4，k ≦ 1e9，-1e5 ≦ Xi ≦ 1e5
 * 核心解法：根據不同情況處理(有Cnt張分數一開始是負的，而翻牌次數是K)
 * (1) K ≦ Cnt，將所有的負數牌翻面
 * (2) K > Cnt，將所有的負數牌翻面後，多餘的次數都耗在絕對值離0最小的那張牌上
 *     每張牌的狀態都只有正面/背面兩種，只需要考慮『多餘次數』模二的餘數決定是否扣除
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001

int N; // 桌上的牌數
int K; // 需要翻面的次數
int number[MAXN];
int main(){
  while(scanf("%d%d",&N,&K)!=EOF){
    int sum=0;
    int cnt_negative=0;
    int close_zero=1<<30;

    for(int i=0;i<N;i++){
      scanf("%d",&number[i]);
      sum+=number[i];
      if(number[i]<0){
        cnt_negative++;
        if(-number[i]<close_zero)
          close_zero=-number[i];
      }
      else{
        if(number[i]<close_zero)
          close_zero=number[i];
      }
    }
    sort(number,number+N);
    for(int i=0;i<min(cnt_negative,K);i++)
      sum+=(-number[i])<<1;
    K-=cnt_negative;
    if(K>0 and (K&1))
      sum-=close_zero<<1;
    printf("%d\n",sum);
  }
}