#define FRAC_INT_TYPE int
class Frac {
    public:
        FRAC_INT_TYPE num, denum;

    public:
        Frac(double x = 0, double y = 1) {
            num = x;
            denum = y;
        }
    public:
        // arithmetics
        Frac& operator+= (const Frac&);
        Frac& operator-= (const Frac&);
        Frac& operator*= (const Frac&);
        Frac& operator/= (const Frac&);

        // fraction specifics
        Frac& operator+ ();
        Frac& operator+= (const FRAC_INT_TYPE&);
        Frac& operator-= (const FRAC_INT_TYPE&);
        Frac& operator*= (const FRAC_INT_TYPE&);
        Frac& operator/= (const FRAC_INT_TYPE&);

};

// arithmetics
Frac operator+ (Frac first, const Frac& second);
Frac operator- (Frac first, const Frac& second);
Frac operator* (Frac first, const Frac& second);
Frac operator/ (Frac first, const Frac& second);

// Int arithmetics

Frac operator+ (Frac first, const FRAC_INT_TYPE& second);
Frac operator- (Frac first, const FRAC_INT_TYPE& second);
Frac operator* (Frac first, const FRAC_INT_TYPE& second);
Frac operator/ (Frac first, const FRAC_INT_TYPE& second);

// comparison
bool operator== (const Frac& first, const Frac& second);
bool operator!= (const Frac& first, const Frac& second);