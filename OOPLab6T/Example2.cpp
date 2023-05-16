#include "Lab6Example.h"
#include <iostream>
using namespace std;
namespace SpaceExample2 { 
    using namespace std;
#include <iostream>
#include <cmath>

    class Function {
    public:
        virtual double calculateValue(double x) const = 0;
    };

    class Line : public Function {
    private:
        double a, b;

    public:
        Line(double a, double b) : a(a), b(b) {}

        double calculateValue(double x) const override {
            return a * x + b;
        }
    };

    class Ellipse : public Function {
    private:
        double a, b;

    public:
        Ellipse(double majorAxis, double minorAxis) : a(majorAxis), b(minorAxis) {}

        double calculateValue(double x) const override {
            double y = sqrt(1 - pow(x, 2) / pow(a, 2)) * b;
            return y;
        }
    };

    class Hyperbola : public Function {
    private:
        double a, b;

    public:
        Hyperbola(double transverseAxis, double conjugateAxis) : a(transverseAxis), b(conjugateAxis) {}

        double calculateValue(double x) const override {
            double y = sqrt(pow(x, 2) / pow(a, 2) - 1) * b;
            return y;
        }
    };

    int mainExample2()
    {
        Line line(2.0, 3.0);
        Ellipse ellipse(5.0, 3.0);
        Hyperbola hyperbola(2.0, 2.0);

        double x = 2.5;
        std::cout << "Line: y = " << line.calculateValue(x) << std::endl;
        std::cout << "Ellipse: y = " << ellipse.calculateValue(x) << std::endl;
        std::cout << "Hyperbola: y = " << hyperbola.calculateValue(x) << std::endl;

        return 0;
    }


}