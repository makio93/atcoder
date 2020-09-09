#include <bits/stdc++.h>
using namespace std;

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


void func(long long N, long long K, std::vector<long long> A){

}

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vi cnt(n);
    int p = 0, roop = -1, ans = -1;
    rep1(i, n) {
        if (k == 0) {
            ans = p + 1;
            break;
        }
        if (cnt[p] != 0) {
            roop = i - cnt[p];
            k %= roop;
            int q = p;
            rep(j, k) {
                q = a[q];
            }
            ans = q + 1;
            break;
        }
        cnt[p] = i;
        p = a[p];
        --k;
    }
    cout << ans << endl;
    return 0;
}
