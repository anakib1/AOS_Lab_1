
#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;
static long long holdrand = 1L;

#define MX (int)(1e8)

long double mrand() {
	return 0.3337 * (((holdrand = holdrand * 214013LL + 2531011LL) >> 16) & 0x7fff);
}
template<typename T>
double test_efficiency_plus(int num = MX) {
	num /= 8;
	T a = (T)mrand();
	T b = (T)mrand();
	T c = (T)mrand();
	T d = (T)mrand();
	double time = clock();
	while (num--) {
		b = a + c;
		c = a + b;
		a = b + c;
		d = a + b;
		b = a + d;
		a = b + d;
		b = a + b;
		c = b + d;
	}
	return (double)(MX) / (((double)(clock() - time)) / CLOCKS_PER_SEC);
}
template<typename T>
double test_efficiency_minus(int num = MX) {
	num /= 8;
	T a = (T)mrand();
	T b = (T)mrand();
	T c = (T)mrand();
	T d = (T)mrand();
	double time = clock();
	while (num--) {
		b = a - c;
		c = a - b;
		a = b - c;
		d = a - b;
		b = a - d;
		a = b - d;
		b = a - b;
		c = b - d;
	}
	return (double)(MX) / (((double)(clock() - time)) / CLOCKS_PER_SEC);
}

template<typename T>
double test_efficiency_div(int num = MX) {
	num /= 2;
	T a = 1 + (T)mrand();
	T b = 1 + (T)mrand();
	T c = 1 + (T)mrand();
	double time = clock();
	while (num--) {
		c = a / b;
		b = c / a;
		a = (T)((int)(a) ^ 463945383);
		b = (T)((int)(a) ^ 432954383);
	}
	return (double)(MX) / (((double)(clock() - time)) / CLOCKS_PER_SEC);

}
template<typename T>
double test_efficiency_prod(int num = MX) {
	num /= 8;
	T a = (T)mrand();
	T b = (T)mrand();
	T c = (T)mrand();
	T d = (T)mrand();
	double time = clock();
	while (num--) {
		b = a * c;
		c = a * b;
		a = b * c;
		d = a * b;
		b = a * d;
		a = b * d;
		b = a * b;
		c = b * d;
	}
	return (double)(MX) / (((double)(clock() - time)) / CLOCKS_PER_SEC);
}
void conv(double d)
{
	int exponent = (int)floor(log10(fabs(d)));
	double base = d * pow(10, -1.0 * exponent);
	printf("%lfE%+01d", base, exponent);
}
int main()
{
	double ans[20];
	ans[0] = test_efficiency_plus<char>();
	ans[1] = test_efficiency_plus<int>();
	ans[2] = test_efficiency_plus<long long>();
	ans[3] = test_efficiency_plus<double>();
	ans[4] = test_efficiency_plus<long double>();
	ans[5] = test_efficiency_minus<char>();
	ans[6] = test_efficiency_minus<int>();
	ans[7] = test_efficiency_minus<long long>();
	ans[8] = test_efficiency_minus<double>();
	ans[9] = test_efficiency_minus<long double>();
	ans[10] = test_efficiency_div<char>();
	ans[11] = test_efficiency_div<int>();
	ans[12] = test_efficiency_div<long long>();
	ans[13] = test_efficiency_div<double>();
	ans[14] = test_efficiency_div<long double>();
	ans[15] = test_efficiency_prod<char>();
	ans[16] = test_efficiency_prod<int>();
	ans[17] = test_efficiency_prod<long long>();
	ans[18] = test_efficiency_prod<double>();
	ans[19] = test_efficiency_prod<long double>();
	/*
	Assigning number of operations per second
	*/
	string type_names[] = {"char       ",  "int        ", "long long  ", "double     ", "long double" };
	string operation_names[] = { "plus (+)", "minus (-)", "div (/)", "prod (*)" };

	double mx = *max_element(ans, ans + 16); //find maximum for percentage

	for (int i = 0; i < 20; i++) {
		if (i % 5 == 0) 
			cout << '\n' << operation_names[i / 5] << '\n' << '\n';

		double prt = ans[i] / mx; //percentage
		cout << setprecision(10) << fixed; 
		cout << type_names[i % 5] << " Made "; conv(ans[i]); cout << " operations per second "; //type and time
		cout << setprecision(2) << fixed << prt * 100 << "% "; 
		for (int j = 0; j < ceil(20 * prt); j++)cout << "X"; // percentage and slidebar

		cout << '\n';
	}

}

