#include "mathlib.h"

// arithmetics

LLL& operator- (LLL& f) {
    static LLL x = LLL(f, f.len, f.sign);
    x.sign = -f.sign;
    return x;
}

LLL operator+ (LLL& first, LLL& second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        first.folder.resize(l_max);
        second.folder.resize(l_max);
        LLL ret = LLL(0, l_max);
        for (int i = 0; i < l_max; i++) {
            int x = first.folder[i] + second.folder[i] + ret.folder[i];
            ret.folder[i] = x % 10;
            if (x/10 != 0) {
                if (ret.folder.size() == i+1) {
                    ret.folder.resize(i+2);
                    ret.len += 1;
                }
                ret.folder[i+1] = x / 10;
            }
                
        }
        return ret;
    } else {
        return (first - (-second));
    }
}

LLL operator- (LLL& first, LLL& second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        first.folder.resize(l_max);
        second.folder.resize(l_max);

        if (first > second) {
            LLL ret = LLL(0, l_max, first.sign);
            for (int i = 0; i < l_max; i++) {
                int x = first.folder[i] + ret.folder[i] - second.folder[i];
                if (x >= 0) {
                    ret.folder[i] = x;
                } else {
                    ret.folder[i] = x + 10;
                    if (ret.folder.size() == i) {
                        ret.folder.resize(i+1);
                        ret.len += 1;
                    }
                    ret.folder[i+1] = -1;
                }
            }
            return ret;
        } else {
            if (first < second) {
                LLL x = second - first;
                return -x;
            } else {
                LLL x = LLL(0, l_max);
                return x;
            }
        } 
    } else {
        return (first + (-second));
    }
}


LLL operator* (const LLL& first, int second) {
    LLL ret;
    ret = LLL(0, first.len);
    for (int i = 0; i < first.len; i++) {
            int x = first.folder[i]*second + ret.folder[i];
            ret.folder[i] = x % 10;
            if ((x/10 != 0)) {
                if (ret.len == i+1) {
                    ret.folder.resize(i+2);
                    ret.len += 1;
                }
                ret.folder[i+1] = x / 10;
            }
    }
    return ret;
}

LLL operator>> (const LLL& first, int second) {
    LLL ret = LLL(0, first.len + second);
    for (int i = 0; i < first.len; i++) {
        ret.folder[i + second] = first.folder[i];
    }
    return ret;
}

LLL operator* (LLL& first, LLL& second) {
    LLL ret = LLL(0, 1);
    for (int i = 0; i < second.len; i++) {
        if (second.folder[i] != 0) {
            LLL x = (first * second.folder[i]);
            x = x >> i;
            ret = ret + x;
        }
        //std::cout << first << "*" << int(second.folder[i]) << std::endl;
    }
    ret.sign = first.sign * second.sign;
    return ret;
}

LLL operator/ (LLL& first, LLL& second) {
    LLL mod = LLL(first, first.len, 1);
    LLL divider = LLL(second, second.len, 1);
    LLL div = LLL(0, 1);
    LLL one = LLL(1, 1);
    for (int k = first.len - second.len; k > -1; k--) {
        LLL x = LLL(divider) >> k;
        if (x <= mod) {
            LLL y = one >> k;
            while (mod >= x) {
                mod = mod - x;
                div = y + div;
            }
        }
    }
    div.sign = first.sign * second.sign;
    return div;
}

// assignment operators
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
bool operator== (const LLL& first, const LLL& second) {
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

bool operator!= (const LLL& first, const LLL& second) {
    return !(first == second);
}

bool operator> (LLL& first, LLL& second) {
    if (first.sign == second.sign) {
        int l_max = max(first.len, second.len);
        first.folder.resize(l_max);
        second.folder.resize(l_max);
        for (int i = l_max - 1; i > -1; i--) {
            if (first.folder[i] > second.folder[i]) {
                return true;
            }
            if (first.folder[i] < second.folder[i]) {
                    return false;
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