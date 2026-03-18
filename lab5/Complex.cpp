#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
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
