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

// きまぐれ精進、自力AC

int main(){
    string c;
    cin >> c;
    bool unknown = false;
    int n = c.size(), l = 0, r = n-1;
    while (l<n && c[l]=='_') ++l;
    while (r>=0 && c[r]=='_') --r;
    if (l>=n || !islower(c[l])) unknown = true;
    if (!unknown) {
        string c2 = c.substr(l, r-l+1);
        int t = 0;
        vector<string> words = { "" };
        rep(i, sz(c2)) {
            if (islower(c2[i]) || isdigit(c2[i])) {
                if ((words.back().size())==0 && isdigit(c2[i])) {
                    unknown = true;
                    break;
                }
                words.back() += tolower(c2[i]);
            }
            else {
                if (t==0) {
                    if (isupper(c2[i])) t = 1;
                    else if (c2[i] == '_') t = 2;
                    else {
                        unknown = true;
                        break;
                    }
                }
                else {
                    if (!(t==1&&isupper(c2[i])) && !(t==2&&c2[i]=='_')) {
                        unknown = true;
                        break;
                    }
                }
                if (sz(words.back()) == 0) {
                    unknown = true;
                    break;
                }
                words.pb("");
                if (t==1) {
                    if (!isupper(c2[i])) {
                        unknown = true;
                        break;
                    }
                    words.back() += tolower(c2[i]);
                }
            }
        }
        if (t==0) unknown = true;
        if (!unknown) {
            string ans = string(l, '_');
            rep(i, sz(words)) {
                if (t==1) {
                    ans += words[i];
                    if (i < sz(words)-1) ans += '_';
                }
                else {
                    string nword(1, (i==0?words[i][0]:toupper(words[i][0])));
                    if (sz(words[i]) > 1) nword += words[i].substr(1);
                    ans += nword;
                }
            }
            ans += string(n-r-1, '_');
            cout << ans << endl;
        }
    }
    if (unknown) cout << c << endl;
    return 0;
}
