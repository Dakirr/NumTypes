#include "LLL.h"
#include "mathlib.h"

// arithmetics

LLL& LLL::operator-() {
    sign *= -1;
    return *this;
}

LLL operator+ (LLL first, LLL& second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        LLL ret = LLL(0, l_max + 1);
        ret.sign = first.sign;
        LLL f = LLL(first, l_max);
        LLL s = LLL(second, l_max);

        for (int i = 0; i < l_max; i++) {
            int x = f.folder[i] + s.folder[i] + ret.folder[i];
            ret.folder[i] = x % 10;
            ret.folder[i+1] = x / 10;
        }
        return ret;

    } else {
        return (first - (-second));
    }
}

LLL operator- (LLL first, LLL& second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        LLL ret = LLL(0, l_max);
        ret.sign = first.sign;
        for (int i = l_max; i > -1; i--) {
             
        }
        return ret;
    } else {
        return (first + (-second));
    }
}

LLL operator* (LLL first, const LLL& second) {
    return first *= second;
}

// assignment operators

LLL operator/ (LLL first, const LLL& second) {
    return first /= second;
}

LLL& LLL::operator+= (const LLL& other) {
    
    return *this;
}
LLL& LLL::operator-= (const LLL& other) {
    
    return *this;
}
LLL& LLL::operator*= (const LLL& other) {
    
    return *this;
}
LLL& LLL::operator/= (const LLL& other) {
    
    return *this;
}

// comparison
bool operator== (LLL& first, LLL& second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        if (first.len != second.len) {
            LLL f = LLL(first, l_max);
            LLL s = LLL(second, l_max);
            for (int i = 0; i < l_max; i++) {
                if (f.folder[i] != s.folder[i]) {
                    return false;
                }
            }
        } else {
            for (int i = 0; i < l_max; i++) {
                if (first.folder[i] != second.folder[i]) {
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

bool operator!= (LLL& first, LLL& second) {
    return !(first == second);
}

bool operator> (LLL& first, LLL& second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        if (first.len != second.len) {
            LLL f = LLL(first, l_max);
            LLL s = LLL(second, l_max);
            for (int i = l_max; i > -1; i--) {
                if (f.folder[i] > s.folder[i]) {
                    return true;
                }
            }
        } else {
            for (int i = l_max; i > -1; i--) {
                if (first.folder[i] > second.folder[i]) {
                    return true;
                }
            }
        }
        return false;
    } else {
        if (first.sign > second.sign) {
            return true;
        } else {
            return false;
        }
    }
}

bool operator< (LLL& first, LLL& second) {
    return second > first;
}

bool operator>= (LLL& first, LLL& second) {
    return !(first < second);
}

bool operator<= (LLL& first, LLL& second) {
    return !(first > second);
}