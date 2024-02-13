#include <cstring>

class LLL {
    public:
        int len;
        char sign;
        char* folder;
    
    LLL(long long x, int l = 2) {
        len = l;
        sign = x < 0 ? -1 : 1;
        folder = new char[l];
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
bool operator== (const LLL& first, const LLL& second);
bool operator!= (const LLL& first, const LLL& second);
