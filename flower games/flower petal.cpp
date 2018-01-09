#include <cmath>

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

bool ispow2(ll k) {
    return !(k & (k - 1));
}

ll nextpow2(ll k) {
    int count = 1;
    while(k >>= 1)
        count++;
    return 1 << count;
}

ll nextpow2(ll x)
{
x--;
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	x++;
	
	return x;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        ll N;
        cin >> N;
        if(ispow2(N))
            cout << "1\n";
        else {
            ll np = nextpow2(N);
            //cout << ;
            cout << N - (np-N-1) << '\n';
        }
    }
    return 0;
}
