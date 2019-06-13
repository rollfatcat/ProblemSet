// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4276967
/* 因為給定的 nowB 不一定是正整數，我們需要將 nowB 質因數分解為 P1^C1 × P2^C2 …… 的形式，
 * 其中 Pi 是質數、Ci 是非負整數， i 為正整數。
 * 而題目所求為找到最大的 p 使得 m^p 整除 n! ，
 * 因此我們把以上質因數分解出來的每個質數去算ｎ÷Pi＋ｎ÷(Pi^２)＋ｎ÷(Pi^３)……，並把此數除以Ci取商。
 * 以上是為每個質因數，找到各自的最大可能的 p。從中取最小的可能 p，才是題目所求。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10000;
int main(){
  // 題目最多問到 10000! 所以只要存100以內的25個質數做質數判斷即可
  int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

  int T, nowN, nowB;
  scanf("%d",&T);
  for(int caseN=1;caseN<=T;caseN++){
    printf("Case %d:\n",caseN);
    scanf("%d %d",&nowB,&nowN);
    int ans=1<<30;
    for(int Pcnt,i=0;i<25 and nowB;i++){
      for(Pcnt=0;nowB%prime[i]==0;nowB/=prime[i],Pcnt++);
      if(Pcnt){
        int cnt=0;
        for(int base=prime[i]; base<=nowN; base*=prime[i])
          cnt+=(nowN/base);
        ans=min(ans,cnt/Pcnt);
      }
    }
    if(nowB>1) // 此時若nowB沒被100以內的質數除光代表他必定是個質數且平方會超過1e4
      ans=min(ans,nowN/nowB);

    if(ans==0) puts("Impossible to divide");
    else printf("%d\n",ans);
  }
}