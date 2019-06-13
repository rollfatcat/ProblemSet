// 簡單模擬，關燈的情況只會影響自己的倍數，所以從小的關起即可
#include<iostream>
using namespace std;

int N;
bool on[300001];
int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
    getchar(), on[i]=(getchar()=='1');
  int cnt=0;
  for(int i=1;i<=N;i++)
    if(on[i]){
      cnt++;
      for(int j=1;i*j<=N;j++)
        on[i*j]^=true;
    }
  printf("%d\n",cnt);
}