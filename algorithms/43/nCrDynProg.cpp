/**
 * Compute nCr recursively
 * nCr = (n - 1)Cr + (n - 1)C(r - 1)
 * 0 <= r <= n <= 1000
 **/

#include <iostream>

using namespace std;

#define mod 1000000007

int C[1000][1000] = {{ 0 }};

int combination(int n, int r) {
    if (r == 0 or r == n) return 1;
    if (C[n][r]) return C[n][r];
    return C[n][r] = (combination(n - 1, r - 1)%mod + combination(n - 1, r)%mod)%mod;
}

int main() {
    long n, r;
    while (cin >> n >> r, n || r) {
    /* This loop reads a pair (n, r) from STDIN until (0, 0) is encountered
     * and prints nCr
     */
	cout << combination(n, r) << '\n';
    }
    return 0;
}
