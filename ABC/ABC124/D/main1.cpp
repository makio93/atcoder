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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi nums;
    int t = 1, cnt1 = 0;
    rep(i, n) {
        if (s[i]==(char)(t+'0')) ++cnt1;
        else {
            nums.pb(cnt1);
            t = 1 - t;
            cnt1 = 1;
        }
    }
    if (cnt1 != 0) nums.pb(cnt1);
    int left = 0, right = 0, len = 2 * k + 1;
    int ans = 0, cnt = 0;
    for (int i=0; i<(int)nums.size(); i+=2) {
        int n_left = i, n_right = min(i+len, (int)nums.size());
        while (left < n_left) {
            cnt -= nums[left];
            ++left;
        }
        while (right < n_right) {
            cnt += nums[right];
            ++right;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
