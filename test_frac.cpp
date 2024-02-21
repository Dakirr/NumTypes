#include <cassert>
#include "frac.cpp"

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
    Frac sum = z + y;
    Frac diff = x - z;
    Frac mult = y * y;
    Frac div = z/z;
    assert(sum == x);
    assert(diff == y);
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
    std::cout << "Frac input OK" << std::endl;
}

int main() {
    comparison_test();
    arithmetic_test();
    input_test();
}
