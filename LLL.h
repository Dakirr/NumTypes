#include <cstring>

class LLL {
    public:
        int len;
        char sign;
        char* folder;
    
    LLL(char x, int l = 2, int sign = 1) {
        len = l;
        sign = x < 0 ? -1 : 1;
        folder = new char[l];
    }

    LLL(LLL& other, int l) {
        len = l;
        folder = new char[l];
        memmove(folder, other.folder, other.len*sizeof(char));
        sign = other.sign;
    }

    LLL& operator= (LLL& other) {
        char* tmp = folder;
        len = other.len;
        sign = other.sign;
        folder = new char[len];
        memmove(folder, other.folder, len*sizeof(char));
        delete[] tmp;
        return *this;
    }

    ~LLL () {
        delete[] folder;
    }

    LLL& operator- ();
    LLL& operator+= (const LLL&);
    LLL& operator-= (const LLL&);
    LLL& operator*= (const LLL&);
    LLL& operator/= (const LLL&);
};

// arithmetics
LLL operator+ (LLL first, LLL& second);
LLL operator- (LLL first, LLL& second);
LLL operator* (LLL first, LLL& second);
LLL operator/ (LLL first, LLL& second);

// comparison
bool operator== (LLL& first, LLL& second);
bool operator!= (LLL& first, LLL& second);
bool operator> (LLL& first,  LLL& second);
bool operator< (LLL& first,  LLL& second);
bool operator>= (LLL& first, LLL& second);
bool operator<= (LLL& first, LLL& second);

