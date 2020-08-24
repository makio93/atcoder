#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

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

class UnionFind {
private:
    vi p;
public:
    UnionFind(int size) : p(size, -1) {}
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (abs(p[x]) < abs(p[y])) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }
private:
    int root(int x) { return (p[x] < 0) ? x : (p[x] = root(p[x])); }
};

struct Corrider {
    int a, b;
    double len;
    Corrider(int a, int b, double len) : a(a), b(b), len(len) {}
    const bool operator<(const Corrider& x) const {
        if (len != x.len) return (len < x.len);
        else if (a != x.a) return (a < x.a);
        return (b < x.b);
    }
};

double calcDist(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main(){
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<double> x(n), y(n), z(n), r(n);
        rep(i, n) cin >> x[i] >> y[i] >> z[i] >> r[i];
        UnionFind f(n);
        vector<Corrider> cor;
        rep(i, n) for (int j=i+1; j<n; ++j) {
            cor.pb(Corrider(i, j, max(0.0, calcDist(x[i],y[i],z[i],x[j],y[j],z[j])-r[i]-r[j])));
        }
        VSORT(cor);
        int cnt = 0;
        double ans = 0.0;
        for (vector<Corrider>::iterator itr=cor.begin(); cnt<n-1; ++itr) {
            if (!f.unite(itr->a, itr->b)) continue;
            ans += itr->len;
            ++cnt;
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
