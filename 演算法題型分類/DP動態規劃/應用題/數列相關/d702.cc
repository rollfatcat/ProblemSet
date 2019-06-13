// 抓到規則後作大數加法
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 1002

int len[MaxN];
long long int num[MaxN][8];
long long int base=100000000000000000; //e17
void Add(int c,int a,int b){
  long long int carry=0;
  for(int i=0;i<len[b];i++){
    num[c][i]=num[a][i]+num[b][i]+carry;
    carry=num[c][i]/base;
    num[c][i]=num[c][i]%base;
  }
  for(int i=len[b];i<len[a];i++){
    num[c][i]=num[a][i]+carry;
    carry=num[c][i]/base;
    num[c][i]=num[c][i]%base;
  }
  if(carry)
    num[c][len[a]]=carry, len[c]=len[a]+1;
  else
    len[c]=len[a];
}
int main(){
  memset(num,0,sizeof(num));
  len[0]=len[1]=len[2]=1;
  num[1][0]=1;
  for(int j=2; j<=1000; j++ )
    num[j][0]=num[j-2][0];
  num[2][0]=1;
  for(int j=3; j<=1000; j++ )
    Add(j,j-2,j-3);
  int n;
  while(cin>>n){
    printf("%lld",num[n][len[n]-1]);
    for(int i=len[n]-2;i>=0;i--)
      printf("%017lld",num[n][i]);
    printf("\n");
  }
}