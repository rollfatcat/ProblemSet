// 二分搜尋應用題型(2) : 利用二分搜尋快速逼近答案
// 注意邊界的型態是long，因為全部頁數加總是5e10且輸出格式很難(建議直接給學生Codes)
/* 題目給定M本書及K個員工(1<=K<=M<=500)，每本書有不同的頁數，同本書只能分配給同個員工，
 * 我們用二分搜尋找出每個人的工作量(頁數)的上限，(題目要求工作量越少越好，但如果太少就
 * 需要>K個員工)。此外如果有多組解的情況，index越大的員工所分配的書要盡量的多，
 * 因此分配書的時候index從後面開始，但注意分配時每個人至少要有一本書，因此如果
 * (剩下的書<=剩下的人)，就算那個人還沒分完，也要直接換下一個人。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=500;
int caseN, book_num, man_num;
int book[MAXN];
inline int MAX(int a,int b){ return (a>b)?a:b; }
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
bool test(int volumn){
  int remM=man_num-1, rem_v=volumn;
  for(int i=0;i<book_num;i++){
    if(book[i]>rem_v)
      if(remM==0) return false;
      else  rem_v=volumn, remM--;
    rem_v-=book[i];
  }
  return true;
}
int main(){

  for(scanInt(caseN); caseN--; ){
    scanInt(book_num),
    scanInt(man_num);
    long nL=0, nR=0, nM;
    for(int i=0;i<book_num;i++)
      scanInt(book[i]),
      nL=MAX(nL,book[i]),
      nR+=book[i];
    // 想辦法維持在『合法』的範圍內
    for(nM=(nL+nR)>>1; nR>nL;){
      nM=(nL+nR)>>1;
      if(test(nM)) // <- 目前這個數值是合法，所以往左縮一半
        nR=nM;
      else // <- 目前這個數值是不合法，所以往右縮一半且+1
        nL=nM+1;
    }
    // 根據格式要求輸出(最難的地方...)
    /* 題目要求index越大的員工所分配的書要盡量的多，因此分配書的時候index從後面開始，
     * 但注意分配時每個人至少要有一本書，因此如果(剩下的書<=剩下的人)，就算那個人還沒分完，
     * 也要直接換下一個人。
     */
    vector<int> ans;
    long rem_v=nL;
    int book_idx=book_num-1;
    for(man_num--; book_idx>=man_num;book_idx--){
      if(book[book_idx]>rem_v)
        ans.push_back(-1),
        man_num--, rem_v=nL;
      ans.push_back(book[book_idx]),
      rem_v-=book[book_idx];
    }
    for(;book_idx>=0;book_idx--)
      ans.push_back(-1),
      ans.push_back(book[book_idx]);
    printf("%d",ans.back());
    for(int i=ans.size()-2;i>=0;i--)
      if(ans[i]==-1) printf(" /");
      else printf(" %d",ans[i]);
    puts("");
  }
}
/*
2
9 3
100 200 300 400 500 600 700 800 900
5 4
100 100 100 100 100
*/