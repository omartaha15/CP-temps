#include <bits/stdc++.h>

#pragma GCC optimize "trapv"

using namespace std;

#define Graph vector<vector<int>>
#define ll long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()

template<class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    for (auto &x: A) out << x << ' ';
    return out;
}

template<class T>
istream &operator>>(istream &in, vector<T> &A) {
    for (auto &x: A) in >> x;
    return in;
}

void Fun() {
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        Fun();
    }
}
