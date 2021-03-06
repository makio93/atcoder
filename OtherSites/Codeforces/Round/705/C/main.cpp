#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n%k != 0) {
            cout << -1 << endl;
            continue;
        }
        v(int) ccnt(26);
        rep(i, n) ccnt[(int)(s[i]-'a')]++;
        bool ok = true;
        rep(i, 26) if (ccnt[i]%k!=0) ok = false;
        if (ok) {
            cout << s << endl;
            continue;
        }
        string ans;
        repr(i, n) {
            ccnt[(int)(s[i]-'a')]--;
            rep2(j, (int)(s[i]-'a')+1, 25) {
                ccnt[j]++;
                int tsum = 0;
                rep(j2, 26) tsum += (ccnt[j2]%k==0?0:k-ccnt[j2]%k);
                if (tsum==(n-1)-i || (tsum<=(n-1)-i&&(tsum%k)==(((n-1)-i)%k))) {
                    string bstr;
                    rep(j2, 26) if (ccnt[j2]%k != 0) bstr += string(k-ccnt[j2]%k, (char)('a'+j2));
                    if (sz(bstr) < (n-1)-i) {
                        int kmul = (((n-1)-i) - sz(bstr)) / k;
                        bstr += string(k*kmul, 'a');
                    }
                    VSORT(bstr);
                    ans += s.substr(0,i) + (char)('a'+j) + bstr;
                    break;
                }
                ccnt[j]--;
            }
            if (!ans.empty()) break;
        }
        if (ans.empty()) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
