#include "LLL.h"

LLL gcd(LLL x, LLL y) {
    if (x.sign != y.sign) {
        LLL a = LLL(x, x.len, 1);
        LLL b = LLL(y, y.len, 1);
        if (a == b) {
        return b;
        }
        if (a > b) {
            return gcd(a - b, b);
        } else {
            return gcd(b - a, a);
        }
    }
    
    if (x == y) {
        return x;
    }
    if (x > y) {
        return gcd(x - y, y);
    } else {
        return gcd(y - x, x);
    }
};

int max(int a, int b) {
    return a > b ? a : b;
};

int min(int a, int b) {
    return a < b ? a : b;
}

