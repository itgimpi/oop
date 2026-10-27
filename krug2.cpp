#include <iostream>
#include <cmath>
#include <string>
//#include <windows.h>

struct Tacka {    double x;    double y; };

class Krug {
private:
    double poluprecnik;
    Tacka centar; 

public:
    // Конструктор са подразумеваним вредностима (центар у (0,0), полупречник 1)
    Krug(double r = 1.0, double cx = 0.0, double cy = 0.0) {
        centar.x = cx;
        centar.y = cy;
        setPoluprecnik(r);     }

    // Сетер и гетер методе
    void setPoluprecnik(double r) {
        if (r > 0) 
            poluprecnik = r;
        else {
            std::cout << "Грешка: Полупречник мора бити већи од 0! Постављам на 1.0.\n";
            poluprecnik = 1.0;         }     }

    double getPoluprecnik() const { return poluprecnik; }

    Tacka getCentar() const { return centar; }
    void setCentar(double cx, double cy) { centar.x = cx; centar.y = cy; }

    // Основни прорачуни
    double obim() const {
        return 2 * poluprecnik * M_PI;     }

    double povrsina() const {
        return std::pow(poluprecnik, 2) * M_PI;    }

    // Померање круга за вредности dx и dy
    void pomeri(double dx, double dy) {
        centar.x += dx;
        centar.y += dy;     }

    // Провера припадности тачке кругу
    // Тачка припада кругу ако је њено растојање до центра мање или једнако полупречнику
    bool припадаЛиТачка(Tacka t) const {
        double rastojanjeKvadrat = std::pow(t.x - centar.x, 2) + std::pow(t.y - centar.y, 2);
        return rastojanjeKvadrat <= std::pow(poluprecnik, 2); // Избегавамо sqrt због перформанси
    }

    // Одређивање међусобног положаја два круга
    std::string medjusobniPolozaj(const Krug& drugi) const {
        // Растојање између центара два круга
        double d = std::sqrt(std::pow(centar.x - drugi.centar.x, 2) + std::pow(centar.y - drugi.centar.y, 2));
        double r1 = poluprecnik;
        double r2 = drugi.poluprecnik;

        if (d == 0 && r1 == r2) {
            return "Кругови се поклапају (концентрични су и једнаки).";         }
        if (d > r1 + r2) {
            return "Кругови су изван један другог и немају заједничких тачака.";         }
        if (d < std::abs(r1 - r2)) {
            return "Један круг се налази унутар другог без додиривања.";         }
        if (d == r1 + r2) {
            return "Кругови се додирују са спољашње стране.";        }
        if (d == std::abs(r1 - r2)) {
            return "Кругови се додирују са унутрашње стране.";        }
        // Ако је |r1 - r2| < d < r1 + r2
        return "Кругови се секу у две тачке.";      }

    // Текстуална симулација цртања круга на конзоли
    void nacrtaj() const {
        std::cout << "[ЦРТЕЖ] Цртам круг са центром у (" << centar.x << ", " << centar.y 
                  << ") и полупречником " << poluprecnik << ".\n";
    }

    // Приказ основних информација
    void ispis() const {
        std::cout << "Круг: Центар(" << centar.x << ", " << centar.y << "), Р=" << poluprecnik 
                  << ", О=" << obim() << ", П=" << povrsina() << "\n";
    }
};

int main() {
    //SetConsoleOutputCP(CP_UTF8);
    
    // 1. Креирање кругова
    Krug k1(5, 0, 0); // Центар у (0,0), р=5
    Krug k2(3, 7, 0); // Центар у (7,0), р=3
    
    std::cout << "--- Почетно стање ---\n";
    k1.ispis();
    k2.ispis();

    // 2. Међусобни положај
    std::cout << "\n--- Међусобни положај ---\n";
    std::cout << k1.medjusobniPolozaj(k2) << "\n"; // Растојање центара је 7, р1+р2=8 (секу се)

    // 3. Провера тачке
    std::cout << "\n--- Провера припадности тачке кругу 1 ---\n";
    Tacka t1 = {3, 3}; // Растојање до (0,0) је sqrt(18) ~ 4.24 (мање од р=5)
    Tacka t2 = {6, 0}; // Растојање је 6 (веће од р=5)
    
    std::cout << "Тачка (3,3) припада к1: " << (k1.припадаЛиТачка(t1) ? "ДА" : "НЕ") << "\n";
    std::cout << "Тачка (6,0) припада к1: " << (k1.припадаЛиТачка(t2) ? "ДА" : "НЕ") << "\n";

    // 4. Померање круга
    std::cout << "\n--- Померање круга 1 ---\n";
    k1.pomeri(2, 3); // Нови центар је (2,3)
    k1.ispis();

    // 5. Симболичко цртање
    std::cout << "\n--- Цртање ---\n";
    k1.nacrtaj();

    return 0;
}
