#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
int main() {
    ifstream inp("turtle.inp");
    ofstream out("turtle.out");

    int T;
    inp >> T;
    for (int i = 0; i < T; i++) {
        string temp;
        inp >> temp;
        int N = 0, W = 0;//(0,0)을 기준으로
        int Max = 0, Min = 0, max = 0, min = 0;
        char direction = 'n';
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == 'F') {
                if (direction == 'n') {
                    N++;
                }
                else if (direction == 's') {
                    N--;
                }
                else if (direction == 'w') {
                    W++;
                }
                else if (direction == 'e') {
                    W--;
                }
            }
            if (temp[j] == 'B') {
                if (direction == 'n') {
                    N--;
                }
                else if (direction == 's') {
                    N++;
                }
                else if (direction == 'w') {
                    W--;
                }
                else if (direction == 'e') {
                    W++;
                }
            }
            if (temp[j] == 'L') {
                if (direction == 'n') {
                    direction = 'w';
                }
                else if (direction == 's') {
                    direction = 'e';
                }
                else if (direction == 'w') {

                    direction = 's';
                }
                else if (direction == 'e') {
                    direction = 'n';

                }
            }
            if (temp[j] == 'R') {
                if (direction == 'n') {
                    direction = 'e';


                }
                else if (direction == 's') {
                    direction = 'w';

                }
                else if (direction == 'w') {
                    direction = 'n';

                }
                else if (direction == 'e') {
                    direction = 's';

                }
            }
            if (N > Max) {
                Max = N;
            }
            if (N < Min) {
                Min = N;
            }
            if (W > max) max = W;
            if (W < min)min = W;
        }


        out << abs((Max - Min) * (max - min)) << endl;
    }
}