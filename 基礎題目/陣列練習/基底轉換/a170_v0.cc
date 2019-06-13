// 8進位轉16進位
// 讀取時直接處理,不是透過計算成10進位 => 0.2s
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int T;
  int x, y;

  for(scanf("%d",&T); T--;)
    scanf("%o %o",&x, &y),
    printf("%X\n",x+y);
}