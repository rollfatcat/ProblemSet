// 簡單模擬(不需要算循環來加速)
#include<iostream>
#include<cmath>
using namespace std;
#define MaxN 200

int judgeMap[5][5]={
  { 0,-1, 1, 1,-1},
  { 1, 0,-1, 1,-1},
  {-1, 1, 0,-1, 1},
  {-1,-1, 1, 0, 1},
  { 1, 1,-1,-1, 0}
};
int main(){
  int N, NA, NB, score[2];
  int A[MaxN], B[MaxN];
  while(cin>>N>>NA>>NB){
    for(int i=0;i<NA;i++)
      cin>>A[i];
    for(int i=0;i<NB;i++)
      cin>>B[i];
    score[0]=score[1]=0;
    for(int i=0;i<N;i++)
      if(judgeMap[ A[i%NA] ][ B[i%NB] ]>0)
        score[0]++;
      else if(judgeMap[ A[i%NA] ][ B[i%NB] ]<0)
        score[1]++;
    cout<<score[0]<<' '<<score[1]<<endl<<endl;
  }
}