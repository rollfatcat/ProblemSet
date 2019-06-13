// HashMap => unordered_map
#include<bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<int,int> table;
  unordered_map<int,int>::iterator it;

  for(int num;scanf("%d",&num)!=EOF;){
    if((it=table.find(num))==table.end())
      table.insert(make_pair(num,1));
    else
      table[num]++;
  }
  for(it=table.begin(); (it->second%3)==0; it++);
  printf("%d\n",it->first);
}