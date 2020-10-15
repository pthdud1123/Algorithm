#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream inp("bitmap.inp");
ofstream out("bitmap.out");
int row, col, n = 0, p_n = 0;
string value;
void Division(int r, int c, int R, int C, int arr[][201]) {
    bool check = true;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[r][c] != arr[r + i][c + j]) {
                check = false;
                if (p_n == 50) {
                    out << endl;
                    p_n = 0;
                }
                p_n++;
                out << "D";
                break;
            }
        }
        if (!check)break;
    }
    if (check) {
        if (p_n == 50) {
            out << endl;
            p_n = 0;
        }
        p_n++;
        out << arr[r][c];
    }
    else {

        if (R == 1) {
            //행이 한줄인 왼쪽 오른쪽 분리 경우
            if (C % 2 == 1) {
                Division(r, c, R, (C / 2) + 1, arr);
                Division(r, c + (C / 2) + 1, R, (C / 2), arr);
            }
            else {
                Division(r, c, R, C / 2, arr);
                Division(r, c + (C / 2), R, C / 2, arr);
            }
        }
        else if (C == 1) {
            //열이 한줄인 위쪽 아래쪽분리 경우
            if (R % 2 == 1) {
                Division(r, c, (R / 2) + 1, C, arr);
                Division(r + (R / 2) + 1, c, R / 2, C, arr);
            }
            else {
                Division(r, c, R / 2, C, arr);
                Division(r + (R / 2), c, R / 2, C, arr);
            }
        }
        else if (R % 2 == 1 && C % 2 == 1) {
            //행과 열이 홀수 인 경우
            Division(r, c, R / 2 + 1, C / 2 + 1, arr);
            Division(r, c + (C / 2) + 1, R / 2 + 1, C / 2, arr);
            Division(r + (R / 2) + 1, c, R / 2, C / 2 + 1, arr);
            Division(r + (R / 2) + 1, c + (C / 2) + 1, R / 2, C / 2, arr);
        }
        else if (R % 2 == 1 && C % 2 == 0) {
            //행만 홀수 인경우
            Division(r, c, R / 2 + 1, C / 2, arr);
            Division(r, c + C / 2, R / 2 + 1, C / 2, arr);
            Division(r + R / 2 + 1, c, R / 2, C / 2, arr);
            Division(r + R / 2 + 1, c + C / 2, R / 2, C / 2, arr);
        }
        else if (R % 2 == 0 && C % 2 == 1) {
            //열만 홀수인 경우
            Division(r, c, R / 2, C / 2 + 1, arr);
            Division(r, c + C / 2 + 1, R / 2, C / 2, arr);
            Division(r + R / 2, c, R / 2, C / 2 + 1, arr);
            Division(r + R / 2, c + C / 2 + 1, R / 2, C / 2, arr);
        }
        else if (R % 2 == 0 && C % 2 == 0) {
            //행과 열 짝수 인경우
            Division(r, c, R / 2, C / 2, arr);
            Division(r, c + C / 2, R / 2, C / 2, arr);
            Division(r + R / 2, c, R / 2, C / 2, arr);
            Division(r + R / 2, c + C / 2, R / 2, C / 2, arr);
        }
    }

}
void Division2(int r, int c, int R, int C, int arr[][201]) {
    if (value[n] == 'D') {
        n++;
        if (R == 1) {
            if (C % 2 == 1) {
                Division2(r, c, R, C / 2 + 1, arr);
                Division2(r, c + C / 2 + 1, R, C / 2, arr);
            }
            else {
                Division2(r, c, R, C / 2, arr);
                Division2(r, c + C / 2, R, C / 2, arr);
            }
        }
        else if (C == 1) {
            if (R % 2 == 1) {
                Division2(r, c, R / 2 + 1, C, arr);
                Division2(r + R / 2 + 1, c, R / 2, C, arr);
            }
            else {
                Division2(r, c, R / 2, C, arr);
                Division2(r + R / 2, c, R / 2, C, arr);
            }

        }
        else if (R % 2 == 1 && C % 2 == 1) {
            Division2(r, c, R / 2 + 1, C / 2 + 1, arr);
            Division2(r, c + C / 2 + 1, R / 2 + 1, C / 2, arr);
            Division2(r + R / 2 + 1, c, R / 2, C / 2 + 1, arr);
            Division2(r + R / 2 + 1, c + C / 2 + 1, R / 2, C / 2, arr);

        }
        else if (R % 2 == 1 && C % 2 == 0) {
            Division2(r, c, R / 2 + 1, C / 2, arr);
            Division2(r, c + C / 2, R / 2 + 1, C / 2, arr);
            Division2(r + R / 2 + 1, c, R / 2, C / 2, arr);
            Division2(r + R / 2 + 1, c + C / 2, R / 2, C / 2, arr);

        }
        else if (R % 2 == 0 && C % 2 == 1) {
            Division2(r, c, R / 2, C / 2 + 1, arr);
            Division2(r, c + C / 2 + 1, R / 2, C / 2, arr);
            Division2(r + R / 2, c, R / 2, C / 2 + 1, arr);
            Division2(r + R / 2, c + C / 2 + 1, R / 2, C / 2, arr);
        }
        else if (R % 2 == 0 && C % 2 == 0) {
            Division2(r, c, R / 2, C / 2, arr);
            Division2(r, c + C / 2, R / 2, C / 2, arr);
            Division2(r + R / 2, c, R / 2, C / 2, arr);
            Division2(r + R / 2, c + C / 2, R / 2, C / 2, arr);
        }
    }
    else {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (value[n] == '1') {
                    arr[r + i][c + j] = 1;
                }
                else {
                    arr[r + i][c + j] = 0;
                }
            }
        }
        n++;
    }
}

int main() {
    char type;
    inp >> type;
    while (type != '#') {
        int arr[201][201] = { 0, };
        inp >> row >> col;
        inp >> value;
        string v;
        while (value.size() % 50 == 0) {
            inp >> v;
            if (v == "B" || v == "D") {
                break;
            }
            value = value + v;
        }
        if (type == 'B') {
            out << "D" << " " << row << " " << col << endl;
            int num = 0;
            for (int i = 1; i <= row; i++) {
                for (int j = 1; j <= col; j++) {
                    if (value[num] == '1')
                        arr[i][j] = 1;
                    else arr[i][j] = 0;
                    num++;
                }
            }
            Division(1, 1, row, col, arr);
            out << endl;
        }
        if (type == 'D') {
            out << "B" << " " << row << " " << col << endl;
            Division2(1, 1, row, col, arr);
            for (int i = 1; i <= row; i++) {
                for (int j = 1; j <= col; j++) {
                    if (p_n == 50) {
                        out << endl;
                        p_n = 0;
                    }
                    out << arr[i][j];
                    p_n++;
                }
            }
            out << endl;

        }

        if (v[0] == 'B' && v.size() == 1) {
            type = 'B';
        }
        else if (v[0] == 'D' && v.size() == 1) {
            type = 'D';
        }
        else if (v[0] == '#' && v.size() == 1) {
            type = '#';
        }
        else {
            inp >> type;
        }
        n = 0, p_n = 0, value = "";
    }
}