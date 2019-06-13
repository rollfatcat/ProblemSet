/* 模擬(有標明規則，但規則複雜且題目提供的測資簡單)
 * 把所有離起飛時間剩不到30分鐘(T_takeoff−T_now ≤ 30) 的旅客從一般佇列晉升到優先佇列
 * 60%AC+40%WA
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3;
const int MAXK=1e1;
int N; // 1 ≤ N ≤ 1000
int K; // 1 ≤ K ≤ 10
struct CUST{
  int work, rest, cycle;
  CUST(int w=0,int b=0):work(w),rest(b){ cycle=w+b; }
  bool IsOpen(int Tnow){ return 0<Tnow%cycle and Tnow%cycle<=work; }
} custom[MAXK];
struct TRAV{
  int arrive, take_off, todoor;
  TRAV(int a=0,int t=0,int g=0):arrive(a),take_off(t),todoor(g){}
  bool operator<(const TRAV &rhs)const{
    return take_off>rhs.take_off or take_off==rhs.take_off and arrive>rhs.arrive; }
};

// 模擬時間經過，一旦起飛時間小於30分鐘就將該旅客晉升
priority_queue<TRAV,vector<TRAV>> PQ; // 維護一般佇列的順序以起飛時間排序
queue<TRAV> Q;  // 維護優先佇列的順序：先到先處理

/* 模擬在時間 Tnow 時會發生的事：
 * (1) 檢查一般佇列中有沒有要晉升到優先佇列的旅客
 * (2) 假設有海關在運作則先清空優先佇列
 * (3) 假設有海關在運作則再清空一般佇列
 */
void TimePass(int &Tnow,int &delay_cnt){
  // 統計在這個時刻『正在運作』的海關數量
  int buff=0;
  for(int j=0;j<K;j++)
    buff+=custom[j].IsOpen(Tnow);
  // (1)檢查有沒有旅客會從一般佇列升級到優先佇列
  while(PQ.empty()==0 and Tnow+30>=PQ.top().take_off)
    Q.push(PQ.top()),
    PQ.pop();
  // (2)假設有海關在運作則先清空優先佇列
  while(buff and Q.empty()==0){
    TRAV now_trav=Q.front(); Q.pop();
    if(now_trav.todoor+Tnow>=now_trav.take_off) // 通關時需要花一秒所以『剛好』時也算遲到
      delay_cnt++;
    buff--;
  }
  // (3)假設有海關在運作則再清空一般佇列
  while(buff and PQ.empty()==0){
    TRAV now_trav=PQ.top(); PQ.pop();
    if(now_trav.todoor+Tnow>=now_trav.take_off) // 通關時需要花一秒所以『剛好』時也算遲到
      delay_cnt++;
    buff--;
  }
}

int main(){

  int work, rest;
  scanf("%d %d",&N,&K);
  for(int i=0;i<K;i++)
    scanf("%d %d",&work,&rest),
    custom[i]=CUST(work,rest);

  int Tnow=1, delay_cnt=0;
  int arrive, take_off, todoor;
  for(int i=0;i<N;i++){  // 題目保證 a1 < a2 < ... < aN
    scanf("%d %d %d",&arrive,&take_off,&todoor);
    // 計算和前一刻的時間間可以處理多少個旅客
    while(Tnow<arrive)
      TimePass(Tnow,delay_cnt),
      Tnow++;
    // 把這個時刻的旅客放入優先佇列
    // 避免出現同一個時間點等下插入的旅客卻優先於之前已經待在佇列的人(因為PQ的性質)
    while(PQ.empty()==0 and Tnow+30>=PQ.top().take_off)
      Q.push(PQ.top()),
      PQ.pop();
    // 所有旅客剛抵達海關的時候都會被加進一般佇列的尾端
    PQ.push(TRAV(arrive,take_off,todoor));
  }
  // 繼續模擬時間經過，直到兩個佇列都清空為止
  while(PQ.empty()==0 or Q.empty()==0)
    TimePass(Tnow,delay_cnt),
    Tnow++;
  printf("%d\n",delay_cnt);
}
