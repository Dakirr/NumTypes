#include <cassert>
#include "LLL.cpp"

void comparison_test () {
    LLL x = LLL(10, 2, 1);
    LLL y = LLL(0, 3, 1);
    LLL z = LLL(10, 2, -1);
    assert(x == x);
    assert(y != z);
    assert(z < y);
    assert(y <= x);
    assert(x > z);
    assert(y >= z);
    std::cout << "LLL comparison OK" << std::endl;
}

void arithmetic_test () {
    LLL x = LLL(10, 2, 1);
    LLL y = LLL(0, 3, 1);
    LLL z = LLL(10, 2, -1);
    LLL x2 = LLL(100, 3, 1);
    assert(x + z == y);
    assert(y - z == x);
    assert(x * y == y);
    assert(y / z == y * z);
    assert(x2 == x*x);
    assert(x2 == z*z);
    assert(-x == z);
    std::cout << "LLL artihmetic OK" << std::endl;
}

int main() {
    comparison_test();
    arithmetic_test();
}
