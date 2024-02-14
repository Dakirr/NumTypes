#include "LLL.h"
#include "mathlib.h"

// arithmetics

LLL operator- (LLL f) {
    return LLL(f, f.len, -1*f.sign);
}

LLL operator+ (LLL first, LLL second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        LLL ret = LLL(0, l_max + 1);
        ret.sign = first.sign;
        LLL f = LLL(first, l_max, first.sign);
        LLL s = LLL(second, l_max, second.sign);

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

LLL operator- (LLL first, LLL second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);

        if (first.len != second.len) {
            LLL f = LLL(first, l_max, first.sign);
            LLL s = LLL(second, l_max, second.sign);
            if (f > s) {
                LLL ret = LLL(0, l_max);
                ret.sign = f.sign;
                for (int i = 0; i < l_max; i++) {
                    int x = f.folder[i] + ret.folder[i] - s.folder[i];
                    if (x >= 0) {
                        ret.folder[i] = x;
                    } else {
                        ret.folder[i] = x + 10;
                        ret.folder[i+1] = -1;
                    }
                }
                return ret;
            } else {
                if (f < s) {
                    return -(s - f);
                } else {
                    return LLL(0, l_max);
                }
            }
        } else {
           if (first > second) {
                LLL ret = LLL(0, l_max);
                ret.sign = first.sign;
                for (int i = 0; i < l_max; i++) {
                    int x = first.folder[i] + ret.folder[i] - second.folder[i];
                    if (x >= 0) {
                        ret.folder[i] = x;
                    } else {
                        ret.folder[i] = x + 10;
                        ret.folder[i+1] = -1;
                    }
                }
                return ret;
            } else {
                if (first < second) {
                    return -(second - first);
                } else {
                    return LLL(0, l_max);
                }
            } 
        }
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
            LLL f = LLL(first, l_max, first.sign);
            LLL s = LLL(second, l_max, second.sign);
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
            LLL f = LLL(first, l_max, first.sign);
            LLL s = LLL(second, l_max, second.sign);
            for (int i = l_max - 1; i > -1; i--) {
                if (f.folder[i] > s.folder[i]) {
                    return true;
                }
            }
        } else {
            for (int i = l_max - 1; i > -1; i--) {
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