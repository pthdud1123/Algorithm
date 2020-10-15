#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main() {
    ifstream inp("sequence.inp");
    ofstream out("sequence.out");
    int n;
    inp >> n;
    int S[1001], C[1001], result[1001], check[1001];
    int temp;
    for (int i = 0; i < n; i++) {
        inp >> S[i];
    }
    for (int i = 0; i < n; i++) {
        inp >> C[i];
    }
    sort(S, S + n);
    check[0] = 0;
    int number = 0;
    for (int i = 1; i < n; i++) {
        if (S[i] > S[i - 1]) {
            check[i] = i;
        }
        else if (S[i] == S[i - 1]) {
            check[i] = check[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        bool c = true;
        for (int j = 0; j < n; j++) {
            if (C[i] == check[j] && c == true) {
                result[i] = S[j];
                check[j] = -1;
                c = false;
            }
            else if (C[i] < check[j]) {
                check[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        out << result[i] << endl;
    }

    return 0;
}