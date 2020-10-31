/* BobbleSort
 */
#include<iostream>
using namespace std;
#define MaxItem 1000

struct Item{
  int n, w;
}item[MaxItem+1];

int main(){
  int T, N;
  cin>>T;
  while(T--){
    cin>>N;
    for(int i=0;i<N;i++)
      cin>>item[i].n;
    for(int i=0;i<N;i++)
      cin>>item[i].w;
    int total=0;
    for(int i=1;i<N;i++){
      item[MaxItem].n=item[i].n;
      item[MaxItem].w=item[i].w;
      int j=i;
      for( ; j>0 and item[MaxItem].n<item[j-1].n; j--){
        item[j].n=item[j-1].n;
        item[j].w=item[j-1].w;
        total+=(item[j-1].w+item[MaxItem].w);
      }
      item[j].n=item[MaxItem].n;
      item[j].w=item[MaxItem].w;
    }
    cout<<total<<'\n';
  }
}