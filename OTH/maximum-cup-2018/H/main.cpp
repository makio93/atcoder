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


void func(long long N, long long M, std::vector<long long> v, std::vector<long long> u, std::vector<long long> w, long long K, std::vector<long long> a, long long Q, std::vector<long long> b){

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> v(M);
    std::vector<long long> u(M);
    std::vector<long long> w(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&v[i]);
        scanf("%lld",&u[i]);
        scanf("%lld",&w[i]);
    }
    long long K;
    scanf("%lld",&K);
    std::vector<long long> a(K);
    for(int i = 0 ; i < K ; i++){
        scanf("%lld",&a[i]);
    }
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> b(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&b[i]);
    }
    func(N, M, std::move(v), std::move(u), std::move(w), K, std::move(a), Q, std::move(b));
    return 0;
}
