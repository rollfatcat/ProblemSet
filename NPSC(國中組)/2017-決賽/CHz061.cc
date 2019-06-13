// 注意Case：當所有的submission時間可能都小於180s以內
// 題目輸入保證：會依照ID和時間都會由小到大輸入

#include<iostream>
using namespace std;

bool board[28][7]={};
int main(){
  int N, ID, team, moment;
  string problem, status;
  cin>>N;
  while(N--){
    cin>>ID>>team>>moment>>problem>>status;
    if(moment>=180) break;
    if(board[team-1][problem[0]-'A']==0 and status=="AC")
      board[team-1][problem[0]-'A']=1,
      cout<<"Send balloon of "<<problem<<" to team "<<team<<" at time "<<moment<<"."<<endl;
  }
  cout<<"Go get snacks."<<endl;
}