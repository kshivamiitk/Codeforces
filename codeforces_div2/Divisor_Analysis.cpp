#include <iostream>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define int long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

// fast modular exponentiation: computes (base^exponent) mod m
int power(int base, int exp, int m) {
    int res = 1;
    base %= m;
    while(exp > 0) {
        if(exp & 1) 
            res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}

// modular inverse using Fermat's little theorem (mod is prime)
int modInverse(int a, int m) {
    return power(a, m - 2, m);
}

void solve(){
    int t; 
    cin >> t;
    
    // For product computation, we need modulus L = 2*(mod-1)
    int L = 2 * (mod - 1);
    
    // d_mod will be the total number of divisors modulo L
    int d_mod = 1;
    // numDiv will be the total number of divisors modulo mod (for output)
    int numDiv = 1;
    
    // n_mod = n mod mod, where n = product( x^y )
    int n_mod = 1;
    // sqrtN = product( x^(y/2) ) mod mod; it will be used when n is a perfect square.
    int sqrtN = 1;
    // sum = product of sum of divisors for each prime factor, i.e.,
    // sum = ∏((x^(y+1)-1)/(x-1)) mod mod.
    int sum = 1;
    
    // Track if n is a perfect square (all exponents are even)
    bool perfectSquare = true;
    
    while(t--){
        int x, y;
        cin >> x >> y;
        
        // update n_mod: n_mod = n_mod * (x^y) mod mod.
        n_mod = (n_mod * power(x, y, mod)) % mod;
        
        // update d_mod and numDiv (number of divisors)
        d_mod = (d_mod * ((y + 1) % L)) % L;
        numDiv = (numDiv * (y + 1)) % mod;
        
        // For sum of divisors: term = (x^(y+1) - 1) / (x - 1) mod mod.
        int numerator = (power(x, y + 1, mod) - 1 + mod) % mod;
        int denominator = (x - 1) % mod;
        int inv_den = modInverse(denominator, mod);
        int term = (numerator * inv_den) % mod;
        sum = (sum * term) % mod;
        
        // update sqrtN using integer division of the exponent
        sqrtN = (sqrtN * power(x, y / 2, mod)) % mod;
        
        // If any exponent y is odd, n is not a perfect square.
        if(y & 1) 
            perfectSquare = false;
    }
    
    int prod;
    if(perfectSquare) {
        // When n is a perfect square, d (number of divisors) is odd.
        // Then product = n^((d-1)/2) * sqrt(n) mod mod.
        // Since d_mod stores d mod L, we compute ((d_mod - 1 + L) % L) / 2.
        int exp = ((d_mod - 1 + L) % L) / 2;
        prod = (power(n_mod, exp, mod) * sqrtN) % mod;
    } else {
        // Otherwise, d is even and product = n^(d/2) mod mod.
        prod = power(n_mod, d_mod / 2, mod);
    }
    
    cout << numDiv << " " << sum << " " << prod << endl;
}

signed main(){
    fast;
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}
