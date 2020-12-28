// 有趣的變形題
// 和選中的前一個字母不一樣(因為已經排序過)

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int cmp(const void*a, const void*b){ return *(char*)a-*(char*)b; }
int n;
bool use[11];
char bag[11], ss[11];;
void Permutate(int now){
  if(now==n){
    printf("%s\n",bag);
    return;
  }
  char pre=' ';
  for(int i=0;i<n;i++)
    if(!use[i] and ss[i]!=pre){ //和選中的前一個字母不一樣
      pre=bag[now]=ss[i];
      use[i]=1;
      Permutate(now+1);
      use[i]=0;
    }
}

int main(){
  int T;

  cin>>T;
  while(T--){
    scanf("%s",ss);
    n=strlen(ss);
    bag[n]='\0';
    qsort(ss,n,sizeof(char),cmp);
    memset(use,0,sizeof(use));
    Permutate(0);
    printf("\n");
  }
}