// 難點：題目需要輸出合併方式(有多組答案時盡量讓左邊括號內多放入陣列)
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define MaxN 10

int N;
int R[MaxN], C[MaxN];
int map[MaxN][MaxN];
int mid[MaxN][MaxN];
int TD(int st,int ed){
  if(map[st][ed]==0x7fffffff){
    for(int i=st;i<ed;i++){
      int cost=TD(st,i)+TD(i+1,ed)+C[i]*R[st]*C[ed];
      if(map[st][ed]>=cost)
        map[st][ed]=cost, mid[st][ed]=i;
    }
  }
  return map[st][ed];
}
void CoutPath(int st, int ed){
  if(st==ed){
    cout<<'A'<<st+1;
    return;
  }
  cout<<'(';
  CoutPath(st,mid[st][ed]);
  cout<<" x ";
  CoutPath(mid[st][ed]+1,ed);
  cout<<')';
}
int main(){
  for(int caseNum=1;cin>>N and N;caseNum++){
    for(int i=0;i<N;i++)
      cin>>R[i]>>C[i];
    for(int i=0;i<N;i++){
      map[i][i]=0;
      mid[i][i]=i;
      for(int j=i+1;j<N;j++)
        map[i][j]=0x7fffffff;
    }
    TD(0,N-1);
    cout<<"Case "<<caseNum<<": ";
    CoutPath(0,N-1);
    cout<<endl;
  }
}