#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    map<int, int> mp;
    rep(i, n) mp[a[i]]++;
    int cnt = 0;
    for (auto p : mp) {
        if (p.second == 1) ++cnt;
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (auto p : mp) {
        if (p.second == 0) continue;
        int s = p.first;
        for (int i=2; i*s<=1000000; ++i) {
            if (mp[i*s] == 1) mp[i*s] = 0;
        }
    }
    int cnt2 = 0;
    for (auto p : mp) {
        if (p.second == 1) ++cnt2;
    }
    cout << cnt2 << endl;
    return 0;
}
