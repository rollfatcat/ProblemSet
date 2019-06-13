// 快速傅立葉轉換：http://blog.miskcoo.com/2015/04/polynomial-multiplication-and-fast-fourier-transform
#include<bits/stdc++.h>
using namespace std;

const double ESP=1e-5;
const double PI=acos(-1);

void FFT(bool InverseTransform, vector<complex<double> > &In, vector<complex<double> > &Out){
	int samples = In.size(), bits = NumberOfBits(samples), offset = 1, steps = 2;
	for (int i = 0; i < samples; i++)
		Out[ReverseBits(i, bits)] = In[i];

	double radian = PI * (InverseTransform ? -2 : 2);
	for (; steps <= samples; steps <<= 1) {
		double deltaRadian = radian / steps;
		double sin1 = sin(-deltaRadian), cos1 = cos(-deltaRadian);
		double sin2 = sin(-deltaRadian * 2), cos2 = cos(-deltaRadian * 2);
		for (int i = 0; i < samples; i += steps) {
			complex<double> a1(cos1, sin1), a2(cos2, sin2);
			for (int j = i, n = 0; n < offset; j++, n++) {
				complex<double> a0(2 * cos1 * a1.real() - a2.real(), 2 * cos1 * a1.imag() - a2.imag());
				complex<double> a = a0 * Out[j + offset];
				Out[j + offset] = Out[j] - a, Out[j] += a;
				a2 = a1, a1 = a0;
			}
		}
		offset = steps;
	}

	if (InverseTransform)
		for (int i = 0; i < samples; i++)
			Out[i] /= samples;
}
vector<double> convolution(vector<double> a, vector<double> b) {
	vector<complex<double> > signal(a.size()), buffer1(a.size()), buffer2(a.size()), y(a.size());

	for (int i = 0; i != a.size(); i++)
		signal[i] = complex<double>(a[i], 0);
	FFT(false, signal, buffer1);

	signal[0] = complex<double>(b[0], 0);
	for (int i = 1; i != a.size(); i++)
		signal[i] = complex<double>(b[a.size() - i], 0);
	FFT(false, signal, buffer2);

	for (int i = 0; i != a.size(); i++)
		y[i] = buffer1[i] * buffer2[i];
	FFT(true, y, signal);

	vector<double> answer(a.size());
	for (int i = 0; i != a.size(); i++)
		answer[i] = signal[i].real();

	return answer;
}

struct Polynomial{
  vector<double> coefficient;
  void init(string num){
    coefficient.resize(num.length());
    for(int i=0;i<num.length();i++)
      coefficient[num.length()-1-i]=num[i]-'0';
  }
  Polynomial operator*(const Polynomial &rhs)const{
    int n=max(coefficient.size(),rhs.coefficient.size())<<1;
		int m=1<<__lg(n)+1;

		vector<double> newA(m,0), newB(m,0);
		for(int i=0; i<coefficient.size(); i++)
			newA[i]=coefficients[i];
		for(int i=0; i<rhs.coefficient.size(); i++)
			newB[m-1-i]=rhs.coefficient[i];

		Polynomial answer;
		answer.coefficient=convolution(newA,newB);
		for(int i=1; i<answer.coefficient.size(); i++)
			answer.coefficient[i-1]=answer.coefficient[i];
		answer.coefficient[answer.coefficient.size()-1]=0;
		return answer;
  }
};
int main(){

}