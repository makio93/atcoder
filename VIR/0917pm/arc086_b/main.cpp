#include <bits/stdc++.h>
using namespace std;

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
    rep(i, n) {
        int m = 0;
        vi b = a;
        vpii ans;
        bool ng = false;
        for (int j=i; j-1>=0; --j) {
            if (b[j-1]>b[j]) {
                if (b[j]>=0 && b[j-1]>=0) {
                    ng = true;
                    break;
                }
                while (m<=2*n && b[j-1]>b[j]) {
                    if (abs(b[j-1]+b[j]-b[j-1])<abs(b[j-1]+b[j]-b[j])) {
                        b[j-1] += b[j-1];
                        ans.emplace_back(j, j);
                    }
                    else {
                        b[j-1] += b[j];
                        ans.emplace_back(j+1, j);
                    }
                    ++m;
                }
                if (m > 2*n) {
                    ng = true;
                    break;
                }
            }
        }
        if (ng) continue;
        for (int j=i; j+1<n; ++j) {
            if (b[j+1]<b[j]) {
                if (b[j]<=0 && b[j+1]<=0) {
                    ng = true;
                    break;
                }
                while (m<=2*n && b[j+1]<b[j]) {
                    if (abs(b[j+1]+b[j]-b[j+1])<abs(b[j+1]+b[j]-b[j])) {
                        b[j+1] += b[j+1];
                        ans.emplace_back(j+2, j+2);
                    }
                    else {
                        b[j+1] += b[j];
                        ans.emplace_back(j+1, j+2);
                    }
                    ++m;
                }
                if (m > 2*n) {
                    ng = true;
                    break;
                }
            }
        }
        if (ng) continue;
        cout << m << endl;
        rep(j, sz(ans)) {
            printf("%d %d\n", ans[j].first, ans[j].second);
        }
        break;
    }
    return 0;
}
