// 枚舉 起點和終點分別屬於哪四個時段，計算每個時段的時間後統計費用
// 程式碼很長(要考慮的情況很多但核心想法是簡單)
#include<bits/stdc++.h>
using namespace std;

double rate[5][3]={ {0.10,0.06,0.02},
                    {0.25,0.15,0.05},
                    {0.53,0.33,0.13},
                    {0.87,0.47,0.17},
                    {1.44,0.80,0.30}};
const int AM08=480;
const int PM06=1080;
const int PM10=1320;
const int AM00=1440;
int main(){
  string level, phone_number;
  int start_hour, start_minute, end_hour, end_minute;

  while(cin>>level and level!="#"){
    cin>>phone_number>>start_hour>>start_minute>>end_hour>>end_minute;
    int level_number=level[0]-'A';
    start_minute+=start_hour*60,
    end_minute+=end_hour*60;
    int timeCnt[3]={0,0,0};
    double pay=0.0;
    // 分段處理
    if(AM08<=start_minute and start_minute<PM06){
      if(AM08<=end_minute and end_minute<PM06){
        if(start_minute<=end_minute)
          timeCnt[0]=end_minute-start_minute;
        else
          timeCnt[0]=PM06-start_minute+end_minute-AM08,
          timeCnt[1]=240,
          timeCnt[2]=600;
      }
      else if(PM06<=end_minute and end_minute<PM10)
        timeCnt[0]=PM06-start_minute,
        timeCnt[1]=end_minute-PM06;
      else if(PM10<=end_minute)
				timeCnt[0]=PM06-start_minute,
				timeCnt[1]=240,
				timeCnt[2]=end_minute-PM10;
			else
				timeCnt[0]=PM06-start_minute,
				timeCnt[1]=240,
				timeCnt[2]=120+end_minute;
    }
    else if(PM06<=start_minute and start_minute<PM10){
      if(AM08<=end_minute and end_minute<PM06)
        timeCnt[0]=end_minute-AM08,
        timeCnt[1]=PM10-start_minute,
        timeCnt[2]=600;
      else if(PM06<=end_minute and end_minute<PM10){
        if(start_minute<=end_minute)
          timeCnt[1]=end_minute-start_minute;
        else
          timeCnt[0]=600,
          timeCnt[1]=PM10-start_minute+end_minute-PM06,
          timeCnt[2]=600;
      }
      else if(PM10<=end_minute)
				timeCnt[1]=PM10-start_minute,
				timeCnt[2]=end_minute-PM10;
			else
				timeCnt[1]=PM10-start_minute,
				timeCnt[2]=120+end_minute;
    }
    else if(PM10<=start_minute){
      if(AM08<=end_minute and end_minute<PM06)
        timeCnt[0]=end_minute-AM08,
        timeCnt[2]=AM00-start_minute+AM08;
      else if(PM06<=end_minute and end_minute<PM10)
        timeCnt[0]=600,
        timeCnt[1]=end_minute-PM06,
        timeCnt[2]=AM00-start_minute+AM08;
      else if(PM10<=end_minute){
				if(start_minute<=end_minute)
          timeCnt[2]=end_minute-start_minute;
        else
				  timeCnt[0]=600,
          timeCnt[1]=240,
          timeCnt[2]=AM00-start_minute+end_minute-PM10;
      }
			else
				timeCnt[2]=AM00-start_minute+end_minute;
    }
    else{
      if(AM08<=end_minute and end_minute<PM06)
        timeCnt[0]=end_minute-AM08,
        timeCnt[2]=AM08-start_minute;
      else if(PM06<=end_minute and end_minute<PM10)
        timeCnt[0]=600,
        timeCnt[1]=end_minute-PM06,
        timeCnt[2]=AM08-start_minute;
      else if(PM10<=end_minute)
				timeCnt[0]=600,
				timeCnt[1]=240,
				timeCnt[2]=end_minute-PM10+AM08-start_minute;
			else{
				if(start_minute<=end_minute)
				  timeCnt[2]=end_minute-start_minute;
				else
				  timeCnt[0]=600,
				  timeCnt[1]=240,
				  timeCnt[2]=AM08-start_minute+end_minute+120;
			}
    }
    cout<<setw(10)<<phone_number;
    cout<<setw(6)<<timeCnt[0]<<setw(6)<<timeCnt[1]<<setw(6)<<timeCnt[2]<<setw(3)<<level;
    cout<<setw(8)<<fixed<<setprecision(2)<<(rate[level_number][0]*timeCnt[0]+rate[level_number][1]*timeCnt[1]+rate[level_number][2]*timeCnt[2])<<endl;
  }
}