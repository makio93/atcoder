#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> mars, sum;
vector<vector<double>> dp;
double calc(int i1, int d1) {
    if (dp[i1][d1] != -1.0) return dp[i1][d1];
    if (i1 == n) {
        if (d1 > 0) return (dp[i1][d1] = 0.0);
        else return (dp[i1][d1] = 1.0);
    }
    if (d1 <= 0) return (dp[i1][d1] = 1.0);
    //long long num = 1, den = 1;
    double res = 0.0, rate = 1.0;
    for (int i=0; i<=min(4, d1); ++i) {
        if (i==0) {
            res += (double)(sum[i1]-mars[i1]) / (double)sum[i1] * calc(i1+1, d1);
        }
        else {
            rate *= (double)(mars[i1] - i + 1) / (double)(sum[i1] - (9-d1));
            res += rate * calc(i1+1, d1-i);
        }
    }
    return (dp[i1][d1] = res);
}

class MarbleDrawGame {
public:
    double winningChance(vector<int> marbles) {
        n = marbles.size();
        mars = marbles;
        sum = vector<int>(n+1);
        for (int i=n-1; i>=0; --i) sum[i] = sum[i+1] + marbles[i];
        dp = vector<vector<double>>(n+1, vector<double>(10, -1.0));
        return (calc(0, 9));
    }
};

int main(){
    MarbleDrawGame cl;
    int n;
    cin >> n;
    vector<int> marbles(n);
    for (int i=0; i<n; ++i) cin >> marbles[i];
    cout << cl.winningChance(marbles) << endl;
    return 0;
}
