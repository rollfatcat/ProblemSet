// 對於每組測資保證有解，輸出對應的L,W(W ≦ L),若有多組L,W解請輸出L,W值相差最大的那組解。
// (X) 針對內部矩形做因式分解找到所有因數
// (O) 枚舉邊長，只要能整除面積就是因數

#include<bits/stdc++.h>
using namespace std;
int MAXN=1<<30;

int main(){

  int inRec, border, x;
  while(scanf("%d%d",&border,&inRec)==2){
    int maxw=sqrt(inRec);
    for(int in_w=1; in_w<=maxw; in_w++){
      if(inRec%w) continue;
      int in_l=inRec/in_w;
      long sum=in_l+in_w;
      // 4T*T+2(w+l)*T=border => T存在整數解 => 公式解找到根後反帶回檢查是否相等
      long T=((long)sqrt(sum*sum+((long)border<<2))-sum)>>2;
      if((sum<<1)*T+((T*T)<<2)==border){
				printf("%ld %ld\n",l+(T<<1),w+(T<<1));
				break;
			}
    }
  }
}
