#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const long long mod = 1e9 + 7;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
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

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main(){
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<double> x(n), y(n), z(n), r(n);
        rep(i, n) cin >> x[i] >> y[i] >> z[i] >> r[i];
        set<int> cell;
        multimap<double, int> cor;
        double ans = 0.0;
        cor.insert(mp(0.0, 0));
        while (sz(cell) < n) {
            double len = cor.begin()->first;
            int v = cor.begin()->second;
            cor.erase(cor.begin());
            if (!cell.insert(v).second) continue;
            ans += len;
            rep(i, n) if (cell.find(i) == cell.end()) {
                cor.insert(mp(max(0.0, dist(x[v],y[v],z[v],x[i],y[i],z[i])-r[v]-r[i]), i));
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
