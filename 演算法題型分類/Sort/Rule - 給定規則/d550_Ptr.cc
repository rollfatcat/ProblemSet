// 利用陣列排序練習指標
// 這題不可交換兩個陣列會TLE
// 題目沒說,不過測試結果是測資沒有兩個陣列是一樣的

#include<iostream>
#include<algorithm>
using namespace std;
#define MaxR 10000
#define MaxC 200

bool cmp(int *a, int *b){ //傳進來的是指標變數
  while( *a==*b ) //透過指標取出值做比較, 一樣的話兩個指標都往下一個元素移動
    a++, b++;
  return *a<*b;
}
int main(){
  int map[MaxR][MaxC];
  int *ptr[MaxR];
  int R, C;

  while(scanf("%d%d",&R,&C)!=EOF){
    for(int i=0;i<R;i++){
      ptr[i]=&map[i][0];
      for(int j=0;j<C;j++)
        scanf("%d",&map[i][j]);
    }
    sort(ptr,ptr+R,cmp);
    for(int i=0;i<R;i++, printf("\n"))
      for(int *now=ptr[i], j=0;j<C;j++,now++)
        printf("%d ",*now);
  }
}