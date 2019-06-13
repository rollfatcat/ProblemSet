// 競賽題：精確度導致，精確度低的先互乘，不然後面會有受影響

#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int caseNum, n;
  double p, cost[2];
  cin>>caseNum;
  while(caseNum--){
    cin>>n>>p;
    cost[0]=ceil( (n>>1)*p*0.6+( (n>>1)+(n&1) )*p );
    cost[1]=ceil( n*p*0.812 );
    if(cost[0]<cost[1])
      cout<<": )"<<endl;
    else if(cost[0]>cost[1])
      cout<<"8-12=-4"<<endl;
    else //cost[0]==cost[1]
    cout<<"SAME"<<endl;
  }
}