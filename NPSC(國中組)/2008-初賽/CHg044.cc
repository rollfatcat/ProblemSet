// 練習 Sort 的自訂順序
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct Team{ string name; int score, get, loss; } team[8];
bool compare(Team a, Team b){
  if(a.score!=b.score)return a.score>b.score;
  if(a.get!=b.get)    return a.get>b.get;
  if(a.loss!=b.loss)  return a.loss<b.loss;
  return a.name<b.name;
}
int main(){
  int caseNum, s1, s2;
  string ss, t1, t2;

  cin>>caseNum;
  while(caseNum--){
    map<string, int> Book;
    for(int i=0;i<8;i++)
      cin>>team[i].name,  team[i].score=team[i].get=team[i].loss=0,
      Book[team[i].name]=i;
    for(int i=0;i<12;i++){
      cin>>t1>>s1>>s2>>t2;
      team[ Book[t1] ].get+=s1, team[ Book[t2] ].loss+=s1,
      team[ Book[t2] ].get+=s2, team[ Book[t1] ].loss+=s2;
      if(s1>s2)       team[ Book[t1] ].score+=3;
      else if(s1<s2)  team[ Book[t2] ].score+=3;
      else  team[ Book[t1] ].score+=1, team[ Book[t2] ].score+=1;
    }
    sort(team,team+4,compare);
    sort(team+4,team+8,compare);
    cout<<"A1 "<<team[0].name<<endl<<"A2 "<<team[1].name<<endl;
    cout<<"B1 "<<team[4].name<<endl<<"B2 "<<team[5].name<<endl;

    cout<<"BEST3 "<<( (compare(team[2],team[6]))?team[2].name:team[6].name )<<endl;

  }
}