#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    if (N % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    int i = 0;
    int correct = int('1');
    while (i < (N + 1) / 2 - 1) {
        if (int(S.at(i)) == correct) {
            ++i;
            continue;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (S[i] != int('/')) {
        cout << "No" << endl;
        return 0;
    }
    ++i;
    ++correct;
    while (i < N) {
        if (int(S.at(i)) == correct) {
            ++i;
            continue;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
