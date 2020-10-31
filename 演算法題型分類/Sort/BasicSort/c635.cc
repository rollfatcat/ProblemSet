#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int even[20], odd[20], num[20];
  while(scanf("%d",&even[0])!=EOF){
    int len[2]={1,0};
    char c=getchar();
    for(int i=1;c!='\n' and c!=EOF;i++, c=getchar())
      if(i%2) scanf("%d",&odd[ len[1]++ ]);
      else    scanf("%d",&even[ len[0]++ ]);
    sort(even,even+len[0]);
    sort(odd,odd+len[1]);

    for(int i=1;i<len[0];i++)
      num[2*i]=even[i];
    for(int i=0;i<len[1];i++)
      num[2*i+1]=odd[i];
    printf("%d",even[0]);
    for(int i=1;i<(len[0]+len[1]);i++)
      printf(",%d",num[i]);
    printf("\n");

  }
}