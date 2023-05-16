#include "Lab6Example.h"
#include <iostream>
namespace SpaceExample1 {
    ///Задача. Створити дві ієрархії класів без віртуального та з віртуальним спадкуванням, 
    // з елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами. 
    // Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. 
    // Вивести розміри об’єктів даних класів.
    ///
    class Base
    {
    protected:
        int dat;
        double a[5] = { 10,1,7,1,9 };
    public:
        Base() : dat(1) {}
        Base(int d) : dat(d) {}
    };
  
    class L : protected Base
    {
    protected:
        int l;
    public:
        L() : L(1) {}
        L(int d) : l(d) {}
        L(int d, int dt) : Base(dt), l(d) {}
    };

    class R : protected Base
    {
    protected:
        double r;
    public:
        R() : R(1) {}
        R(int d) : r(d) {}
        R(int d, double dt) : Base(d), r(dt) {}
    };

    class M1 : protected L, protected R
    {
    protected:
        double m1;
    public:
        M1() : m1(1) {}
        M1(int d) : m1(d) {}
        M1(int a, int b, int c, double d, int e) : L(a, b), R(c, d), m1(e) {}
    };

    class M2 : protected L, protected R, protected M1
    {
    protected:
        double m2;
    public:
        M2() : m2(1) {}
        M2(int d) : m2(d) {}
        M2(int a, int b, int c, double d, int e) : M1(a, b, c, d, e), L(a), R(b), m2(e + 1.) {}
        void showDat()
        {
            std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;
            /// << dat << std::endl;
          //  std::cout << "B12VV::LV::Base::dat =  " << L2::L::Base::dat << std::endl;
           // std::cout << "B12VV::LV::Base::dat =  " << Base::dat << std::endl;
      //      std::cout << "B12VV::LV::Base::dat =  " << L2::R::Base::dat << std::endl;
        }
    };
    
    //
    //  virtual
    //
    class LV : virtual protected Base
    {
    protected:
        int l;
    public:
        LV() : LV(1) {}
        LV(int d) : l(d) {}
        LV(int d, int dt) : Base(dt), l(d) {}
    };

    class RV : virtual protected Base
    {
    protected:
        double r;
    public:
        RV() : RV(1) {}
        RV(int d) : r(d) {}
        RV(int d, double dt) : Base(d), r(dt) {}
    };

    class M1V : virtual protected LV, virtual protected RV
    {
    protected:
        double m1;
    public:
        M1V() : m1(1) {}
        M1V(int d) : m1(d) {}
        M1V(int a, int b, int c, double d, int e) : LV(a, b), RV(c, d), m1(e) {}
    };

    class M2V : virtual protected LV, virtual protected RV, virtual protected M1V
    {
    protected:
        double m2;
    public:
        M2V() : m2(1) {}
        M2V(int d) : m2(d) {}
        M2V(int a, int b, int c, double d, int e) : M1V(a, b, c, d, e), LV(a), RV(b), m2(e + 1.) {}
        void showDat()
        {
            std::cout << "  m1 =  " << m1 << std::endl;
            std::cout << "M1V::LV::Base::dat =  " << M1V::LV::Base::dat << std::endl;
            std::cout << "M1V::m1 =  " << M1V::m1 << std::endl;
            std::cout << "M1V::RV::Base::dat =  " << M1V::RV::Base::dat << std::endl;
        }
    };

    int mainExample1()
    {
        std::cout << " Example1  \n";
        M2 a, b(1, 2, 3, 4.5, 5);
        M2V av, bv(1, 2, 3, 4.5, 5);

        std::cout << "Test !\n";
        std::cout << "Size for Base " << sizeof(Base) << std::endl;
        std::cout << "Size for L " << sizeof(L) << std::endl;
        std::cout << "Size for R " << sizeof(R) << std::endl;
        std::cout << "Size for M1 " << sizeof(M1) << std::endl;
        std::cout << "Size for M2 " << sizeof(M2) << std::endl;

        std::cout << "Size for Base " << sizeof(Base) << std::endl;
        std::cout << "Size for LV " << sizeof(LV) << std::endl;
        std::cout << "Size for RV " << sizeof(RV) << std::endl;
        std::cout << "Size for M1V " << sizeof(M1V) << std::endl;
        std::cout << "Size for M2V " << sizeof(M2V) << std::endl;

        std::cout << "Size for object class M2 " << sizeof(M2) << " or  "
            << sizeof(a) << " or  " << sizeof(b) << std::endl;
        std::cout << "Size for object class M2V " << sizeof(M2V) << " or  "
            << sizeof(av) << " or  " << sizeof(bv) << std::endl;
        b.showDat();
        bv.showDat();
        return 0;
    }

}