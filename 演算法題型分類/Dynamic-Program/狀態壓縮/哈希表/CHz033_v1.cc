/* 狀態壓縮描述：每個數字出現的情況是奇數還是偶數。
 * 區間 [i,j] 是一個符合題目要求的區間等於是 state[i-1] 跟 state[j] 每個bit要完全一樣
 * 以區間尾巴j的角度來看要數有幾個滿足的區間頭, 就等於是數跟state[j]同樣的傢伙出現了幾次
 * 解題步驟：
 * 每加入一個number -> 更新奇偶狀態 -> 將答案加上"以目前位置為尾巴的區間數量" -> counter++
 * 但問題是Ｎ=1e6個，無法使用2^(1e6)來描述，透過 Hash_table描述的狀態只是降低碰撞的機率
 * => Hash_table＋加法來描述狀態的疊加(792ms/18MB)
 */

#include<iostream>
#include<map>
using namespace std;
#define MAXN 1000001
#define MOD 1000000000000000003LL

map<long long int,int> cnt;
long long int hash_table[MAXN];
bool status[MAXN]={};
int main(){
  // 建狀態的hash_table
  hash_table[1]=1;
  for(int i=2;i<MAXN;i++)
    hash_table[i]=(hash_table[i-1]<<1)%MOD;

  int N, number;
  long long int all_cnt=0, nows=0;
  scanf("%d",&N);
  cnt[0]=1;
  for(int i=1;i<=N;i++){
    scanf("%d",&number);
    (status[number])? nows=(nows-hash_table[number]+MOD)%MOD: nows=(nows+hash_table[number])%MOD,
    status[number]=!status[number];
    all_cnt+=cnt[nows]++;
  }
  printf("%lld\n",all_cnt);
}