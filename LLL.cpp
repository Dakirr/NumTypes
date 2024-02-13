#include "LLL.h"

#if !defined "mathlib.h"
#include "mathlib.h"
#endif

// arithmetics

LLL& LLL::operator-() {
    LLL a = *this;
    a.sign *= -1;
    return *this;
}

LLL operator+ (LLL first, LLL& second) {
    if (first.sign == second.sign) {
        
        int l_min = min(first.len, second.len);
        LLL ret = LLL(0, max(first.len, second.len) + 1);
        ret.sign = first.sign;

        for (int i = 0; i < l_min; i++) {
            int x = first.folder[i] + second.folder[i] + ret.folder[i];
            ret.folder[i] = x % 10;
            ret.folder[i+1] = x / 10;
        }

        for (int i = l_min; i < first.len; i++) {
            int x = first.folder[i] + ret.folder[i];
            ret.folder[i] = x % 10;
            ret.folder[i+1] = x / 10;
        }

        for (int i = l_min; i < second.len; i++) {
            int x = first.folder[i] + ret.folder[i];
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
        int l_min = min(first.len, second.len);
        LLL ret = LLL(0, max(first.len, second.len) + 1);
        return ret;
    } else {
        return (first + (-second));
    }
}

LLL operator* (LLL first, const LLL& second) {
    return first *= second;
}

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