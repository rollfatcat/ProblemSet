#include<bits/stdc++.h>
using namespace std;

const long mod=1e18;
const double PI=acos(-1);
typedef complex<double> base;
vector<base>omega;
long FFT_n;

// 產生『單位根』
void init_fft(long n){
  FFT_n=n, omega.resize(n);
  double theta=2.0*PI/n; // θ=2π/n
  for(int i=0;i<n;i++)   // exp(iθ)=cosθ+i*sinθ, i=(0,n-1)
    omega[i]=base( cos(i*theta),sin(i*theta) );
}
void fft(vector<base> &vec){
  if(vec.size()==1)  return;
  long n=vec.size(), hn=n>>1;

  vector<base> even(hn);
  vector<base> odd(hn);
  for(int i=0; i<hn; i++)
    even[i]=vec[i<<1],
    odd[i]=vec[(i<<1)+1];
  fft(even),
  fft(odd);
  for(int i=0,fact=FFT_n/n; i<hn; i++){
    base twiddle=odd[i]*omega[i*fact];
    vec[i]=even[i]+twiddle;
    vec[i+hn]=even[i]-twiddle;
  }
}
void multiply(const vector<long> &a, const vector<long> &b, vector<long> &res){
  vector<base> fa(a.begin(),a.end());
  vector<base> fb(b.begin(),b.end());
  long n=max(a.size(),b.size()); n=(long)1<<(__lg(n)+2);

  fa.resize(n),
  fb.resize(n);

  init_fft(n);
  fft(fa),
  fft(fb);
  for(size_t i=0; i<n; i++)
    fa[i]=conj(fa[i]*fb[i]); // 取共軛根
  fft(fa);
  res.resize(n);
  for(size_t i=0; i<n; i++)
    res[i]=(long)(fa[i].real()/n+0.5);

}

int main(){

}