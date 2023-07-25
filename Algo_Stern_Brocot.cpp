#include <iostream>
#include <string>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;

    Fraction(int num, int den) : numerator(num), denominator(den) {}
};

Fraction mediant(const Fraction &frac1, const Fraction &frac2) {
    return Fraction(frac1.numerator + frac2.numerator, frac1.denominator + frac2.denominator);
}

string findPath(int num, int den) {
    Fraction target(num, den);
    Fraction left(0, 1);
    Fraction right(1, 0);
    string path;

    while (target.numerator != left.numerator || target.denominator != left.denominator) {
        Fraction med = mediant(left, right);
        if (target.numerator * med.denominator < med.numerator * target.denominator) {
            path += 'L';
            right = med;
        } else {
            path += 'R';
            left = med;
        }
    }

    return path;
}

int main() {
    int numerator, denominator;
    cin >> numerator >> denominator;

    string path = findPath(numerator, denominator);
    path.pop_back();
    cout << path << endl;

    return 0;
}
