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

const string YES = "Yes";
const string NO = "No";

int main(){
    int h, w;
    cin >> h >> w;
    vi cnt(26);
    rep(i, h) {
        string a;
        cin >> a;
        rep(j, w) cnt[a[j]-'a']++;
    }
    vi nums(h*w+1);
    rep(i, sz(cnt)) if (cnt[i]!=0) nums[cnt[i]]++;
    if (h%2==0 && w%2==0) {
        bool ok = true;
        for (int i=0; i<sz(nums); ++i) {
            if (i%4==0) continue;
            if (nums[i]!=0) ok =false;
        }
        if (!ok) cout << NO << endl;
        else cout << YES << endl;
    }
    else if (h%2==0 || w%2==0) {
        int val = 0;
        if (h%2!=0) val = w/2;
        else val = h/2;
        bool ok = true;
        for (int i=0; i<sz(nums); ++i) {
            if (i%4==0) continue;
            if (i%2==0) {
                val -= nums[i];
                if (val < 0) ok = false;
            }
            else if (nums[i]!=0) ok = false;
        }
        if (!ok) cout << NO << endl;
        else cout << YES << endl;
    }
    else {
        int val = w/2 + h/2, val2 = 1;
        bool ok = true;
        for (int i=0; i<sz(nums); ++i) {
            if (i%4==0) continue;
            if (i%2==0) {
                val -= nums[i];
                if (val < 0) ok = false;
            }
            else {
                val2 -= nums[i];
                if (val2 < 0) ok = false;
            }
        }
        if (!ok) cout << NO << endl;
        else cout << YES << endl;
    }
    return 0;
}
