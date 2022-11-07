// 題目同b584，DP解選最小Cost
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 100000

int num[MaxN];
bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int N;scanInt(N);){
    if(N==1){  scanInt(num[0]); printf("%d\n",num[0]); continue; }
    for(int i=0;i<N;i++)
      scanInt(num[i]);
    // 需要先排序方便之後的解法
    sort(num,num+N);
    long sum=0;
    // 觀察題目給的兩個範例可以發現以下的狀態轉換規則：
    // 取最小時間: (1) AB->A->CD->B (2) AD->A->AC->A
    /* A：通過吊橋【最低】的時間成本
     * B：通過吊橋【次低】的時間成本
     * C：通過吊橋【次高】的時間成本
     * D：通過吊橋【最高】的時間成本
     */
    for(N--; N>=3; N-=2) // 每一輪可以送兩個人到對岸，直到剩下三人以下時做討論
      sum+=min(num[1]+num[0]+num[N]+num[1], num[N]+num[0]+num[N-1]+num[0]);
    if(N==2)  sum+=(num[2]+num[0]+num[1]);    //若三個人時, AC->A->AB故C+A+B
    else if(N==1)sum+=num[1];    //若兩個人時, AB故B
    cout<<sum<<endl;
  }
}