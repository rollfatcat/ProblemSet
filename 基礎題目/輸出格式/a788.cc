#include<iostream>
#include<cmath>
using namespace std;

inline double DIS(double x, double y){ return sqrt(x*x+y*y); }
int main(){
  for(int x[4],y[4]; true;){
    scanf("%d %d %d %d %d %d %d %d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]);
    if(x[0]==0.0 and x[1]==0.0 and x[2]==0.0 and x[3]==0.0) break;
    int dis[2]={(x[1]+x[3]-x[0]-x[2])/2,(y[1]+y[3]-y[0]-y[2])/2};
    double scale=DIS(x[1]-x[3],y[1]-y[3])/DIS(x[0]-x[2],y[0]-y[2]);
    double m1=((double)y[2]-y[0])/(x[2]-x[0]),
           m2=((double)y[3]-y[1])/(x[3]-x[1]);
    // 精確度會出現 -0.00
    double t=atan((m2-m1)/(1+m1*m2));
           t=(abs(t-0.0)<1e-3)?0.0:t;
    printf("%d %d %.3lf %.3f\n",dis[0],dis[1],scale,t);
  }
}