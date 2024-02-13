#include "frac.h"
#include "mathlib.cpp"

// arithmetics
Frac& Frac::operator+= (const Frac& other) {
    num = other.num * denum + other.denum * num;
    denum *= other.denum;
    return *this;
}
Frac& Frac::operator-= (const Frac& other) {
    num = -other.num * denum + other.denum * num;
    denum *= other.denum;
    return *this;
}
Frac& Frac::operator*= (const Frac& other) {
    num *= other.num;
    denum *= other.denum;
    return *this;
}
Frac& Frac::operator/= (const Frac& other) {
    num *= other.denum;
    denum *= other.num;
    return *this;
}

Frac operator+ (Frac first, const Frac& second) {
    return first += second;
}
Frac operator- (Frac first, const Frac& second) {
    return first -= second;
}
Frac operator* (Frac first, const Frac& second) {
    return first *= second;
}
Frac operator/ (Frac first, const Frac& second) {
    return first /= second;
}

// int Arithmetics

Frac& Frac::operator+= (const FRAC_INT_TYPE& other) {
    num = other * denum;
    return *this;
}
Frac& Frac::operator-= (const FRAC_INT_TYPE& other) {
    num = -other * denum;
    return *this;
}
Frac& Frac::operator*= (const FRAC_INT_TYPE& other) {
    num *= other;
    return *this;
}
Frac& Frac::operator/= (const FRAC_INT_TYPE& other) {
    denum *= other;
    return *this;
}

Frac operator+ (Frac first, const FRAC_INT_TYPE& second) {
    return first += second;
}
Frac operator- (Frac first, const FRAC_INT_TYPE& second) {
    return first -= second;
}
Frac operator* (Frac first, const FRAC_INT_TYPE& second) {
    return first *= second;
}
Frac operator/ (Frac first, const FRAC_INT_TYPE& second) {
    return first /= second;
}

Frac& Frac::operator+ () {
    int x = gcd(num, denum);
    num /= x;
    denum /= x;
    return *this;
}
