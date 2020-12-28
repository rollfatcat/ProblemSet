// 有趣的接龍題目：麻煩在計算兩字串重疊部分(如果有越小越好)
// 關係圖建立後跑DFS即可
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int N, maxL, cnt[20]={};
char ss[20][100];
struct nn{int n,L;}tmp;
vector<nn> e[20];
void Build_Map(){
  //窮舉 ith 字串當前面 jth 字串後面，試試重疊的部分
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      for(int iL=strlen(ss[i])-1;iL>=0;iL--){ // 枚舉每個 ith 字串產生的子字串，且重疊部分越少越好=>子字串從短的開始比
        int subL=strlen(ss[i])-iL, jL;
        if(strlen(ss[j])>subL){ //且只有當 jth 字串長度大於子字串時才有意義
          for(jL=0;jL<subL and ss[j][jL]==ss[i][iL+jL];jL++);
          if(jL==subL){
            tmp.n=j, tmp.L=strlen(ss[j])-jL;
            e[i].push_back(tmp);
            break;
          }
        }
      }
    }
}
void DFS(int now,int L){
  bool end=true;
  for(int i=0;i<e[now].size();i++)
    if(cnt[ e[now][i].n ]<2)
      end=false,
      cnt[e[now][i].n]++,
      DFS(e[now][i].n, L+e[now][i].L),
      cnt[e[now][i].n]--;
  if(end and maxL<L) maxL=L;
}
int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%s",ss[i]);
  Build_Map();
  getchar();
  char st=getchar();
  maxL=0;
  for(int i=0;i<N;i++)
    if(ss[i][0]==st)
      cnt[i]=1, DFS(i,strlen(ss[i])), cnt[i]=0;
  printf("%d\n",maxL);
}
// atoucheatactactouchoose = at touch cheat tact tact touch choose