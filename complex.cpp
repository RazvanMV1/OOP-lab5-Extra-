#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    Complex rez(real, imag);
    return rez;
}

Complex operator-(const Complex& l, const Complex& r)
{
    double real1 = l.real();
    double real2 = r.real();
    double imag1 = l.imag();
    double imag2 = r.imag();
    Complex rez(real1 - real2, imag1 - imag2);
    return rez;
}

Complex operator-(const Complex& l, double r)
{
    double real1 = l.real();
    double imag1 = l.imag();
    Complex rez(real1 - r, imag1);
    return rez;
}

Complex operator-(double l, const Complex& r)
{
    double real1 = r.real();
    double imag1 = r.imag();
    Complex rez(l+real1, imag1);
    return rez;
}

Complex operator*(const Complex& l, const Complex& r)
{
    double realPart = (l.real() * r.real()) - (l.imag() * r.imag());
    double imagPart = (l.real() * r.imag()) + (l.imag() * r.real());
    return Complex(realPart, imagPart);
}

Complex operator*(const Complex& l, double r)
{
    double real1 = l.real();
    double imag1 = l.imag();
    Complex rez(r * real1, imag1);
    return rez;
}

Complex operator*(double l, const Complex& r)
{
    double real1 = r.real();
    double imag1 = r.imag();
    Complex rez(l * real1, imag1);
    return rez;
}

Complex operator+(const Complex& l, const Complex& r)
{
    double real1 = l.real();
    double real2 = r.real();
    double imag1 = l.imag();
    double imag2 = r.imag();
    Complex rez(real1 + real2, imag1 + imag2);
    return rez;
}

Complex operator+(const Complex& l, double r)
{
    double real1 = l.real();
    double imag1 = l.imag();
    Complex rez(real1 + r, imag1);
    return rez;
}

Complex operator+(double l, const Complex& r)
{
    double real1 = r.real();
    double imag1 = r.imag();
    Complex rez(real1 + l, imag1);
    return rez;
}

Complex operator-(const Complex& obj)
{
    double real1 = obj.real();
    double imag1 = obj.imag();
    real1 *= (-1);
    imag1 *= (-1);
    Complex rez(real1, imag1);
    return rez;
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() != r.real()) return false;
    if (l.imag() != r.imag()) return false;
    return true;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    out << "Real: " << complex.real() << ", imaginar: " << complex.imag();
    return out;
}

bool operator!=(const Complex& l, const Complex& r)
{
    if (l.real() != r.real()) return true;
    if (l.imag() != r.imag()) return true;
    return false;
}

Complex& Complex::operator++() {
    ++this->real_data;
    return *this;
}

// Post-incrementare: obj++
Complex Complex::operator++(int) {
    Complex temp = *this;
    this->real_data++;
    return temp;
}

// Pre-decrementare: --obj
Complex& Complex::operator--() {
    --this->real_data;
    return *this;
}

// Post-decrementare: obj--
Complex Complex::operator--(int) {
    Complex temp = *this;
    this->real_data--;
    return temp;
}
