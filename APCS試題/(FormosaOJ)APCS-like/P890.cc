/* 模擬(有標明規則，但規則複雜且題目提供的測資簡單)
 * 把所有離起飛時間剩不到30分鐘(T_takeoff−T_now ≤ 30) 的旅客從一般佇列晉升到優先佇列
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
  int arrive, take_off, todoor, TimePQ;
  TRAV(int a=0,int t=0,int g=0,int tq=0):arrive(a),take_off(t),todoor(g),TimePQ(tq){}
  bool ToPQ(int Tnow){ return TimePQ<=Tnow; }
};

// 模擬時間經過，一旦起飛時間小於30分鐘就將該旅客晉升到優先佇列
vector<TRAV> NQ;// 維護一般佇列的順序：
queue<TRAV>  PQ;// 維護優先佇列的順序：先到先處理

/* 模擬在時間 Tnow 時會發生的事：
 * (1) 檢查一般佇列中有沒有要晉升到優先佇列的旅客
 * (2) 假設有海關在運作則先清空優先佇列
 * (3) 假設有海關在運作則再清空一般佇列
 */
void TimePass(int &Tnow,int &delay_cnt){
  // 統計在這個時刻『正在運作』的海關數量
  int buff=0;
  for(int i=0;i<K;i++)
    buff+=custom[i].IsOpen(Tnow);
  // (1)掃描整個vector看有沒有旅客已到達起飛時間前30分鐘，假若有則從一般佇列剔除放入優先佇列
  //    實作細節：當掃描到『某位旅客可以晉升』時將他從一般佇列移除但此時指標不會往後移動否則往下一個檢查
  for(int idx=0; idx<NQ.size(); )
    if(NQ[idx].ToPQ(Tnow))
      PQ.push(NQ[idx]),
      NQ.erase(NQ.begin()+idx);
    else
      idx++;
  // (2)假設有海關在運作則先清空優先佇列
  while(buff and PQ.empty()==0){
    TRAV now_trav=PQ.front(); PQ.pop();
    if(now_trav.todoor+Tnow>=now_trav.take_off) // 通關時需要花一秒所以『剛好』時也算遲到
      delay_cnt++;
    buff--;
  }
  // (3)假設有海關在運作則再清空一般佇列
  //    實作細節：從前端開始移除旅客並讓海關數量-1
  while(buff and NQ.empty()==0){
    if(NQ[0].todoor+Tnow>=NQ[0].take_off) // 通關時需要花一秒所以『剛好』時也算遲到
      delay_cnt++;
    NQ.erase(NQ.begin());
    buff--;
  }
}

int main(){

  int work, rest;
  scanf("%d %d",&N,&K);
  for(int i=0;i<K;i++)
    scanf("%d %d",&work,&rest),
    custom[i]=CUST(work,rest);

  // 先讀取第一位旅客直接將他放入一般佇列，此時時間從第一位旅客到的時間開始計算
  int arrive, take_off, todoor;
  scanf("%d %d %d",&arrive,&take_off,&todoor);
  NQ.push_back(TRAV(arrive,take_off,todoor,take_off-30));

  // 處理下一位客人前，模擬這段時間內的海關可以處理兩個佇列內的旅客
  int Tnow=arrive, delay_cnt=0;
  for(int i=1;i<N;i++){ // 題目保證 a1 < a2 < ... < aN
    scanf("%d %d %d",&arrive,&take_off,&todoor);
    while(Tnow<arrive)
      TimePass(Tnow,delay_cnt),
      Tnow++;
    // 所有旅客剛抵達海關的時候都會被加進一般佇列的尾端
    NQ.push_back(TRAV(arrive,take_off,todoor,take_off-30));
  }
  // 繼續模擬時間經過，直到兩個佇列都清空為止
  while(PQ.empty()==0 or NQ.empty()==0)
    TimePass(Tnow,delay_cnt),
    Tnow++;
  printf("%d\n",delay_cnt);
}
/*
5 3
3 3
5 5
10 10
1 30 29
2 100 97
16 50 30
17 49 30
18 60 20
*/