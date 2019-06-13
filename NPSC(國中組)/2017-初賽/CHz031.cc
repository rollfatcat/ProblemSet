// 賓果遊戲：當『形成一條線時』就停止填格子，每填一格可以獲得一分，最後輸出依據分數和ID印出

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct MAN{
  bool end, black[5][5];
  short ID, score;
  pair<short,short> bingo[26];
  bool operator<(const MAN &rhs)const{ return score<rhs.score or score==rhs.score and ID<rhs.ID; }
  bool CheckEnd(int x,int y,int i=0){
    for(i=0;i<5 and black[i][y];i++);
    if(i==5) return true;
    for(i=0;i<5 and black[x][i];i++);
    if(i==5) return true;
    for(i=0;i<5 and black[i][i];i++);
    if(i==5) return true;
    for(i=0;i<5 and black[i][4-i];i++);
    return (i==5);
  }
}student[30];
int main(){
  short N, number, now_x, now_y;
  short answer;

  cin>>N;
  for(int i=0;i<N;i++){
    student[i].ID=i+1;
    student[i].end=0;
    student[i].score=0;
    for(int j=0;j<5;j++)
      for(int k=0;k<5;k++)
        cin>>number,
        student[i].bingo[number]=make_pair(j,k);
  }
  for(int i=0;i<25;i++){
    cin>>answer;
    for(int j=0;j<N;j++)
      if(student[j].end==0){
        student[j].score++,
        now_x=student[j].bingo[answer].first,
        now_y=student[j].bingo[answer].second,
        student[j].black[ now_x ][ now_y ]=1,
        student[j].end=student[j].CheckEnd(now_x,now_y);
      }
  }
  sort(student,student+N);
  vector<short> menu[25];
  for(int i=0;i<N;i++)
    menu[ student[i].score ].push_back(student[i].ID);
  for(int i=4;i<25;i++)
    if(menu[i].size()){
      cout<<i<<':';
      for(int j=0;j<menu[i].size();j++)
        cout<<' '<<menu[i][j];
      cout<<endl;
    }
}