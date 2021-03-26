#include<iostream>
#include<cmath>
using namespace std;
#define MaxS 101

int main(){
  int H, W, x, maxL;
  int map[MaxS][MaxS];
  for(int i=0;i<MaxS;i++)
    map[i][0]=map[0][i]=0;

  while(cin>>H>>W){
    maxL=0;
    for(int i=1;i<=H;i++)
      for(int j=1;j<=W;j++){
        cin>>x;
        map[i][j]=(x==0)?( min(min(map[i-1][j],map[i][j-1]),map[i-1][j-1])+1):0;
        if(maxL<map[i][j])
          maxL=map[i][j];
      }
    cout<<(maxL*maxL)<<endl;
  }
}