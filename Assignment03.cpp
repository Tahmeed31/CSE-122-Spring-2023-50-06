// Name: Tahmeed Sadiq //
// ID: 22234103297 //
#include <iostream>
#include <sstream>
#include <cassert>
#include <typeinfo>

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num, int den) {
        assert(typeid(num) == typeid(int));
        assert(typeid(den) == typeid(int));
        assert(den != 0);
        numerator = num;
        denominator = den;
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    std::string str() const {
        std::stringstream ss;
        ss << numerator << "/" << denominator;
        return ss.str();
    }

    std::string repr() const {
        std::stringstream ss;
        ss << "Fraction(" << numerator << ", " << denominator << ")";
        return ss.str();
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 + f2;
    std::cout << f1.str() << " + " << f2.str() << " = " << f3.str() << std::endl;
    std::cout << "f1 = " << f1.repr() << std::endl;
    std::cout << "f2 = " << f2.repr() << std::endl;
    std::cout << "f3 = " << f3.repr() << std::endl;
    return 0;
}

