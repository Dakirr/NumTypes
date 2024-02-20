#include "frac.cpp"
#include <chrono>

int a(int n) {
    if (n == 1) {
        return 4;
    } else {
        return (n - 1) * (n - 1);
    }
}

int b(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 2*n - 1;
    }
}

Frac pi(int acc) {
    int acc1 = acc * 3 / 2;
    std::vector<LLL> A;
    A.resize(acc1 + 2);
    A[0] = LLL(1, 1);
    A[1] = LLL(0, 1);

    std::vector<LLL> B;
    B.resize(acc1 + 2);
    B[0] = LLL(0, 1);
    B[1] = LLL(1, 1);
    
    for (int i = 2; i < acc1 + 2; i++) {
        LLL x(b(i-1), i);
        x = x * A[i-1];
        LLL y(a(i-1), 2*(i-1));
        y = y * A[i-2];
        A[i] = x + y;

        x = LLL(b(i-1), i);
        x = x * B[i-1];
        y = LLL(a(i-1), 2*(i-1));
        y = y * B[i-2];
        B[i] = x + y;
    }
    return Frac(A[acc1+1], B[acc1+1]);
}

int main() {
    std::cout << "Insert accuracy (integer between 10 and 200)" << std::endl;
    int acc;
    std::cin >> acc;

    auto start = std::chrono::high_resolution_clock::now();
    Frac Pi = pi(acc);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = finish - start;
    
    std::cout << "Pi number: ";
    pi_n(Pi, acc) << std::endl;
    std::cout << "Time required: " << time.count() << std::endl;
}