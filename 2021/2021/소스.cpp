#include <iostream>
#include<vector>
#include<map>
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=1;i<=n;++i)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

int tc;

string A, W, S;
int main() {
    FAST;
    cin >> tc;
    while (tc--) {
        vector<int> ans;
        cin >> A >> W >> S;

        //다음 문자의 정보를 가지고 있는 map
        map<char, char> conv;
        int a = A.size();
        for (int i = 0;i < a;++i)
            conv[A[i]] = A[(i + 1) % a];

        int w = W.size();
        //A이하의 길이 만큼 shift를 수행한 결과를 업데이트 해주므로
        //실제로 shift를 수행하는 길이는 0또는 1이다.
        //ex)BCA는 ABC에서 1번 SHIFT 한결과, CAB는 ABC에서 2번 SHIFT한 결과
        //지만 BCA 기준으로는 1번만 SHIFT 하면 된다.
        for (int shift = 0;shift < a;++shift) {

            if (shift != 0) {
                for (int k = 0;k < w;++k)
                    W[k] = conv[W[k]];
            }

            int fail[50001]{};

            //새로운 W의 실패함수
            for (int i = 1, j = 0;i < w;++i) {
                while (j && W[i] != W[j]) j = fail[j - 1];
                if (W[i] == W[j]) fail[i] = ++j;
            }
            bool FIND = false;
            int s = S.size();

            //S에서 W를 찾는 kmp 알고리즘
            for (int i = 0, j = 0;i < s;++i) {
                while (j && S[i] != W[j]) j = fail[j - 1];
                if (S[i] == W[j]) {
                    if (j == w - 1) {
                        //아직 못찾았다면 true
                        if (!FIND) {
                            FIND = true;
                            j = fail[j];
                        }
                        //이미 찾았는데 또 발견했다면 false
                        else {
                            FIND = false;
                            break;
                        }
                    }
                    else ++j;
                }
            }
            // 한개만 찾았다면 정답에 넣어주자
            if (FIND)
                ans.emplace_back(shift);
        }
        if (ans.size() == 0) {
            cout << "no solution" << '\n';
        }
        else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << '\n';
        }
        else {
            cout << "ambiguous: ";
            for (auto x : ans)
                cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}