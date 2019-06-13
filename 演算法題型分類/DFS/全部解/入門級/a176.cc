#include<cstdio>
using namespace std;

int BlockCnt[5], bag[6], n, cnt;
char Block[5][2][5]={{"*   ","*** "},{"    ","****"},{"  * ","*** "},{"**  ","**  "},{"*** "," *  "}};
void DFS(int deep,int preBlock){
  if(deep==n){
    // 輸出排列的內容
    for(int i=0;i<n;i++)
      printf("%s|",Block[bag[i]][0]);
    printf("\n");
    for(int i=0;i<n;i++)
      printf("%s|",Block[bag[i]][1]);
    printf("\n\n\n");
    cnt++;  return;
  }
  for(int i=0;i<5;i++)
    if(BlockCnt[i] and i!=preBlock)
      BlockCnt[i]--,
      bag[deep]=i,
      DFS(deep+1,i),
      BlockCnt[i]++;
}
int main(){
  for(int m; scanf("%d %d",&n,&m)!=EOF and n; ){
    for(int i=0;i<5;i++)
      BlockCnt[i]=m;
    cnt=0;
    DFS(0,-1);
    printf("Sum : %d\n",cnt);
  }
}