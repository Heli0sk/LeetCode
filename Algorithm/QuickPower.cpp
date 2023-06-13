#include<iostream>
using namespace std;


long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}


double myPow(double x, int n) {
	if(x == 0.0f) return 0.0d;

	long b = n;
	double res = 1.0;
	if(b < 0) {
		x = 1 / x;
		b = -b;
	}
	while(b > 0) {
		if((b & 1) == 1) res *= x;
		x *= x;
		b >>= 1;
	}
	return res;
}

int main()
{
	
	return 0;
}
