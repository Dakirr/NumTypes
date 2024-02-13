#include <cstring>

class ULLL {
    public:
        int len;
        char* folder;
    
    ULLL(long long x, int l = 2) {
        len = l;
        folder = new char[l];
    }

    ULLL& operator= (ULLL& other) {
        char* tmp = folder;
        len = other.len;
        folder = new char[len];
        memmove(folder, other.folder, len*sizeof(char));
        delete[] tmp;
        return *this;
    }

    ~ULLL () {
        delete[] folder;
    }

    ULLL& operator+= (const ULLL&);
    ULLL& operator-= (const ULLL&);
    ULLL& operator*= (const ULLL&);
    ULLL& operator/= (const ULLL&);
};

// arithmetics
ULLL operator+ (ULLL first, const ULLL& second);
ULLL operator- (ULLL first, const ULLL& second);
ULLL operator* (ULLL first, const ULLL& second);
ULLL operator/ (ULLL first, const ULLL& second);

// comparison
bool operator== (const ULLL& first, const ULLL& second);
bool operator!= (const ULLL& first, const ULLL& second);
