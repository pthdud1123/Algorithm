#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
int main() {
    ifstream inp("expression.inp");
    ofstream out("expression.out");
    int T;
    inp >> T;
    for (int i = 0; i < T; i++) {
        stack<int>n;
        stack<char>s;
        int temp = 0;
        char sign = ' ';
        bool check = true;
        inp >> temp;
        n.push(temp);
        while (1) {
            inp >> sign;
            if (sign == '=')
                break;

            else if (sign == '*') {
                inp >> temp;
                n.top() *= temp;
            }
            else if (sign == '/') {
                inp >> temp;
                if (temp == 0) {
                    check = false;
                    temp = 1;
                }
                n.top() /= temp;
            }
            else if (sign == '%') {
                inp >> temp;
                if (temp == 0) {
                    check = false;
                    temp = 1;
                }
                n.top() %= temp;
            }
            else if ((sign == '+' || sign == '-') && !s.empty()) {
                inp >> temp;
                int t1 = n.top();
                n.pop();
                if (s.top() == '+') {
                    n.top() += t1;
                }
                else if (s.top() == '-') {
                    n.top() -= t1;
                }
                s.pop();
                s.push(sign);
                n.push(temp);
            }
            else if ((sign == '+' || sign == '-') && s.empty()) {
                inp >> temp;
                s.push(sign);
                n.push(temp);
            }
        }
        while (!s.empty() && check == true) {
            int t1 = n.top();
            n.pop();
            if (s.top() == '+') {
                n.top() += t1;
            }
            else if (s.top() == '-') {
                n.top() -= t1;
            }
            s.pop();
        }
        if (!check) {
            out << "Error!" << endl;
        }
        else {
            out << n.top() << endl;
        }
    }
    return 0;
}