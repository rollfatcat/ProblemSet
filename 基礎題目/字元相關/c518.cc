// 字串讀取 string vs char[]
#include<cstdio>
using namespace std;

char org[200000], ss[10000000];
int main(){
  int N, M;
  char map[123]={}, a, b;

  for(char i='0';i<='9';i++) map[i]=i;
  for(char i='A';i<='Z';i++) map[i]=i;
  for(char i='a';i<='z';i++) map[i]=i;

  scanf("%d %d",&N,&M);
  getchar();
  for(int i=0;i<N;i++)
    org[i]=getchar();
  getchar();
  for(int i=0;i<M;i++)
    ss[i]=getchar();
  getchar();
  for(int idx=0;idx<M;idx++){
    a=ss[idx], b=getchar();
    for(char i='0';i<='9';i++) if(map[i]==a) map[i]=b;
    for(char i='A';i<='Z';i++) if(map[i]==a) map[i]=b;
    for(char i='a';i<='z';i++) if(map[i]==a) map[i]=b;
  }
  for(int i=0;i<N;i++)
    printf("%c",map[org[i]]);
  printf("\n");
}