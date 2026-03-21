#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
}

Complex::Complex(const Complex& complex) {
    this->imag_data = complex.imag_data;
    this->real_data = complex.real_data;
}

Complex::Complex(Complex&& complex) {
    this->imag_data = complex.imag_data;
    this->real_data = complex.real_data;
}

bool Complex::is_real() const {
    if (imag_data == 0) {
        return true;
    }
    return false;
}

double Complex::real() const {
    return this->real_data;
}

double Complex::imag() const {
    return this->imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex operator+(const Complex& l, const Complex& r) {
    Complex result(l.real() + r.real(), l.imag() + r.imag());
    return result;
}

Complex operator+(const Complex& l, double r) {
    Complex result(l.real() + r, l.imag());
    return result;
}

Complex operator+(double l, const Complex& r) {
    Complex result(l + r.real(), r.imag());
    return result;
}
Complex operator-(const Complex& l, const Complex& r) {
    Complex result(l.real() - r.real(), l.imag() - r.imag());
    return result;
}

Complex operator-(const Complex& l, double r) {
    Complex result(l.real() - r, l.imag());
    return result;
}

Complex operator-(double l, const Complex& r) {
    return r - l;
}

Complex& Complex::operator=(const Complex& complex) {
    this->imag_data = complex.imag_data;
    this->real_data = complex.real_data;
    return *this;
}

Complex& Complex::operator=(Complex&& complex) {
    this->imag_data = complex.imag_data;
    this->real_data = complex.real_data;
    return *this;
}

//(a + bi)(c + di) = ac - bd + i(ad + bc)
Complex operator*(const Complex& l, const Complex& r) {
    double realPart = l.real() * r.real() - l.imag() * r.imag();
    double imagPart = l.real() * r.imag() + l.imag() * r.real();
    Complex result(realPart, imagPart);
    return result;
}

Complex operator*(const Complex& l, double r) {
    Complex result(l.real() * r, l.imag() * r);
    return result;
}

Complex operator*(double l, const Complex& r) {
    return r * l;
}

Complex& Complex::operator()(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}

Complex operator-(const Complex& obj) {
    Complex result(-obj.real(), -obj.imag());
    return result;
}

bool operator==(const Complex& l, const Complex& r) {
    if (l.real() != r.real()) {
        return false;
    }
    if (l.imag() != r.imag()) {
        return false;
    }
    return true;
}

bool operator!=(const Complex& l, const Complex& r) {
    if ( ( l.real() == r.real() ) && (l.imag() == r.imag()) ) {
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.real() == 0 && complex.imag() == 0) return out << "0";
    if (complex.real() != 0) {
        out << complex.real();
        if (complex.imag() > 0) out << " + " << complex.imag() << "i";
        else if (complex.imag() < 0) out << " - " << -complex.imag() << "i";
    }
    else {
        out << complex.imag() << "i";
    }
    return out;
}

Complex& Complex::operator++() {
    this->real_data = this->real_data + 1;
    return *this;
}

Complex  Complex::operator++(int) {
    Complex copy(*this);
    this->real_data = this->real_data + 1;
    return copy;
}

Complex& Complex::operator--() {
    this->real_data = this->real_data - 1;
    return *this;
}

Complex  Complex::operator--(int) {
    Complex copy(*this);
    this->real_data = this->real_data - 1;
    return copy;
}