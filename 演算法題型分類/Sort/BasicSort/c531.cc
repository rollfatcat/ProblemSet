#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int even[20], pos[20], num[20];
  while(scanf("%d",&num[0])!=EOF){
    int N=1, Neven=0;
    if(num[0]%2==0)
      even[Neven]=num[0], pos[Neven++]=0;
    for(char c=getchar();c!=EOF and c!='\n';N++, c=getchar() ){
      scanf("%d",&num[N]);
      if(num[N]%2==0)
        even[Neven]=num[N], pos[Neven++]=N;
    }
      
    sort(even,even+Neven);
    for(int i=0;i<Neven;i++)
      num[ pos[i] ]=even[i];
    
    printf("%d",num[0]);
    for(int i=1;i<N;i++)
      printf(",%d",num[i]);
    printf("\n");
    
  }
}