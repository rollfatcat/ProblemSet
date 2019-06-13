// 規律觀察：先找出『內部正方形的邊長』，根據邊長決定外圍的座標變化方式
// (1)內部邊長是偶數，外圍屬於奇數，先照直的往下放之後再往左
// (2)內部邊長是奇數，外圍屬於偶數，先照橫的往右放之後再往上
#include<bits/stdc++.h>
using namespace std;

int main(){
  int Nsz, No, rem;
  while(scanf("%d",&No) and No){
    Nsz=sqrt(No),
    Nsz-=(No==Nsz*Nsz);
    rem=No-Nsz*Nsz, Nsz++;
    if(Nsz&1){
      if(rem>Nsz) printf("%d %d\n",Nsz-(rem-Nsz),Nsz);
      else        printf("%d %d\n",Nsz,rem);
    }
    else{
      if(rem>Nsz) printf("%d %d\n",Nsz,Nsz-(rem-Nsz));
      else        printf("%d %d\n",rem,Nsz);
    }
  }
}