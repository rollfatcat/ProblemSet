// 不需要DFS去嘗試全部的可能
#include<iostream>
using namespace std;

int T, N, x;
int a[7], *num=&a[3];
void Merge(int a, int b){
  x=min(num[a],num[b]);
  num[a]-=x;  num[b]-=x;  num[a+b]+=x;
}

int main(){
  cin>>T;
  while(T--){
    cin>>N;
    fill(a,a+7,0);
    int total=0;
    while(N--)
      cin>>x, num[x]++, total+=x;
	  // 簡單判斷：一開始就是Goal超出範圍一定就不可能達成
	  if(total>3 or total<0){
		  cout<<"NO"<<endl;
      continue;
	  }
    // 判斷(-3) 0= -3+3 = -3+2+(+2-1) = (-3+1)+2 = (-3+1)+1+1
    Merge(3,-3);
    Merge(2,-1);
    Merge(-3,1);
    if(num[-3]>0){
      cout<<"NO"<<endl;
      continue;
    }
    // num[-3]==0的前提下才會繼續
    // 判斷(+3) 0= +3-2+(-2+1) = (+3-1)-2 = (+3-1)-1-1
    Merge(-2,1);
    Merge(3,-1);
    // 因為初始狀態是0 可以多承受一個+3
    if(num[3]>1)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }
}