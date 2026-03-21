#pragma once
#include <ostream>
class Complex {
private:
    double real_data;
    double imag_data;

public:
    Complex();
    Complex(double real, double imag);
    Complex(const Complex& complex);
    Complex(Complex&& complex);

    bool is_real() const;

    double real() const;
    double imag() const;
    double abs() const;
    Complex conjugate() const;

    Complex& operator()(double real, double imag);
    Complex& operator=(const Complex& complex);
    Complex& operator=(Complex&& complex);
    Complex& operator++(); //++a
    Complex operator++(int); //a++
    Complex& operator--(); //--a
    Complex operator--(int); //a--
};

Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l, const Complex& r);
Complex operator-(const Complex& l, const Complex& r);
Complex operator-(const Complex& l, double r);
Complex operator-(double l, const Complex& r);
Complex operator*(const Complex& l, const Complex& r);
Complex operator*(const Complex& l, double r);
Complex operator*(double l, const Complex& r);
Complex operator-(const Complex& obj);

bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

std::ostream& operator<<(std::ostream& out, const Complex& complex);


