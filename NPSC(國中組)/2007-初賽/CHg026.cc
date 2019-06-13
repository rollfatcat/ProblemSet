// 時間計算, struct自定義的練習
#include<iostream>
using namespace std;

struct Time{
  int h, m;
} st, ed, away, tmp;
Time TimeMinus(Time a, Time b){
  Time tmp;
  tmp.m=a.m-b.m;
  tmp.h=a.h-b.h;
  if(tmp.m<0)
    tmp.h--,  tmp.m+=60;
  if(tmp.h<0)
    tmp.h+=24;
  return tmp;
}

int main(){
  int caseNum, cnt;
  string ss;
  char ch;

  cin>>caseNum;
  while(caseNum--){
    cin>>cnt>>st.h>>ch>>st.m>>ed.h>>ch>>ed.m;
    while(cnt--){
      cin>>ss>>away.h>>ch>>away.m;
      tmp=TimeMinus(st,away);
      printf("%02d:%02d ",tmp.h,tmp.m);
      tmp=TimeMinus(ed,away);
      printf("%02d:%02d\n",tmp.h,tmp.m);
    }
  }
}