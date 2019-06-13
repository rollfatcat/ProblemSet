// 輸出兩組圓的面積差(水題，連精確度都不用)
#include<iostream>
#include<cmath>
using namespace std;
#define esp 1e-8
const double PI=3.14159;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  double sumR1, sumR2, x;
  for(int n1,n2,i; cin>>n1;){
    for(i=sumR1=0; i<n1; i++)
      cin>>x, x/=2, sumR1+=x*x;
    cin>>n2;
    for(i=sumR2=0; i<n2; i++)
      cin>>x, x/=2, sumR2+=x*x;
    printf("%.2lf\n",abs(sumR1-sumR2)*PI);
  }
}