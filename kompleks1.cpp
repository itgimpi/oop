#include <iostream>
#include <cmath>

class KompleksanBroj {
private:
    double re; // Realni deo
    double im; // Imaginarni deo

public:
    // Konstruktor
    KompleksanBroj(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    // Geteri javnog interfejsa
    double getRealni() const { return re; }
    double getImaginarni() const { return im; }
    
    double getModuo() const { return std::sqrt(re * re + im * im); }
    double getArgument() const { return std::atan2(im, re); }

    void prikazi() const {
        std::cout << re << (im >= 0 ? " + " : " - ") << std::abs(im) << "i" << std::endl;
    }
    // --- PREKLOPLJENI OPERATORI ---

    // 1. Operator sabiranja (+)
    KompleksanBroj operator+(const KompleksanBroj& drugi) const {
        // (a + bi) + (c + di) = (a + c) + (b + d)i
        return KompleksanBroj(re + drugi.re, im + drugi.im);
    }

    // 2. Operator oduzimanja (-)
    KompleksanBroj operator-(const KompleksanBroj& drugi) const {
        // (a + bi) - (c + di) = (a - c) + (b - d)i
        return KompleksanBroj(re - drugi.re, im - drugi.im);
    }

    // 3. Operator množenja (*)
    KompleksanBroj operator*(const KompleksanBroj& drugi) const {
        // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
        double noviRe = re * drugi.re - im * drugi.im;
        double noviIm = re * drugi.im + im * drugi.re;
        return KompleksanBroj(noviRe, noviIm);
    }

    // 4. Operator deljenja (/)
    KompleksanBroj operator/(const KompleksanBroj& drugi) const {
        // Deljenje se vrši množenjem konjugovanim brojem imenioca
        double imenilac = drugi.re * drugi.re + drugi.im * drugi.im;
        if (imenilac == 0) {
            std::cerr << "Greska: Deljenje nulom!" << std::endl;
            return KompleksanBroj(0, 0);
        }
        double noviRe = (re * drugi.re + im * drugi.im) / imenilac;
        double noviIm = (im * drugi.re - re * drugi.im) / imenilac;
        return KompleksanBroj(noviRe, noviIm);
    }

    // 5. Globalni operator za ispis (<<) kao prijatelj klase
    friend std::ostream& operator<<(std::ostream& os, const KompleksanBroj& z) {
        os << z.re;
        if (z.im >= 0) {
            os << " + " << z.im << "i";
        } else {
            os << " - " << std::abs(z.im) << "i"; // Sređivanje ispisa za negativne brojeve
        }
        return os;
    }

    void ispis() const {

        std::cout << re;
        if (im >= 0) 
            std::cout << " + " << im << "i";
        else 
            std::cout << " - " << std::abs(im) << "i"; // Sređivanje ispisa za negativne brojeve


    }
};

int main() {
    KompleksanBroj z1(3.0, 4.0);  // 3 + 4i
    KompleksanBroj z2(1.0, -2.0); // 1 - 2i

    std::cout << "z1 = "; z1.ispis(); std::cout << std::endl;
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;

    std::cout << "z1 + z2 = " << z1 + z2 << std::endl;
    std::cout << "z1 - z2 = " << z1 - z2 << std::endl;
    std::cout << "z1 * z2 = " << z1 * z2 << std::endl;
    std::cout << "z1 / z2 = " << z1 / z2 << std::endl;

    return 0;
}
