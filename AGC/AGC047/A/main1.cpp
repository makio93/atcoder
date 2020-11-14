#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
    vll a(n);
    rep(i, n) {
        string ai;
        cin >> ai;
        int ppos = ai.find_first_of('.');
        if (ppos == (int)(string::npos)) a[i] = stoll(ai) * (ll)(1e9);
        else {
            a[i] += stoll(ai.substr(0, ppos)) * (ll)(1e9);
            ll add = stoll(ai.substr(ppos+1));
            int len = 9 - (sz(ai) - ppos - 1);
            rep(j, len) add *= 10;
            a[i] += add;
        }
    }
    vpii msum(n);
    rep(i, n) {
        ll val = a[i];
        while (val%2 == 0) {
            val /= 2;
            msum[i].first++;
        }
        while (val%5 == 0) {
            val /= 5;
            msum[i].second++;
        }
        msum[i].first = min(msum[i].first, 18);
        msum[i].second = min(msum[i].second, 18);
    }
    map<pii, int> cnt;
    rep(i, n) cnt[msum[i]]++;
    ll ans = 0;
    for (auto itr=cnt.begin(); itr!=cnt.end(); ++itr) {
        for (auto itr2=itr; itr2!=cnt.end(); ++itr2) {
            if ((itr->first.first)+(itr2->first.first) < 18) continue;
            if ((itr->first.second)+(itr2->first.second) < 18) continue;
            if (itr == itr2) ans += (ll)(itr->second)*(itr->second-1LL)/2LL;
            else ans += (ll)(itr->second) * (itr2->second);
        }
    }
    cout << ans << endl;
    return 0;
}
