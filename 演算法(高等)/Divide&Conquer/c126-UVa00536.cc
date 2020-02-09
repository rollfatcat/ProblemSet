// 給前序(中左右)中序(左中右)輸出後序(左右中) => 練習 Divide&Conquer
// 題解：http://www.csie.ntnu.edu.tw/~u91029/BinaryTree.html
#include<iostream>
#include<cstring>
using namespace std;

char Prss[30], Inss[30];
int deep;
void DivCon(int l,int r){
  if(l==r){ putchar(Prss[deep]); return; }
  int idx, now=deep;
  for(idx=l; idx<=r and Prss[now]!=Inss[idx]; idx++);
  if(l<=idx-1)  deep++, DivCon(l,idx-1);
  if(idx+1<=r)  deep++, DivCon(idx+1,r);
  putchar(Prss[now]);
}
int main(){
  while(scanf("%s %s",Prss,Inss)!=EOF)
    deep=0,
    DivCon(0,strlen(Inss)-1),
    puts("");
}
/*
0136742589
6371402859
*/