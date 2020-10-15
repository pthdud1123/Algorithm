#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream inp("bowling.inp");
    ofstream out("bowling.out");

    int T;
    inp >> T;
    for (int i = 0; i < T; i++) {
        int game[12] = { 0, };
        bool spare = false, strike = false;
        int strikenumber = 0;
        int t1, t2;

        for (int j = 1; j < 10; j++) {
            inp >> t1;
            if (t1 == 10) {
                game[j] += 10;

                if (!strike) {
                    strike = true;
                    strikenumber++;
                    if (spare) {
                        game[j - 1] += 10;
                        spare = false;
                    }
                }
                else if (strike) {

                    if (strikenumber == 2) {
                        game[j - 2] += 10;
                        game[j - 1] += 10;
                    }
                    if (strikenumber == 1) {
                        game[j - 1] += 10;
                    }
                    if (strikenumber < 2) {
                        strikenumber++;
                    }
                }


            }
            else {
                inp >> t2;
                if (t1 + t2 < 10) {
                    if (strike) {
                        if (strikenumber == 1) {
                            game[j - 1] += (t1 + t2);
                        }
                        else if (strikenumber == 2) {
                            game[j - 1] += (t1 + t2);
                            game[j - 2] += (t1);

                        }
                        strike = false;
                        strikenumber = 0;
                    }
                    else if (spare) {
                        game[j - 1] += t1;
                        spare = false;
                    }

                    game[j] = t1 + t2;

                }
                else if (t1 + t2 == 10) {
                    game[j] += 10;
                    if (strike) {
                        if (strikenumber == 1) {
                            game[j - 1] += (t1 + t2);
                        }
                        else if (strikenumber == 2) {
                            game[j - 1] += (t1 + t2);
                            game[j - 2] += (t1);

                        }
                        strike = false;
                        strikenumber = 0;
                    }
                    else if (spare) {
                        game[j - 1] += t1;
                        spare = false;
                    }
                    spare = true;

                }


            }

        }
        inp >> t1 >> t2;
        int t3;
        if (t1 + t2 >= 10) {
            inp >> t3;

            if (strikenumber == 1) {
                game[9] += t1 + t2;
            }

            else if (strikenumber == 2) {
                game[8] += (t1);
                game[9] += (t2 + t1);
            }
            else if (spare) {
                game[9] += (t1);
            }

            game[10] = t1 + t2 + t3;
        }

        else if (t1 + t2 < 10) {

            if (strikenumber == 1) {
                game[9] += (t1 + t2);
            }

            else if (strikenumber == 2) {
                game[8] += (t1);
                game[9] += (t2 + t1);
            }
            else if (spare) {
                game[9] += (t1);
            }

            game[10] = t1 + t2;
        }

        int result = 0;
        for (int x = 1; x <= 10; x++) {
            result += game[x];
        }
        out << result << endl;
    }
    return 0;
}