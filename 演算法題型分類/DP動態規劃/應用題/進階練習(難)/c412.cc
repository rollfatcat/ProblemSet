/* Demo : OwwOOwOwOww
 * 從以上的例子可以看到，讀到'w'時，就把潛在的可能數(一開始為0)加上前面有多少個'O'之數目
 * 而讀到'O'時，把方法數(一開始也是0)加上剛剛算出的可能數，然後把遇到過的 #'O'+1。（記得每一步驟都要取餘數）
 */
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main(){
  int N;
  scanf("%d",&N), getchar();
  while(N--){
    int Os=0, Ws=0, cnt=0;
    for(char buffer; (buffer=getchar())!='\n'; )
      if(buffer=='O')   cnt=(cnt+Ws)%mod, Os++;
      else if(buffer=='w')  Ws=(Ws+Os)%mod;
    printf("%d\n",cnt);
  }
}
/*
3
OwOwOb
aObwcOd
OwwOOwOwOww
*/