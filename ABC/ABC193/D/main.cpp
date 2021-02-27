#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

ll calc(v(int)& tcard) {
    ll res = 0;
    rep2(i, 1, 9) {
        ll ten = 1;
        rep(j, tcard[i]) ten *= 10LL;
        res += (ll)i * ten;
    }
    return res;
}

int main(){
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    v(int) card(10, k), mcard1(10), mcard2(10);
    rep(i, 4) {
        card[(int)(s[i]-'0')]--;
        mcard1[(int)(s[i]-'0')]++;
    }
    rep(i, 4) {
        card[(int)(t[i]-'0')]--;
        mcard2[(int)(t[i]-'0')]++;
    }
    ll wins = 0;
    rep2(i, 1, 9) rep2(j, 1, 9) {
       auto tcard1 = mcard1, tcard2 = mcard2;
       tcard1[i]++; tcard2[j]++;
       ll tval1 = calc(tcard1), tval2 = calc(tcard2);
       if (tval1 > tval2) {
           ll twins = 0;
           if (i == j) twins += (ll)card[i] * (card[i] - 1);
           else twins += (ll)card[i] * card[j];
           wins += twins;
       }
    }
    ll alval = (ll)(9LL * k - 8) * (9LL * k - 9);
    printf("%.10f\n", (double)wins / alval);
    return 0;
}
