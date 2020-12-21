/* 題意需要知道高中化學關於『烷基』『烷烴』定義後才能推導動態規劃的規律
 * 題目保證計算過程中使用 unsigned long 即可
 * N=1 額外處理，其餘部分參考：https://zhuanlan.zhihu.com/p/20252429
 * 動態規劃：求得Ｎ碳的烷基同分異構物個數必須先算出1~Ｎ-1碳
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

// 初始化：碳1到碳4的烷基種類
unsigned long  x1[MAXN]={0,1,1,1,2}; // 1°烷基個數
unsigned long  x2[MAXN]={0,0,0,1,1}; // 2°烷基個數
unsigned long  x3[MAXN]={0,0,0,0,1}; // 3°烷基個數
unsigned long tot[MAXN]={0,1,1,2,4}; // 烷基個數之和

/* 計算烷基個數
 * 將烷基分為An(n個碳構成的1°烷基個數)、Bn(2°)、Cn(3°)，而後利用组合的方式可以進行遞迴推導，得到n個碳的烷基個數。
 */
inline void f_calc_alkyl(int n){
  for(int i=5;i<=n;i++){
    // 計算1°烷基種類
    x1[i]=tot[i-1];

    // 計算2°烷基種類
    for(int j=1;j<((i-1)>>1);j++)
      x2[i]+=tot[j]*tot[i-1-j];
    x2[i]+= (i&1)?( tot[(i-1)>>1]*(tot[(i-1)>>1]+1)>>1 ): tot[i>>1]*tot[(i>>1)-1];

    // 計算3°烷基種類
    // (1)連接的3個烷基為ABC型
    for(int j=1;j<i;j++)
      for(int k=j+1;k<i;k++)
        if(i-1-j-k>k)
          x3[i]+=tot[j]*tot[k]*tot[i-1-j-k];
    // (2)連接的3個烷基為AAB型
    for(int j=1;j<i and i-1-(j<<1)>0;j++)
      if( j!=i-1-(j<<1) )
        x3[i]+=( tot[j]*(tot[j]+1)>>1 )*tot[i-1-(j<<1)];
    // (3)連接的3個烷基為AAA型
    if((i-1)%3==0){
      int tem=(i-1)/3;
      x3[i]+=tot[tem]*(tot[tem]+1)*(tot[tem]+2)/6;
    }
    // 累計總數
    tot[i]=x1[i]+x2[i]+x3[i];
  }
}

// 計算中心為3°碳的烷烴個數
inline unsigned long f_calc_3(int n){
  unsigned long ans=0;
  int ub=n+1>>1; //所連接烷基碳數上限
  // 烷基為ABC型
  for(int i=1;i<ub;i++)
    for(int j=i+1;j<ub;j++)
      if(n-i-j>j and n-i-j<ub)
        ans+=tot[i]*tot[j]*tot[n-i-j];
  // 烷基為AAB型
  for(int i=1;i<ub;i++)
    if(n-2*i>0 and n-2*i<ub and i!=n-2*i)
      ans+=((tot[i]+1)*tot[i]>>1)*tot[n-(i<<1)];
  // 烷基為AAA型
  if(n%3==0)
    ans=ans+tot[n/3]*(tot[n/3]+1)*(tot[n/3]+2)/6;
  return ans;
}

// 計算中心為4°碳的烷烴個數
inline unsigned long f_calc_4(int n){
  unsigned long ans=0;
  int ub=n+1>>1;
  // 烷基為ABCD型
  for(int i=1;i<ub;i++)
    for(int j=i+1;j<ub;j++)
      for(int k=j+1;k<ub;k++)
        if(n-i-j-k>k and n-i-j-k<ub)
          ans+=tot[i]*tot[j]*tot[k]*tot[n-i-j-k];
  // 烷基為AABC型
  for(int i=1;i<ub;i++)
    for(int j=1;j<ub;j++)
      if(n-2*i-j>j and i!=j and i!=n-2*i-j and n-2*i-j<ub)
        ans+=( tot[i]*(tot[i]+1)>>1 )*tot[j]*tot[n-2*i-j];
  // 烷基為AABB型
  if((n&1)==0)
    for(int i=1;i<(n>>1)-i;i++)
      ans+=(tot[i]*(tot[i]+1)>>1)*tot[(n>>1)-i]*(tot[(n>>1)-i]+1)>>1;
  // 烷基為AAAB型
  for(int i=1;i<=n and n-3*i>0;i++)
    if(i!=n-3*i and n-3*i<ub)
      ans+=tot[i]*(tot[i]+1)*(tot[i]+2)/6*tot[n-3*i];
  // 烷基為AAAA型
  if((n&3)==0)
    ans+=tot[n>>2]*(tot[n>>2]+1)*(tot[n>>2]+2)*(tot[n>>2]+3)/24;
  return ans;
}

/* 在求得烷基同分異構物個數後，如何將烷烴的問題轉變到烷基的問題：分奇偶討論
 * 偶數：
 * (1) 可以被切分為兩個(n/2)碳的烷基
 *     T(n/2)*( T(n/2)+1 )/2
 * (2) 不能被切分為兩個(n/2)碳的烷基
 *     必能找到唯一一個3°或4°碳作為分子中心，使得其所連接的每個烷基大小均小於(n/2)碳，使用组合計數可得這一部分烷烴的個數
 * 奇數：
 * (1) 可以被切分為一個((n-1)/2)碳和一個((n+1)/2)碳的烷基
 *     根據((n+1)/2)碳的烷基是否由一個((n-1)/2)碳的烷基連接一個亞甲基構成
 * (2) 同偶數
 */
inline unsigned long f_calc(int n){
  unsigned long ans=tot[n>>1]*(tot[n>>1]+1)>>1;
  if(n&1) ans+=tot[n>>1]*(tot[(n>>1)+1]-tot[n>>1]);
  // 額外處理N=1的情況做修正
  ans+=n==1;

  ans+=f_calc_3(n-1);
  ans+=f_calc_4(n-1);
  return ans;
}
int main(){
  // 預處理 1°/2°/3°烷基個數
  f_calc_alkyl(50);

  int N;
  while(cin>>N and N)
    cout<<f_calc(N)<<endl;

}