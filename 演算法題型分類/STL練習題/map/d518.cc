// 題目要求使用HashMap => unordered_map
/* map和unordered_map的差異：
 * STL中，map 对应的数据结构是红黑树。红黑树是一种近似于平衡的二叉查找树，里面的数据是有序的。
 * 在红黑树上做查找操作的时间复杂度为 O(logN)。而 unordered_map 对应 哈希表，
 * 哈希表的特点就是查找效率高，时间复杂度为常数级别 O(1)， 而额外空间复杂度则要高出许多。
 * 所以对于需要高效率查询的情况，使用 unordered_map 容器。而如果对内存大小比较敏感或者数据存储要求有序的话，则可以用 map 容器。
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  for(int N; scanf("%d",&N)!=EOF;){
    char ss[22];
    unordered_map<string,int> table;
    unordered_map<string,int>::iterator it;
    for(int ID=1;N--; ){
      scanf("%s",ss);
      if((it=table.find(ss))==table.end())
        printf("New! %d\n",ID),
        table.insert(make_pair(ss,ID++));
      else
        printf("Old! %d\n",it->second);
    }
  }
}
/*
5
eine
isis
zwei
drei
zwei
*/