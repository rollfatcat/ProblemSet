// 判斷哪種字母出現的次數最多，一樣多時輸出標號越小的
#include<bits/stdc++.h>
using namespace std;

int cnt[7];
char ss[7][10]={"Saber","Lancer","Archer","Rider","Caster","Assassin","Berserker"};
int main(){
  for(char ch;(ch=getchar())!=EOF;)
    if('A'<=ch and ch<='Z')
      cnt[(ch-'A')%7]++;
    else if('a'<=ch and ch<='z')
      cnt[(ch-'a')%7]++;
  int idx=0;
  for(int i=1;i<=6;i++)
    if(cnt[i]>cnt[idx])
      idx=i;
  puts(ss[idx]);
}