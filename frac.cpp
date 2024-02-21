#include "frac.h"

Frac operator+ (Frac& first, Frac& second) {
    LLL x = first.num * second.denum;
    LLL y = first.denum * second.num;
    return Frac(x + y, first.denum*second.denum, first.is_normal && second.is_normal);
}

Frac operator- (Frac& first, Frac& second) {
    LLL x = first.num * second.denum;
    LLL y = first.denum * second.num;
    return Frac(x - y, first.denum*second.denum, first.is_normal && second.is_normal);
}

Frac operator* (Frac& first, Frac& second) {
    LLL x = first.num * second.num;
    LLL y = first.denum * second.denum;
    return Frac(x, y, first.is_normal && second.is_normal);
}

Frac operator/ (Frac& first, Frac& second) {
    LLL x = first.num * second.denum;
    LLL y = first.denum * second.num;
    return Frac(x, y);
}

Frac& Frac::operator+ () {
    LLL x = gcd(num, denum);
    num /= x;
    denum /= x;
    return *this;
}

Frac operator^(Frac& N, int acc) {
    LLL x = N.num >> acc;
    LLL y = x / N.denum;
    return Frac(y, LLL(1, 1) >> acc, 1);
};

bool operator>  (Frac& first, Frac& second) {
    LLL f = first.num * second.denum;
    f.sign = first.num.sign * first.denum.sign;
    LLL s = first.denum * second.num;
    s.sign = second.num.sign * second.denum.sign;
    return f > s;
};

bool operator<  (Frac& first, Frac& second) {
    return second > first;
};

bool operator== (Frac& first, Frac& second) {
    LLL f = first.num * second.denum;
    f.sign = first.num.sign * first.denum.sign;
    LLL s = first.denum * second.num;
    s.sign = second.num.sign * second.denum.sign;
    return f == s;
};

bool operator!= (Frac& first, Frac& second) {
    return !(first == second);
};

bool operator>= (Frac& first, Frac& second) {
    return !(first < second);
};

bool operator<= (Frac& first, Frac& second) {
    return !(first > second);
};