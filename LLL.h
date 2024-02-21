#include <cstring>
#include <iostream>
#include <vector>

class LLL {
    public:
        int len;
        char sign; 	
        std::vector<char> folder;
    
        LLL(long long x, int l, int s = 0) {
            len = l;
            if (s == 0) {
                if (x >= 0) {
                    sign = 1;
                } else {
                    sign = -1;
                }
            } else {
                sign = s;
            }
            folder.resize(len);
            int i = 0;
            while (x != 0) {
                folder[i] = x % 10;
                x /= 10;
                i += 1;
            }
        }

        LLL() = default;

        ~LLL()= default;

        LLL(const LLL& other, int l, int s) {
            len = l;
            folder = other.folder;
            folder.resize(len);
            sign = s;
        }

        LLL(const LLL& other) {
            len = other.len;
            folder = other.folder;
            sign = other.sign;
        }

        LLL& operator= (LLL& other) {
            len = other.len;
            sign = other.sign;
            folder = other.folder;
            return *this;
        }
        
        LLL& operator= (LLL other) {
            len = other.len;
            sign = other.sign;
            folder = other.folder;
            return *this;
        }

        LLL& operator+= (const LLL&);
        LLL& operator-= (const LLL&);
        LLL& operator*= (const LLL&);
        LLL& operator/= (const LLL&);
};

// arithmetics
LLL operator+ (LLL& first, LLL& second);
LLL operator- (LLL& first, LLL& second);
LLL operator* (LLL& first, LLL& second);
LLL operator/ (LLL& first, LLL& second);

// comparison
bool operator== (const LLL& first, const LLL& second);
bool operator!= (const LLL& first, const LLL& second);
bool operator>  (LLL& first, LLL& second);
bool operator<  (LLL& first, LLL& second);
bool operator>= (LLL& first, LLL& second);
bool operator<= (LLL& first, LLL& second);

//
std::ostream& operator<<(std::ostream& os, LLL f) {
    if (f.sign == 1) {
        //os << "+";
    } else {
        os << "-";
    }
    //os << "{" << f.folder.size() << "-" << f.len << "}";
    for (int i = f.folder.size() - 1; i > -1; i--) {
        os << int(f.folder[i]);
    }
    return os;
}

LLL& operator- (LLL&);
LLL operator* (const LLL& first, int second);
LLL operator>> (const LLL& first, int second);

