#include<iostream>
#include<fstream>
using namespace std;

long long fibonacci(long long d_number, long long number, long long p[], long long R[], long long M) {
    if (number > 1) {
        if (number % 2 == 1) {
            fibonacci(d_number, number / 2, p, R, M);
            R[1] = (p[1] + p[2]) % M;
            R[2] = p[1] % M;
            R[3] = (p[3] + p[4]) % M;
            R[4] = p[3] % M;
            p[1] = R[1] % M, p[2] = R[2] % M, p[3] = R[3] % M, p[4] = R[4] % M;

        }
        else if (number % 2 == 0) {
            fibonacci(d_number, number / 2, p, R, M);
        }
    }

    if (number == 1 || number == 0) {
        R[1] = 2;
        R[2] = 1;
        R[3] = 1;
        R[4] = 1;
        p[1] = R[1] % M, p[2] = R[2] % M, p[3] = R[3] % M, p[4] = R[4] % M;
    }
    else if (number == d_number) {
        return R[2] % M;
    }
    else {
        R[1] = ((p[1] * p[1]) % M + (p[2] * p[3]) % M) % M;
        R[2] = ((p[1] * p[2]) % M + (p[2] * p[4]) % M) % M;
        R[3] = ((p[1] * p[3]) % M + (p[3] * p[4]) % M) % M;
        R[4] = ((p[2] * p[3]) % M + (p[4] * p[4]) % M) % M;
        p[1] = R[1] % M, p[2] = R[2] % M, p[3] = R[3] % M, p[4] = R[4] % M;
    }

}

int main() {
    ifstream inp("fibonacci.inp");
    ofstream out("fibonacci.out");

    int T;
    inp >> T;
    for (int k = 0; k < T; k++) {
        long long a, b, c, d, M;
        inp >> a >> b >> c >> d >> M;
        long long result_value[5] = { 0,a,b,c,d };
        for (int i = 1; i < 5; i++) {
            long long p[5] = { 0, }, R[5] = { 0, };
            result_value[i] = fibonacci(result_value[i], result_value[i], p, R, M);
        }
        long long result = ((result_value[1] * result_value[2]) % M + (result_value[3] * result_value[4]) % M) % M;
        out << result << endl;
    }
}