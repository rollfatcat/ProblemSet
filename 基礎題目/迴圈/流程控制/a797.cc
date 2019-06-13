// 流程控制的簡單模擬題(需要花時間看懂內容說明)
// 借題說明：相除時要特別注意型態問題(這題輸入是百分比，而所有交通工具的原始票價都是100的倍數所以計算時可以用整數)

#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
int main(){
  char ss[3][10]={"Bus","Train","HSR"};
  int cost[3]={400,600,1000};
  int TimeJudge[24]={0,0,0,0,0,0,2,2,2,1,1,1,1,1,0,0,1,2,2,1,1,0,0,0};

  int caseT, Money, LeaveTime, offset;

  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d",&Money,&LeaveTime);
    LeaveTime=TimeJudge[LeaveTime];
    int pay=INF, chosen=-1;
    for(int traffic=0;traffic<=2;traffic++)
      for(int level=0;level<=2;level++){
        scanf("%d",&offset);
        int ticket=cost[traffic]*offset;
        if(level==LeaveTime and ticket<=pay)
          pay=ticket,
          chosen=traffic;
      }
    if(pay>Money*100) puts("Walk home");
    else puts(ss[chosen]);
  }
}