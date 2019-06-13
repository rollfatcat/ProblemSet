// 練習 Qsort 和 Struct 寫法
// 參考：http://winage.pixnet.net/blog/post/188269445-qsort%E7%9A%84%E5%87%BD%E6%95%B8%E6%8C%87%E6%A8%99%E6%96%B9%E6%B3%95
// 解法：依據 w*f 排序
#include<iostream>
#include<stdlib.h>
using namespace std;

struct item{
  int w;
  int f;
} arr[100000];
int compare (const void *a, const void *b){
  struct item* x= (item*)a;
  struct item* y= (item*)b;
  return (y->w*x->f)-(x->w*y->f);
}
int main(){
  int cnt;

  while(cin>>cnt){
    for(int i=0; i<cnt; i++)
      cin>>arr[i].w;
    for(int i=0; i<cnt; i++)
      cin>>arr[i].f;
    qsort(arr,cnt,sizeof(arr[0]),compare);
    long long total=0;
    long long total_w=0;
    for(int i=cnt-1;i>0;i--){
      total_w+=arr[i].w;
      total+=(total_w*arr[i-1].f);
    }
    cout<<total<<endl;
  }
}