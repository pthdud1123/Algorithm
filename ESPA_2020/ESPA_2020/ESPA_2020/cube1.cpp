#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream inp("cube.inp");
    ofstream out("cube.out");
    while (1) {
        string value;
        inp >> value;
        char cube_1[6];
        char cube_2[6];
        char temp = value[0];
        bool CHECK = true;
        for (int i = 0; i < 6; i++) {
            cube_1[i] = value[i];
            cube_2[i] = value[6 + i];
            if (temp != value[i] || temp != value[6 + i]) {
                CHECK = false;
            }
        }
        if (CHECK) {
            out << "TRUE" << endl;
            break;
        }
        bool check = false;

        char dice_1[5];
        char dice_2[5];
        for (int i = 0; i < 6; i++) {//stand:cube_1 spare:cube_2
            if (cube_1[0] == cube_2[i] && cube_1[5] == cube_2[5 - i]) {
                dice_1[0] = cube_1[2];
                dice_1[1] = cube_1[1];
                dice_1[2] = cube_1[3];
                dice_1[3] = cube_1[4];
                if (i == 0) {
                    dice_2[0] = cube_2[2];
                    dice_2[1] = cube_2[1];
                    dice_2[2] = cube_2[3];
                    dice_2[3] = cube_2[4];
                }
                else if (i == 1) {
                    dice_2[0] = cube_2[2];
                    dice_2[1] = cube_2[5];
                    dice_2[2] = cube_2[3];
                    dice_2[3] = cube_2[0];
                }
                else if (i == 2) {
                    dice_2[0] = cube_2[5];
                    dice_2[1] = cube_2[1];
                    dice_2[2] = cube_2[0];
                    dice_2[3] = cube_2[4];
                }
                else if (i == 3) {
                    dice_2[0] = cube_2[0];
                    dice_2[1] = cube_2[1];
                    dice_2[2] = cube_2[5];
                    dice_2[3] = cube_2[4];
                }
                else if (i == 4) {
                    dice_2[0] = cube_2[2];
                    dice_2[1] = cube_2[0];
                    dice_2[2] = cube_2[3];
                    dice_2[3] = cube_2[5];
                }
                else if (i == 5) {
                    dice_2[0] = cube_2[2];
                    dice_2[1] = cube_2[4];
                    dice_2[2] = cube_2[3];
                    dice_2[3] = cube_2[1];
                }



                for (int j = 0; j < 5; j++) {
                    if (dice_1[0] == dice_2[j % 4] && dice_1[1] == dice_2[(j + 1) % 4] && dice_1[2] == dice_2[(j + 2) % 4] && dice_1[3] == dice_2[(j + 3) % 4]) {
                        check = true;
                        break;
                    }
                }


            }
            if (check)break;
        }


        if (check)out << "TRUE" << endl;
        else out << "FALSE" << endl;
    }
}