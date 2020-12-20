#include<iostream>
#include<cmath>
using namespace std;
#define MaxN 101
#define MaxW 10001

int total_w, len;
int v[MaxN], w[MaxN];
int val_map[MaxN][MaxW];

int Knapsack_TD(int item_no,int total_w){
  if(item_no==-1 or total_w==0) //沒東西可以選 或是 剩餘重量=0
    return 0;
  if(val_map[item_no][total_w]==-1)
    if(total_w<w[item_no])
      val_map[item_no][total_w]=Knapsack_TD(item_no-1,total_w);
    else
      val_map[item_no][total_w]=max( Knapsack_TD(item_no-1,total_w-w[item_no])+v[item_no], Knapsack_TD(item_no-1,total_w));
  return val_map[item_no][total_w];
}
int main(){
  for(int caseNum=1000; caseNum; caseNum--){
    cin>>len;
    for(int i=0;i<len;i++)
      cin>>w[i]>>v[i];
    cin>>total_w;
    for(int i=0;i<len;i++)
      for(int j=1;j<=total_w;j++)
        val_map[i][j]=-1;
    cout<<Knapsack_TD(len-1,total_w)<<endl;
    /*
    for(int i=0;i<len;i++,cout<<endl)
      for(int j=0;j<=total_w;j++)
        printf("%2d ",val_map[i][j]);
    */
  }
}