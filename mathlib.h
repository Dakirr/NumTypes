int gcd(int a, int b) {
    while (true) {
        if (a == 0) {
            return b;
        }
        
        if (b == 0) {
            return a;
        }
        
        a %= b;
        b %= a;
    }
};

int max(int a, int b) {
    return a > b ? a : b;
};

int min(int a, int b) {
    return a < b ? a : b;
}