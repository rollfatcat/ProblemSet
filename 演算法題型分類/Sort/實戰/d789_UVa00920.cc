// 找dominated point作法同 ZJ-d555
// 找出所有 dominated point 後根據比例計算長度(不須考慮精確度)
#include<bits/stdc++.h>
using namespace std;

pair<int,int> point[100];
inline double DIS(int p,int nowh){
  double dx=point[p+1].first-point[p].first;
  double dy=point[p+1].second-point[p].second;
  double s=sqrt(dx*dx+dy*dy)*(point[p].second-nowh)/(point[p].second-point[p+1].second);
  return s;
}
int main(){
  int caseT, N, x, y;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
      scanf("%d %d",&point[i].first,&point[i].second);
    sort(point,point+N);

    double len=0.0;
    int nowh=point[N-1].second;
    for(int i=N-2;i>=0;i--)
      if(point[i].second>nowh)
        len+=DIS(i,nowh),
        nowh=point[i].second;;
    printf("%.2lf\n",len);
  }
}
/*
2
11
1100 1200
0 500
1400 100
600 600
2800 0
400 1100
1700 600
1500 800
2100 300
1800 700
2400 500
2
0 1000
1000 0
*/