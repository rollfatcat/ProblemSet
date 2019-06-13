// 直接做 Bottom-Up
#include<iostream>
#include<cmath>
using namespace std;

int n, dis, map[41][3];

int main(){
  while(cin>>n and n){
    cin>>dis;
    map[0][0]=0,  map[0][1]=dis, map[0][2]=2*dis;
    for(int i=1;i<n;i++){
      cin>>dis;
      map[i][0]=max( max(map[i-1][0],map[i-1][1]), map[i-1][2] );
      map[i][1]=max( map[i-1][0],map[i-1][1])+dis;
      map[i][2]=max( map[i-1][0],map[i-1][1])+2*dis;
    }
    cout<<max( max(map[n-1][0],map[n-1][1]), map[n-1][2] )<<endl;
  }
}