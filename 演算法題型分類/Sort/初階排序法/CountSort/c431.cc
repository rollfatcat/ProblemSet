#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  int cnt[101], n, num;
  while(scanf("%d",&n)!=EOF){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
      scanf("%d",&num),
      cnt[num]++;

    for(int i=1;i<=100;i++)
      for(int j=0;j<cnt[i];j++)
        printf("%d ",i);
    printf("\n");
  }
}