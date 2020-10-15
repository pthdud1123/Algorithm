#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;


int main() {
    ifstream inp("polygon.inp");
    ofstream out("polygon.out");
    int T;
    inp >> T;
    for (int n = 0; n < T; n++) {
        int N;
        inp >> N;
        int arr[40002];
        int arr2[40002];
        int tem[20001];
        int arr_r[20001];
        for (int i = 0; i < N; i++) {
            inp >> arr[i];
        }
        for (int i = 0; i < N; i++) {
            inp >> arr2[i];
        }
        for (int i = N; i < 2 * N; i++) {
            arr2[i] = arr2[i - N];
        }
        for (int i = N - 1; i >= 0; i--) {
            if (i == 0) {
                if (arr[N - 1] > 0)arr_r[N - 1 - i] = abs(arr[0]) * -1;
                else arr_r[N - 1 - i] = abs(arr[0]);
            }
            else {
                if (arr[i - 1] > 0)arr_r[N - 1 - i] = abs(arr[i]) * -1;
                else arr_r[N - 1 - i] = abs(arr[i]);
            }
        }


        bool check = false;

        for (int i = 0; i < N * 2; i++) {
            if (arr_r[0] == arr2[i]) {
                for (int j = 1; j < N; j++) {
                    if (arr_r[j] != arr2[i + j]) {
                        check = false;
                        break;
                    }
                    else if (j == N - 1)check = true;
                }
            }
            if (check)break;

        }
        if (!check) {
            for (int i = 0; i < N * 2; i++) {
                if (arr[0] == arr2[i]) {
                    for (int j = 1; j < N; j++) {
                        if (arr[j] != arr2[i + j]) {
                            check = false;
                            break;
                        }
                        else if (j == N - 1)check = true;
                    }
                }
                if (check)break;

            }
        }

        if (check) out << 1 << endl;
        else out << 0 << endl;




    }
}