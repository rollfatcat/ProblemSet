/* 簡單模擬：題目明確描述構成三種機器人的方式，目標是最小化三種機器人的成本
 * 需要花時間將規則讀完後轉成程式碼，適合作為作業
 * 每個數字皆不超過10
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 11
#define INF 1<<30

int A_Robot[MAXN]={};
int B_Robot[MAXN]={};
int C_Robot[MAXN]={};
int parameter[26], N;
int main(){
  while(scanf("%d",&parameter[0])!=EOF){
    memset(A_Robot,0,sizeof(A_Robot));
    memset(B_Robot,0,sizeof(B_Robot));
    memset(C_Robot,0,sizeof(C_Robot));
    for(int i=1;i<22;i++)
      scanf("%d",&parameter[i]);
    scanf("%d",&A_Robot[1]);
    scanf("%d",&B_Robot[1]);
    scanf("%d",&C_Robot[1]);
    //
    for(int N=2;N<=parameter[13];N++){
      A_Robot[N]=B_Robot[N]=C_Robot[N]=INF;
      // A_Robot
      if(N>=3) A_Robot[N]=parameter[0]*B_Robot[N-2]+parameter[1]*C_Robot[N-1]+parameter[2];
               A_Robot[N]=min(A_Robot[N],parameter[3]*C_Robot[N-1]+parameter[4]);
               A_Robot[N]=min(A_Robot[N],parameter[5]*A_Robot[N-1]+parameter[6]);
      // B_Robot
      if(N>=3) B_Robot[N]=parameter[7]*C_Robot[N-2]+parameter[8]*A_Robot[N-1]+parameter[9];
               B_Robot[N]=min(B_Robot[N],parameter[10]*C_Robot[N-1]+parameter[11]);
      if(N>=3) B_Robot[N]=min(B_Robot[N],parameter[12]*A_Robot[N-2]+parameter[14]);
      // C_Robot
      if(N>=4) C_Robot[N]=parameter[15]*A_Robot[N-3]+parameter[16]*B_Robot[N-1]+parameter[17];
               C_Robot[N]=min(C_Robot[N],parameter[18]*B_Robot[N-1]+parameter[19]);
      if(N>=3) C_Robot[N]=min(C_Robot[N],parameter[20]*C_Robot[N-2]+parameter[21]);
    }
    printf("%d %d %d\n",A_Robot[parameter[13]],B_Robot[parameter[13]],C_Robot[parameter[13]]);
  }
}