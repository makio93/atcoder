#include <bits/stdc++.h>
using namespace std;

// 本番後、自主研究、よくわからない

class DisjointDiceValues {
    double pm(int a, int b) {
        if (a < b) return 0.0;
        double res = 1.0;
        for (int i=a; i>a-b; --i) res *= (double)i;
        return res;
    }
    double cb(int a, int b) {
        if (b > a) return 0.0;
        if (a-b < b) return cb(a, a-b);
        double res = 1.0;
        for (int i=a; i>a-b; --i) res *= (double)i;
        for (int i=1; i<=b; ++i) res /= (double)i;
        return res;
    }
public:
    double getProbability(int A, int B) {
        double res = 0.0;
        vector<double> adp(min(A,6)+1);
        for (int i=1; i<=min(A,6); ++i) {
            double aval = 1.0;
            for (int j=0; j<A; ++j) aval *= (double)i / 6.0;
            aval *= cb(6, i);
            adp[i] = aval - adp[i-1];
        }
        for (int i=1; i<=min(A,6); ++i) {
            double bval = 1.0;
            bval = ((double)pow(6.0, (double)B) - (double)pow((double)(6-i), (double)B)) / pow(6.0, (double)B);
            res += adp[i] * bval;
        }
        return res;
    }
};

int main(){
    DisjointDiceValues cl;
    int A, B;
    cin >> A >> B;
    cout << fixed << setprecision(10) << cl.getProbability(A, B) << endl;
    return 0;
}
