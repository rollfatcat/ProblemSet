/* 核心作法不變，請參照version 1
 * 對於Hash_table＋加法的實作改善(1)Merkle Tree (2)Zobrist hashing 搭配 XOR sum
 * XOR sum 的改善是基於個數每多一個或是少一個時奇偶性的交替出現規律
 * 換句話說，如果今天要求的是區間內3的倍數時就無法用XOR達成
 */

#include<iostream>
#include<map>
using namespace std;
#define MAXN 1000001

map<long long,int> cnt;
long long hash_table[MAXN];
bool status[MAXN]={};
int main(){
  // 建狀態的hash_table
  hash_table[1]=1;
  for(int i=2;i<MAXN;i++)
    hash_table[i]=rand()|((long long)rand()<<32);

  int N, number;
  long long int all_cnt=0, nows=0;
  scanf("%d",&N);
  cnt[0]=1;
  for(int i=1;i<=N;i++){
    scanf("%d",&number);
    nows^=hash_table[number];
    all_cnt+=cnt[nows]++;
  }
  printf("%lld\n",all_cnt);
}