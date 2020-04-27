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

const int n_max = 10, num_max = 1e8;
vs c(n_max);
vector<bool> used(n_max);
vs perm(n_max);
set<int> num;
void dfs(int pos, int n, int k) {
    if (pos == k) {
        string res;
        rep(i, k) res += perm[i];
        num.insert(stoi(res));
        return;
    }
    rep(i, n) {
        if (used[i]) continue;
        used[i] = true;
        perm[pos] = c[i];
        dfs(pos+1, n, k);
        used[i] = false;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> c[i];
    dfs(0, n, k);
    cout << num.size() << endl;
    return 0;
}
