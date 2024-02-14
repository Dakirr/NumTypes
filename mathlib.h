#include "LLL.h"

LLL gcd(LLL x, LLL y) {
    LLL a = LLL(x, x.len, 1);
    LLL b = LLL(y, y.len, 1);
    
    while (true) {
        if (a == b) {
            return b;
        }
        if (a > b) {
            return gcd(a - b, b);
        } else {
            return gcd(b - a, a);
        }
    }
};

int max(int a, int b) {
    return a > b ? a : b;
};

int min(int a, int b) {
    return a < b ? a : b;
}