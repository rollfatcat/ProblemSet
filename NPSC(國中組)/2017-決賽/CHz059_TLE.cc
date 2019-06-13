// 暴力法(80%＋20%TLE)

#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100005

int org[MAXN];
short GCD[101][101];
int main(){
  for(int i=1;i<=100;i++){
    GCD[i][i]=i;
    for(int j=i+1;j<=100;j++)
      GCD[i][j]=GCD[j][i]=__gcd(i,j);
  }
  int N, K;
  cin>>N>>K;

  long long cnt=0;
  for(int i=0;i<N;i++){
    scanf("%d",&org[i]);
    int now=i, num=K;
    while(now>=0 and num>1)
      num/=GCD[num][org[now]], now--;
    if(num==1) now++;
    cnt+=now+1;
  }
  cout<<cnt<<endl;
}