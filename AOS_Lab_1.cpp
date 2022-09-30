#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;
static long long holdrand = 1L;

#define MX (int)(1e8)

long double mrand() {
    return 0.3337 * (((holdrand = holdrand * 214013LL + 2531011LL) >> 16) & 0x7fff);
}
template<typename T>

double test_efficiency_plus(int num = MX) {
    num /= 8;
    T a, b, c, d, e;

    if (typeid(a) == typeid(12) || typeid(a) == typeid(12LL) || typeid(a) == typeid('a')) {
        a = 1278543;
        b = 34578235;
        c = 873459834;
        d = 0, e = 0;
    }
    else {
        a = 12785.43;
        b = 3452347.8235;
        c = 873324598.34;
        d = 0, e = 0;
    }
    double time = clock();
    while (num--) {
        d = b + a;
        e = c + a;
        d = c + b;
        e = e + d;
        d = b + a;
        e = c + a;
        d = c + b;
        e = e + d;
    }
    return (double)(MX) / (((double)(clock() - time)) / CLOCKS_PER_SEC);
}
template<typename T>
double test_efficiency_minus(int num = MX) {
    num /= 8;
    T a, b, c, d, e;

    if (typeid(a) == typeid(12) || typeid(a) == typeid(12LL) || typeid(a) == typeid('a')) {
        a = 1278543;
        b = 34578235;
        c = 873459834;
        d = 0, e = 0;
    }
    else {
        a = 12785.43;
        b = 3452347.8235;
        c = 873324598.34;
        d = 0, e = 0;
    }
    double time = clock();
    while (num--) {
        d = b - a;
        e = c - a;
        d = c - b;
        e = e - d;
        d = b - a;
        e = c - a;
        d = c - b;
        e = e - d;
    }
    return (double)(MX) / (((double)(clock() - time)) / CLOCKS_PER_SEC);
}

template<typename T>
double test_efficiency_div(int num = MX) {
    num /= 8;
    T a, b, c, d, e;
    if (typeid(a) == typeid(12) || typeid(a) == typeid(12LL) || typeid(a) == typeid('a')) {
        a = 1278543;
        b = 34578235;
        c = 873459834;
        d = 0, e = 0;
    }
    else {
        a = 12785.43;
        b = 3452347.8235;
        c = 873324598.34;
        d = 0, e = 0;
    }
    double time = clock();
    while (num--) {
        d = b / a;
        e = c / a;
        d = c / b;
        e = e / d;
        d = b / a;
        e = c / a;
        d = c / b;
        e = e / d;
    }
    return (double)(MX) / (((double)(clock() - time)) / CLOCKS_PER_SEC);

}
template<typename T>
double test_efficiency_prod(int num = MX) {
    num /= 8;
    T a, b, c, d, e; 
    if (typeid(a) == typeid(12)  || typeid(a) == typeid(12LL)  || typeid(a) == typeid('a')) {
        a = 1271238543;
        b = 345782235;
        c = -83273459834;
        d = 0, e = 0;
    }
    else {
        a = 12783.2543;
        b = -3452347.8235;
        c = 873324598.34;
        d = 0, e = 0;
    }
    double time = clock();
    while (num--) {
        d = b * a;
        e = c * a;
        c = c * b;
        b = e * d;
        d = b * a;
        a = c * a;
        e = c * b;
        e = e * d;
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
    cout << setprecision(10) << fixed;
    for (int i = 0; i < 20; i++) cout << ans[i] << ' '; cout << '\n';

    /*
    Assigning number of operations per second
    */
    string type_names[] = { "char       ",  "int        ", "long long  ", "double     ", "long double" };
    string operation_names[] = { "plus (+)", "minus (-)", "div (/)", "prod (*)" };

    double mx = *max_element(ans, ans + 20); //find maximum for percentage

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