// 題目沒給輸入的字串長度所以就自訂成50
// 題目的字典序是"AaBbCcDd..."
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MaxN 100

char ss[MaxN], ns[MaxN], len;
bool use[MaxN];
int CharToInt(char c){ return (c>='a')? (2*(c-'a')+1) : (2*(c-'A')); }
bool compare(char a, char b){ return CharToInt(a)<CharToInt(b); }
void DFS(int now){
  if(now==len){ //不知道為什麼 printf("%s",bag) 沒辦法正常執行 @@?, 所以一個個字元印出來
    for(int i=0;i<=len;i++)
      printf("%c",ns[i]);
    return;
  }
  char pre=' ';
  for(int i=0;i<len;i++)
    if(!use[i] and ss[i]!=pre){
      use[i]=1, pre=ss[i], ns[now]=ss[i];
      DFS(now+1);
      use[i]=0;
    }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int caseNum;
  cin>>caseNum;
  while(caseNum--){
    scanf("%s",ss);
    len=strlen(ss);
    sort(ss,ss+len,compare);
    memset(use,0,sizeof(use));
    ns[len]='\n';
    DFS(0);
  }
}