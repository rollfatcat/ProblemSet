#include<bits/stdc++.h>
using namespace std;

char ss[102], ch;
int main(){
  while(scanf("%s%c",ss,&ch)!=EOF){
  	for(int i=strlen(ss)-1;i>=0;i--)
  		putchar(ss[i]);
  	putchar(ch);
  }
}