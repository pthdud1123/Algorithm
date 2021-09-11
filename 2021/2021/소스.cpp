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

        //���� ������ ������ ������ �ִ� map
        map<char, char> conv;
        int a = A.size();
        for (int i = 0;i < a;++i)
            conv[A[i]] = A[(i + 1) % a];

        int w = W.size();
        //A������ ���� ��ŭ shift�� ������ ����� ������Ʈ ���ֹǷ�
        //������ shift�� �����ϴ� ���̴� 0�Ǵ� 1�̴�.
        //ex)BCA�� ABC���� 1�� SHIFT �Ѱ��, CAB�� ABC���� 2�� SHIFT�� ���
        //���� BCA �������δ� 1���� SHIFT �ϸ� �ȴ�.
        for (int shift = 0;shift < a;++shift) {

            if (shift != 0) {
                for (int k = 0;k < w;++k)
                    W[k] = conv[W[k]];
            }

            int fail[50001]{};

            //���ο� W�� �����Լ�
            for (int i = 1, j = 0;i < w;++i) {
                while (j && W[i] != W[j]) j = fail[j - 1];
                if (W[i] == W[j]) fail[i] = ++j;
            }
            bool FIND = false;
            int s = S.size();

            //S���� W�� ã�� kmp �˰���
            for (int i = 0, j = 0;i < s;++i) {
                while (j && S[i] != W[j]) j = fail[j - 1];
                if (S[i] == W[j]) {
                    if (j == w - 1) {
                        //���� ��ã�Ҵٸ� true
                        if (!FIND) {
                            FIND = true;
                            j = fail[j];
                        }
                        //�̹� ã�Ҵµ� �� �߰��ߴٸ� false
                        else {
                            FIND = false;
                            break;
                        }
                    }
                    else ++j;
                }
            }
            // �Ѱ��� ã�Ҵٸ� ���信 �־�����
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