/* 注意：前入圍1/3的選手排序依據是名單出現順序不是誰花的時間比較少!!
 */
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 1001

struct Usr{ string name; double t; } usr[MaxN];
double base[12]={36000,3600,0,600,60,0,10,1,0,0.1,0.01,0.001};
double StringToTime(string s){
  double t=0;
  for(int i=0;i<s.length();i++)
    t+=( (s[i]-'0')*base[i] );
  return t;
}
int main(){
  int N;
  double record[MaxN];
  string t;

  while(cin>>N and N){
    for(int i=0;i<N;i++){
      cin>>usr[i].name>>t;
      record[i]=usr[i].t=StringToTime(t);
    }
    sort(record,record+N);
    double boundary=record[N/3-1];
    cout<<"LIST START"<<endl;
    for(int i=0;i<N;i++)
      if(usr[i].t<=boundary)
        cout<<usr[i].name<<endl;
    cout<<"LIST END"<<endl;
  }
}