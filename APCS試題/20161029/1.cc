#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void *a,const void *b){ return *(int*)a-*(int*)b; }
string judgeType(int e[]){
  if(e[2]>e[1]+e[0])
    return "No";
  else{
    int tmp=e[0]*e[0]+e[1]*e[1];
    return (tmp==e[2]*e[2])?"Right": (tmp>e[2]*e[2])?"Acute":"Obtuse";
  }
  return "Impossible";
}
int main(void){
  int edge[3];
  while(cin>>edge[0]>>edge[1]>>edge[2]){
    qsort(edge,3,sizeof(edge[0]),compare);
    //
    cout<<edge[0]<<' '<<edge[1]<<' '<<edge[2]<<endl;
    cout<<judgeType(edge)<<endl;
  }
}