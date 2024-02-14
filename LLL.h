#include <cstring>
#include <iostream>

class LLL {
    public:
        int len;
        char sign;
        char* folder;
    
    LLL(long long x, int l) {
        len = l;
        if (x >= 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        folder = new char[l];
        int i = 0;
        while (x != 0) {
            folder[i] = x % 10;
            x /= 10;
            i += 1;
        }
    }

    LLL(LLL& other, int l, int s) {
        len = l;
        folder = new char[l];
        memmove(folder, other.folder, other.len*sizeof(char));
        sign = s;
    }

    LLL operator= (LLL other) {
        char* tmp = folder;
        len = other.len;
        sign = other.sign;
        folder = new char[len];
        memmove(folder, other.folder, len*sizeof(char));
        delete[] tmp;
        return *this;
    }


    LLL& operator+= (const LLL&);
    LLL& operator-= (const LLL&);
    LLL& operator*= (const LLL&);
    LLL& operator/= (const LLL&);
};

// arithmetics
LLL operator+ (LLL first, LLL second);
LLL operator- (LLL first, LLL second);
LLL operator* (LLL first, LLL second);
LLL operator/ (LLL first, LLL second);

// comparison
bool operator== (LLL& first, LLL& second);
bool operator!= (LLL& first, LLL& second);
bool operator> (LLL& first,  LLL& second);
bool operator< (LLL& first,  LLL& second);
bool operator>= (LLL& first, LLL& second);
bool operator<= (LLL& first, LLL& second);

//
std::ostream& operator<<(std::ostream& os, LLL f) {
    if (f.sign == 1) {
        os << "+";
    } else {
        os << "-";
    }
    for (int i = f.len - 1; i > -1; i--) {
        os << int(f.folder[i]);
    }
    return os;
}

LLL operator- (LLL);

