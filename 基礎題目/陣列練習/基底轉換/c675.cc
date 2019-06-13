// 這個做法是利用陣列預先把所有號碼儲存起來
// 但是看到加強版本的 c677 可以發現這樣的方法其實會有記憶體問題
// c677 的方式是將這個題目當作種 10 進位轉和 9 進位制之間的轉換問題
#include<stdio.h>
#include<stdbool.h>

bool include4(int x){
  for( ;x;x/=10)
    if(x%10==4)
      return true;
  return false;
}
int main(){
  int T[10001], F[15752];
  for(int i=1, j=1;i<=10000;j++)
    if(include4(j)==false)
      T[i]=j, F[j]=i++;
  char c;
  int n;
  while(scanf("%c%d",&c,&n)!=EOF)
    getchar(),  printf("%d\n",(c=='T')?T[n]:F[n]);
}