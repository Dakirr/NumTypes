#include <cassert>
#include "frac.cpp"

void comparison_test_LLL () {
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

void arithmetic_test_LLL () {
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

void comparison_test () {
    Frac x = Frac(LLL(1, 1, -1), LLL(2, 1)); 
    Frac y = Frac(LLL(2, 1), LLL(2, 1));
    Frac z = Frac(LLL(6, 1), LLL(4, 1));
    assert(x == x);
    assert(y != z);
    assert(y < z);
    assert(x <= y);
    assert(z > y);
    assert(z >= x);
    std::cout << "Frac comparison OK" << std::endl;
}

void arithmetic_test () {
    Frac x = Frac(LLL(1, 1), LLL(2, 1)); 
    Frac y = Frac(LLL(2, 1, -1), LLL(2, 1));
    Frac z = Frac(LLL(3, 1), LLL(2, 1));
    Frac sum = x + x;
    sum = sum + x;
    Frac diff = z - x;
    Frac mult = y * y;
    Frac div = z/z;
    assert(sum == z);
    assert(diff == div);
    assert(mult == div);
    std::cout << "Frac artihmetic OK" << std::endl;
}

void input_test () {
    Frac x = Frac(LLL(2345, 4), LLL(100, 3));
    Frac x0 = Frac("23.45");
    assert(x == x0);
    Frac y = Frac(LLL(2345, 4, -1), LLL(100, 3));
    Frac y0 = Frac("-23.45");
    assert(y == y0);
    Frac x1 = "23.450"_f;
    assert(x == x1);
    std::cout << "Frac input OK" << std::endl;
}

int main() {
    comparison_test_LLL();
    arithmetic_test_LLL();
    comparison_test();
    arithmetic_test();
    input_test();
}
