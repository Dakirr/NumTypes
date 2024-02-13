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