#include "LLL.cpp"
#define FRAC_INT_TYPE LLL
class Frac {
    public:
        FRAC_INT_TYPE num, denum;
        bool is_normal;
    public:
        Frac(LLL x = LLL(0, 1), LLL y = LLL(1, 1), bool normalized = 0) {
            num = LLL(x);
            denum = LLL(y);
            is_normal = normalized;
        }

        Frac(std::string s) {
            int len = s.length();

            if (s[0] == '-') {
                num.sign = -1;
                s.replace(0, 1, "");
            } else {
                num.sign = 1;
            }
            num.folder = std::vector<char>(len);    
            num.len = len;
            int k = 0;
            for (int i = len - 1; i > -1; i--) {
                if (isdigit(s[i])) {
                    num.folder[k] = s[i] - '0';
                    k += 1;
                } else {
                    if (s[i] == '.') {
                        denum = LLL(1, 1) >> k;
                    }
                };
            }
            is_normal = 1;
        }

        Frac (Frac& other) {
            num = LLL(other.num);
            denum = LLL(other.denum);
            is_normal = other.is_normal;;
        }


        // fraction specifics
        Frac& operator+ ();
        
        Frac& operator= (Frac other) {
            num = LLL(other.num);
            denum = LLL(other.denum);
            is_normal = other.is_normal;;
            return *this;
        }

        Frac operator= (Frac& other) {
            num = LLL(other.num);
            denum = LLL(other.denum);
            is_normal = other.is_normal;;
            return *this;
        }

        ~Frac() = default;
        Frac() = default;
};

// arithmetics
Frac operator+ (Frac& first, Frac& second);
Frac operator- (Frac& first, Frac& second);
Frac operator* (Frac& first, Frac& second);
Frac operator/ (Frac& first, Frac& second);

// Int arithmetics

Frac operator+ (Frac& first, FRAC_INT_TYPE& second);
Frac operator- (Frac& first, FRAC_INT_TYPE& second);
Frac operator* (Frac& first, FRAC_INT_TYPE& second);
Frac operator/ (Frac& first, FRAC_INT_TYPE& second);

// comparison
bool operator== (Frac& first, Frac& second);
bool operator!= (Frac& first, Frac& second);
bool operator>  (Frac& first, Frac& second);
bool operator<  (Frac& first, Frac& second);
bool operator>= (Frac& first, Frac& second);
bool operator<= (Frac& first, Frac& second);

Frac operator^  (Frac& N, int acc);

std::ostream& operator<<(std::ostream& os, Frac f) {
    if (f.num.sign * f.denum.sign == 1) {
        //os << "+";
    } else {
        os << "-";
    }

    if (f.is_normal) { 
        if (f.num < f.denum && -(f.num) < f.denum) {
            os << "0.";
        }
        if (f.num.folder[f.num.len - 1] != 0) {
            for (int i = f.num.len - 1; i > -1; i--) {
                os << int(f.num.folder[i]);
                if (i == f.denum.len - 1) {
                    os << '.';
                }
            }
        } else {
            for (int i = f.num.len - 2; i > -1; i--) {
                os << int(f.num.folder[i]);
                if (i == f.denum.len - 1) {
                    os << '.';
                }
            }
        }
        
    } else {
        Frac x = f^(f.denum.len + 1);
        if (x.num < x.denum && -(x.num) < x.denum) {
                os << "0.";
        }
        for (int i = x.num.len - 1; i > -1; i--) {
            os << int(x.num.folder[i]);
            if (i == x.denum.len - 1) {
                os << '.';
            }
        }
    }
    return os;
}

std::ostream& pi_n(Frac f, int acc, std::ostream& os = std::cout) {
    if (f.num.sign * f.denum.sign == 1) {
        //os << "+";
    } else {
        os << "-";
    }

    Frac x = f^(f.denum.len + 1);
    if (x.num < x.denum && -(x.num) < x.denum) {
        os << "0.";
    }
    for (int i = x.num.len - 1; i > x.num.len - acc - 2; i--) {
        os << int(x.num.folder[i]);
        if (i == x.denum.len - 1) {
            os << '.';
        }
    }
    return os;
}

