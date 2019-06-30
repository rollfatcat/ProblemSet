#include<bits/stdc++.h>
using namespace std;

const long one=1;
const long one_grd=15;
const long all_one=-1;
struct DATA{
  short space, step;
  unsigned long status;
  DATA(int d=0,int p=0,long s=0):step(d),space(p),status(s){}
} nowS;

inline void ShowBoard(unsigned long s);
inline long Status_Change(unsigned long s,short now_pos,short nxt_pos);

int main(){
  unsigned long now_board=0;
  for(unsigned long i=0;i<16;i++)
    now_board|=i<<(i<<2);
  
  // now_board=1147797409030816545
  map<unsigned long,short> rec;
  rec[now_board]=0;

  queue<DATA> Q;
  Q.push(DATA(0,14,now_board));
  while(Q.empty()==0){
    nowS=Q.front(), Q.pop();
    if( (nowS.space&3)>0 ){
      now_board=Status_Change(nowS.status,nowS.space,nowS.space-1);
      if(nowS.step<20 and rec.find(now_board)==rec.end())
        Q.push(DATA(nowS.step+1,nowS.space-1,now_board)),
        rec[now_board]=nowS.step+1;
    }
    if( (nowS.space&3)<3 ){
      now_board=Status_Change(nowS.status,nowS.space,nowS.space+1);
      if(nowS.step<20 and rec.find(now_board)==rec.end())
        Q.push(DATA(nowS.step+1,nowS.space+1,now_board)),
        rec[now_board]=nowS.step+1;
    }
    if( (nowS.space>>2)>0 ){
      now_board=Status_Change(nowS.status,nowS.space,nowS.space-4);
      if(nowS.step<20 and rec.find(now_board)==rec.end())
        Q.push(DATA(nowS.step+1,nowS.space-4,now_board)),
        rec[now_board]=nowS.step+1;
    }
    if( (nowS.space>>2)<3 ){
      now_board=Status_Change(nowS.status,nowS.space,nowS.space+4);
      if(nowS.step<20 and rec.find(now_board)==rec.end())
        Q.push(DATA(nowS.step+1,nowS.space+4,now_board)),
        rec[now_board]=nowS.step+1;
    }
  }
  printf("%lu\n",rec.size());
}

inline void ShowBoard(unsigned long s){ //輸出盤面
  for(int i=15;i>=0;i--,s>>=4){
    printf("%2ld ",s&15);
    if((i&3)==0) puts("");
  }
  puts("");
}
inline long Status_Change(unsigned long s,short now_pos,short nxt_pos){
  now_pos<<=2, nxt_pos<<=2;
  unsigned long now_num=(s&(one_grd<<now_pos))>>now_pos,
       nxt_num=(s&(one_grd<<nxt_pos))>>nxt_pos;
  s&=all_one^(one_grd<<now_pos)^(one_grd<<nxt_pos),
  s|=(nxt_num<<now_pos)|(now_num<<nxt_pos);
  return s;
}