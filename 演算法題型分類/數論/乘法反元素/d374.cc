// Modular的乘法反元素
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1324567199
/* x*x%m = 1 => x*x=1+n*m => (x+1)(x-1)=n*m
 * n=np*nq, m=mp*mq => x+1=mp*np, x-1=mq*nq => 2=mp*np-mq*nq
 * try all mp, mq, use extended gcd
 */