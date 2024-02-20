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
        Frac (Frac& other) = default;
        // fraction specifics
        Frac& operator+ ();
        Frac& operator= (Frac other) {
            num = LLL(other.num);
            denum = LLL(other.denum);
            is_normal = other.is_normal;;
            return *this;
        }
        Frac& operator= (Frac& other) {
            num = LLL(other.num);
            denum = LLL(other.denum);
            is_normal = other.is_normal;;
            return *this;
        }
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
        if (f.num < f.denum) {
            os << "0.";
        }
        for (int i = f.num.len - 1; i > -1; i--) {
            os << int(f.num.folder[i]);
            if (i == f.denum.len - 1) {
                os << '.';
            }
        }
    } else {
        Frac x = f^(f.denum.len + 1);
        if (x.num < x.denum) {
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
    if (x.num < x.denum) {
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
