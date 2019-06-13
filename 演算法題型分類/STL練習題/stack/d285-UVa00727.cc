// Postfix => 利用Stack將中序轉成後序(不需要建樹)
// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4166529
#include<iostream>
#include<stack>
#include<map>
using namespace std;

void scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); }
int main(){
  map<char,int>BookP;
  BookP['(']=BookP[')']=0,
  BookP['+']=BookP['-']=1,
  BookP['*']=BookP['/']=2;

  int T; scanInt(T);
  getchar();
  for(char ans[51],buff; T--; ){
    stack<char> St;
    for(; true; getchar()){
      if((buff=getchar())=='\n' or buff==EOF) break;
      if(buff>='0' and buff<='9') putchar(buff);
      else{
        if(buff=='(' or St.empty() or BookP[buff]>BookP[St.top()])
          St.push(buff);
        else if(buff==')'){
          while(St.top()!='(')
            putchar(St.top()), St.pop();
          St.pop();
        }else{
          while(!St.empty() and BookP[buff]<=BookP[St.top()])
            putchar(St.top()), St.pop();
          St.push(buff);
        }
      }
    }
    while(!St.empty())
      putchar(St.top()), St.pop();
    puts("");
    if(T) puts("");
  }
}
/*
2

(
3
+
2
)
*
5

3
+
2
*/