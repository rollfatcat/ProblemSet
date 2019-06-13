// 題解：http://morris821028.github.io/2014/04/18/oj/zj/a858/
// 雖然這題沒用到DP但是扣除的計算方式也是常見於DP當中題目的c434
/* O(n^3)窮舉3個點檢查是不是同色邊三角形會TLE
 * 必須是O(n^2)=全部扣除異色邊三角形，
 * 異色邊三角形：固定一個點計算黑/紅邊個數後相乘除以2
 * 上述的方法可以奏效是因為邊只有2種顏色，一但交於同一個點的邊不同色
 * 第三邊必定同色於某一邊，導致這個三角形必定會被重複計算2次，所以除以2
 */
#include<iostream>
using namespace std;
// 扣除法(9ms)
int main(){
  int N;
  scanf("%d",&N); getchar();
  int p=N*(N-1)*(N-2)/6, different=0;
  for(int i=0;i<N;i++){
    int red=0, black=0;
    for(int j=0;j<N;j++){
      char color=getchar(); getchar();
      if(color=='1') red++;
      else if(color=='2') black++;
    }
    different+=(red*black/2);
  }
  printf("%d",p-different);
}
// 直接窮舉3個點判斷三邊是否同色(60%)
/*
int main(){
  int N;
  scanf("%d",&N); getchar();
  bool color[1000][1000];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      char ch=getchar(); getchar();
      color[i][j]=(ch=='2');
    }
  int cnt=0;
  for(int a=0;a<N;a++)
    for(int b=a+1;b<N;b++)
      for(int c=b+1;c<N;c++)
        if(color[a][b]==color[b][c] and color[a][b]==color[a][c] and color[a][c]==color[b][c])
          cnt++;
  printf("%d\n",cnt);
}
*/