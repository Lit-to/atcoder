#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    if (N % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    map<int, bool> usedNum;
    for (int i = 0;i < N / 2;++i) {
        if (S.at(2 * i + 1) == S.at(2 * i) && usedNum.contains(int(S.at(2 * i))) == false) {
            usedNum[int(S.at(2 * i))] = true;
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
