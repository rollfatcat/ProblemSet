// Greedy：利用PriorityQueue實現
// 每次都選取『當每個營地比目前的數量多塞一個帳篷時間距』最大的狀態
#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1);
int R[10];
int N[10];
int circle, camp;
struct PAIR{
  int id; double dis;
  PAIR(int a=0,double b=0):id(a),dis(b){}
  // (1) overload operator "less than", but unable to overload "greater than" 
  // bool operator<(const PAIR &rhs)const{ return dis<rhs.dis; }
};
// (2) 利用strcut定義比較方式()：，而非定義大於
struct COMP{
  bool operator()(const PAIR &lhs,const PAIR &rhs){ return lhs.dis>rhs.dis; }
};
// (3) overload opertor "greater than" in global domain
bool operator> (const PAIR &lhs,const PAIR &rhs){ return lhs.dis<rhs.dis; }

int main(){
  double DIS[10];
  while(scanf("%d %d",&circle,&camp) and circle){
    camp-=circle;

	// ##### 主要差異：三種不同的宣告方法 #####
    // (1) overload "less than" in struct
    // priority_queue<PAIR,vector<PAIR>> PQ;
    // (2) functional class
    // priority_queue<PAIR,vector<PAIR>,COMP> PQ;
    // (3) 
    priority_queue<PAIR,vector<PAIR>,greater<vector<PAIR>::value_type>> PQ;
    
    /* 初始化
     * 讀取每個營地的半徑(計算周長)，並且在 PriorityQueue 放入當『營地存在兩個帳篷時的間距』=周長的一半
     */
    for(int i=0;i<circle;i++)
      scanf("%d",&R[i]),
      N[i]=1,
      DIS[i]=2.0*R[i]*PI,
      PQ.push(PAIR(i,DIS[i]/2.0));
    // 每次取出『多塞一個帳篷時』最大的間距，並更新他的值
    while(camp--){
      PAIR now=PQ.top(); PQ.pop();
      N[now.id]++;
      PQ.push( PAIR(now.id, 2.0*PI*R[now.id]/(N[now.id]+1) ) );
    }
    for(int i=0;i<circle;i++)
      printf("%d ",N[i]);
    puts("");
  }
}{
  double DIS[10];
  while(scanf("%d %d",&circle,&camp) and circle){
    camp-=circle;

    // 紀錄當每個營地比目前的數量多塞一個帳篷時間距
    priority_queue<PAIR,vector<PAIR>> PQ;
    /* 初始化
     * 讀取每個營地的半徑(計算周長)，並且在 PriorityQueue 放入當『營地存在兩個帳篷時的間距』=周長的一半
     */
    for(int i=0;i<circle;i++)
      scanf("%d",&R[i]),
      N[i]=1,
      DIS[i]=2.0*R[i]*PI,
      PQ.push(PAIR(i,DIS[i]/2.0));
    // 每次取出『多塞一個帳篷時』最大的間距，並更新他的值
    while(camp--){
      PAIR now=PQ.top(); PQ.pop();
      N[now.id]++;
      PQ.push( PAIR(now.id, 2.0*PI*R[now.id]/(N[now.id]+1) ) );
    }
    for(int i=0;i<circle;i++)
      printf("%d ",N[i]);
    puts("");
  }
}
/*
2 4
6 3
*/