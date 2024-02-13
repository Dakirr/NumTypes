class LLL {
    public:
        int len;
        long long* folder;
    
    LLL(long long x, int l = 2) {
        len = l;
        folder = (long long*) calloc(l, sizeof(long long));
    }
};
