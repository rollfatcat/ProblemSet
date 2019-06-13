// 需要思考一下排序規則的題目
// 吃越久的先煮,這個人吃的時間剛好可以cover煮的時間
#include<iostream>
#include<algorithm>
using namespace std;

struct Data{
  int C, E;
  bool operator<(const Data &other)const{ return(E==other.E)?(C>other.C):(E>other.E); }
} data[10000];
int main(){
  int N;

  while(cin>>N and N){
    for(int i=0;i<N;i++)
      cin>>data[i].C>>data[i].E;
    sort(data,data+N);
    int SumTime=0, MaxTime=0, tmpTime;
    for(int i=0;i<N;i++){
      SumTime+=data[i].C, tmpTime=SumTime+data[i].E;
      if(tmpTime>MaxTime)
        MaxTime=tmpTime;
    }
    cout<<MaxTime<<endl;
  }
}