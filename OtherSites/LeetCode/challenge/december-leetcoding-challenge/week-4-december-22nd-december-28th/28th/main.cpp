#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, set<int>> warp;
        for (int i=0; i<n; ++i) warp[arr[i]].insert(i);
        vector<int> dist(n, (int)(1e9));
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty() && dist[n-1]==(int)(1e9)) {
            int v = q.front(); q.pop();
            int vd = dist[v], nd = vd + 1;
            if (v-1>=0) {
                int nv = v - 1;
                if (dist[nv] > nd) {
                    q.push(nv);
                    dist[nv] = nd;
                }
            }
            if (v+1 < n) {
                int nv = v + 1;
                if (dist[nv] > nd) {
                    q.push(nv);
                    dist[nv] = nd;
                }
            }
            if (warp.find(arr[v]) != warp.end()) {
                auto nvset = warp[arr[v]];
                for (int nv : nvset) {
                    if (v == nv) continue;
                    if (dist[nv] > nd) {
                        q.push(nv);
                        dist[nv] = nd;
                    }
                }
                warp.erase(arr[v]);
            }
        }
        return dist[n-1];
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    int res = cl.minJumps(arr);
    cout << res << endl;
    return 0;
}
