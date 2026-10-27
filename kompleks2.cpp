#include <iostream>
#include <cmath>

class KompleksanBroj {
private:
    double moduo; // Magnituda (r)
    double arg;   // Ugao u radijanima (theta)

public:
    // Konstruktor koji prihvata polarne koordinate (moduo i argument)
    KompleksanBroj(double m = 0.0, double a = 0.0) : moduo(m), arg(a) {}

    // --- JAVNI INTERFEJS (IDENTIČAN KAO U VERZIJI 1) ---
    
    double getRealni() const { return moduo * std::cos(arg); }
    double getImaginarni() const { return moduo * std::sin(arg); }
    
    double getModuo() const { return moduo; }
    double getArgument() const { return arg; }

    // --- PREKLOPLJENI OPERATORI ---

    // 1. Operator sabiranja (+) - zahteva privremenu konverziju u Dekartove
    KompleksanBroj operator+(const KompleksanBroj& drugi) const {
        double re1 = getRealni();
        double im1 = getImaginarni();
        double re2 = drugi.getRealni();
        double im2 = drugi.getImaginarni();

        double noviRe = re1 + re2;
        double noviIm = im1 + im2;

        // Vraćanje rezultata u polarnu formu
        double noviModuo = std::sqrt(noviRe * noviRe + noviIm * noviIm);
        double noviArg = std::atan2(noviIm, noviRe);

        return KompleksanBroj(noviModuo, noviArg);
    }

    // 2. Operator oduzimanja (-) - zahteva privremenu konverziju u Dekartove
    KompleksanBroj operator-(const KompleksanBroj& drugi) const {
        double re1 = getRealni();
        double im1 = getImaginarni();
        double re2 = drugi.getRealni();
        double im2 = drugi.getImaginarni();

        double noviRe = re1 - re2;
        double noviIm = im1 - im2;

        double noviModuo = std::sqrt(noviRe * noviRe + noviIm * noviIm);
        double noviArg = std::atan2(noviIm, noviRe);

        return KompleksanBroj(noviModuo, noviArg);
    }

    // 3. Operator množenja (*) - Izuzetno efikasan u polarnoj formi!
    KompleksanBroj operator*(const KompleksanBroj& drugi) const {
        // z1 * z2 = (r1 * r2) 2_ Z(theta1 + theta2)
        return KompleksanBroj(moduo * drugi.moduo, arg + drugi.arg);
    }

    // 4. Operator deljenja (/) - Izuzetno efikasan u polarnoj formi!
    KompleksanBroj operator/(const KompleksanBroj& drugi) const {
        if (drugi.moduo == 0) {
            std::cerr << "Greska: Deljenje nulom (moduo imenioca je 0)!" << std::endl;
            return KompleksanBroj(0, 0);
        }
        // z1 / z2 = (r1 / r2) 2_ Z(theta1 - theta2)
        return KompleksanBroj(moduo / drugi.moduo, arg - drugi.arg);
    }

    // 5. Globalni operator za ispis (<<) 
    // Primetite: da bi klijentski kod video "a + bi", koristimo getere za Dekartove koordinate.
    friend std::ostream& operator<<(std::ostream& os, const KompleksanBroj& z) {
        double re = z.getRealni();
        double im = z.getImaginarni();
        os << re;
        if (im >= 0) {
            os << " + " << im << "i";
        } else {
            os << " - " << std::abs(im) << "i";
        }
        // Opciono: Možemo ispisati i polarni oblik radi provere
        os << " [Polar: r=" << z.moduo << ", theta=" << z.arg << "]";
        return os;
    }
};

int main() {
    // PAŽNJA: Konstruktor sada očekuje (moduo, argument).
    // Napravićemo iste brojeve kao u prošlom primeru radi poređenja:
    // z1 = 3 + 4i  => moduo = 5, arg = atan2(4,3) = 0.927295 rad
    // z2 = 1 - 2i  => moduo = sqrt(5) = 2.236068, arg = atan2(-2,1) = -1.107148 rad
    KompleksanBroj z1(5.0, std::atan2(4.0, 3.0));
    KompleksanBroj z2(std::sqrt(5.0), std::atan2(-2.0, 1.0));

    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;

    // Klijentski kod je ostao POTPUNO isti kao za Verziju 1
    KompleksanBroj zbir = z1 + z2;
    KompleksanBroj razlika = z1 - z2;
    KompleksanBroj proizvod = z1 * z2;
    KompleksanBroj kolicnik = z1 / z2;

    std::cout << "\n--- Rezultati operacija (Polar) ---" << std::endl;
    std::cout << "z1 + z2 = " << zbir << std::endl;
    std::cout << "z1 - z2 = " << razlika << std::endl;
    std::cout << "z1 * z2 = " << proizvod << std::endl;
    std::cout << "z1 / z2 = " << kolicnik << std::endl;

    return 0;
}
