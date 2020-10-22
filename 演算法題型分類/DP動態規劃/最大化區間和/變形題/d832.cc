// 題目求『兩段』的"連續元素和"，總和最大 => (理論上可以)類推到求Ｋ段的"連續元素和"，總和最大
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1322223684
#include<bits/stdc++.h>
using namespace std;

int number[10001];  // 原始資料
int maxn[10][10001]; // 當線段數=第一個維度的數值時，Ｋ段連續和的最大加總
int *cont=&maxn[0][0]; // 儲存暫時的連續和

inline void showArr(int H,int width){
  puts("");
  for(int h=0;h<=H;h++,puts(""))
    for(int i=0;i<width;i++)
      printf("%2d ",maxn[h][i]);
}
int main(){
  // 這題只需要求第一段+第二段最大的連續和
  int seg_num=2;
  for(int ballnum,pay; scanf("%d %d",&ballnum,&seg_num)==2;){
    // 因為maxn[0]這個一維陣列被拿來紀錄連續和(cont)，並算出第一段最大的連續和
    for(int i=0;i<ballnum;i++)
      scanf("%d",&number[i]);
    maxn[1][0]=maxn[0][0]=number[0];
    for(int i=1;i<ballnum;i++)
      cont[i] = max(cont[i-1],0)+number[i],
      maxn[1][i] = max(cont[i],maxn[1][i-1]);
    //showArr(1,ballnum);
    //
    for(int seg=2;seg<=seg_num;seg++){
      // 從第 seg 個數字強迫選取
      maxn[seg][seg-1]=maxn[0][seg-1]=maxn[seg-1][seg-2]+number[seg-1];
      for(int i=seg;i<ballnum;i++)
        cont[i]=max(cont[i-1],maxn[seg-1][i-1])+number[i],
        maxn[seg][i]=max(cont[i],maxn[seg][i-1]);
      //showArr(seg,ballnum);
    }
    //
    printf("%d\n",maxn[seg_num][ballnum-1]);
  }
}
/*
9 3
 2 -1  4  3 -5  5 -4  6  7
5 2
 2 -1  4 -3  2
5  3
 2 -3  4 -1  2
*/