#include<iostream>
#include<cstdlib>
using namespace std;

struct line{
  int loc;
  int No;
  int abss;
}arr[10000];
int compare(const void *a, const void *b){
    struct line *c = (line *)a;
    struct line *d = (line *)b;
    return (c->abss==d->abss)?(c->No-d->No):(d->abss-c->abss);
}
int main(){
  int k;
  cin>>k;
  while(k--){
    int len=0;
    cin>>len;
    for(int i=0;i<len;i++){
      arr[i].loc=i;
      cin>>arr[i].No;
    }
    //紀錄的方式有點奇怪
    for(int i=0;i<len-1;i++){
      arr[i].abss=arr[i+1].No-arr[i].No;
    }
    qsort(arr,len-1,sizeof(arr[0]),compare);
//    for(int i=0;i<len;i++)
//      cout<<arr[i].loc<<','<<arr[i].No<<','<<arr[i].abss<<endl;
    //輸出完記得換行
    cout<<arr[0].loc+1<<endl;
  }
}