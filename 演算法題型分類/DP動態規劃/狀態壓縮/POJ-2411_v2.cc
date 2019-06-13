// 注意這一題的 ith Row jth Col 的值=1代表放著直竪的方塊
#include <stdio.h>
#include <string.h>

/** n * m 的地板 */
int n,m;

/** dp[i][j] = x 表示使第i 行状态为j 的方法总数为x */
long long int dp[12][2049];

/* 该方法用于搜索某一行的横向放置瓷砖的状态数,并把这些状态累加上row-1 行的出发状态的方法数
 * @name row 行数
 * @name state 由上一行决定的这一行必须放置竖向瓷砖的地方，s的二进制表示中的1 就是这些地方
 * @name pos 列数
 * @name pre_num row-1 行的出发状态为~s 的方法数
 */
void dfs(int row, int state, int pos, long long int pre_num ){
  /** 到最后一列  */
  if(pos==m){
    dp[row][state]+=pre_num;  return;
  }
  /** 该列不放 */
  dfs(row,state,pos+1,pre_num);
  /** 该列和下一列放置一块横向的瓷砖 => 位置必須*/
  if( ( pos<=m-2 ) && !(state&( 1<<pos )) && !(state & ( 1<<(pos+1) ) ) )
    dfs(row, state|(1<<pos)|(1<<(pos+1)), pos+2, pre_num);
}
int main(){
  while( scanf("%d%d",&n,&m) && ( n || m ) ){
    if(n<m) /** 对较小的数(m)进行状压，已提高效率 */
      n=n^m,  m=n^m,  n=n^m;

    memset(dp,0,sizeof(dp));
    /** 初始化第一行 */
    dfs( 1, 0, 0, 1 );

    for(int i=2; i<=n; i++)
      for(int j=0; j<(1<<m); j++){
        if(dp[i-1][j]){
          long long int tmp=dp[i-1][j];
          /* 如果i-1行的出发状态某处未放，必然要在i行放一个竖的方块，
           * 所以我对上一行状态按位取反之后的状态就是放置了竖方块的状态
           */
          dfs( i, ( ~j ) & ( ( 1 << m ) - 1 ), 0, tmp ) ;
        }
        else continue;
      }
    /** 注意并不是循环i 输出 dp[n][i]中的最大值 */
    printf( "%llu\n",dp[n][(1<<m)-1] );
  }
}
