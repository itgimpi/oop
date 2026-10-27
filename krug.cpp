#include <iostream>
#include <cmath>
#include <string>

// Помоћна структура за представљање тачке у 2D простору
struct Tacka {
    double x;
    double y; };

class Krug {
public:
    // Сви атрибути су јавни (public)
    double poluprecnik;
    Tacka centar;

    // Конструктор са подразумеваним вредностима
    Krug(double r = 1.0, double cx = 0.0, double cy = 0.0) {
        poluprecnik = r;
        centar.x = cx;
        centar.y = cy;
    }

    // Основни прорачуни
    double obim() const {
        return 2 * poluprecnik * M_PI;     }

    double povrsina() const {
        return std::pow(poluprecnik, 2) * M_PI;     }

    // Померање круга за вредности dx и dy
    void pomeri(double dx, double dy) {
        centar.x += dx;
        centar.y += dy;     }

    void zum(double k) {
        poluprecnik *= k;             }

    // Провера припадности тачке кругу
    bool pripadaLiTacka(Tacka t) const {
        double rastojanjeKvadrat = std::pow(t.x - centar.x, 2) + std::pow(t.y - centar.y, 2);
        return rastojanjeKvadrat <= std::pow(poluprecnik, 2);     }

    // Одређивање међусобног положаја два круга
    std::string medjusobniPolozaj(const Krug &drugi) const {
        double d = std::sqrt((centar.x - drugi.centar.x)*(centar.x - drugi.centar.x) 
                            + (centar.y - drugi.centar.y)*(centar.y - drugi.centar.y));
        double r1 = poluprecnik;
        double r2 = drugi.poluprecnik;

        if (d == 0 && r1 == r2) {
            return "Krugovi se poklapaju (koncentricni su i jednaki).";         }
        if (d > r1 + r2) {
            return "Krugovi su izvan jedan drugog i nemaju zajednickih tacaka.";        }
        if (d < std::abs(r1 - r2)) {
            return "Jedan krug se nalazi unutar drugog bez dodirivanja.";        }
        if (d == r1 + r2) {
            return "Krugovi se dodiruju sa spoljasnje strane.";        }
        if (d == std::abs(r1 - r2)) {
            return "Krugovi se dodiruju sa unutrasnje strane.";        }
        return "Krugovi se seku u dve tacke.";    }

    // Текстуална симулација цртања круга
    void nacrtaj() const {
        std::cout << "[CRTEZ] Crtam krug sa centrom u (" << centar.x << ", " << centar.y 
                  << ") i poluprecnikom " << poluprecnik << ".\n";
    }

    // Приказ основних информација
    void ispis() const {
        std::cout << "Centar kruga je (" << centar.x << ", " << centar.y << "), R=" << poluprecnik 
                  << ", O=" << obim() << ", P=" << povrsina() << "\n";
    }
};

int main() {
    // 1. Креирање објекта
    Krug k1(5, 2, 3); // R=5, центар у (2,3)
    //Krug k1;
    k1.ispis();

    k1.pomeri(1,1); // pomeri za (1,1)
    k1.ispis();

    k1.zum(2);
    k1.ispis();

    // 2. ДИРЕКТАН ПРИСТУП И ИЗМЕНА (омогућено јер је све public)
    std::cout << "\n--- Direktna izmena atributa ---\n";
    k1.poluprecnik = 10.0;  // Директно мењамо полупречник
    k1.centar.x = 0.0;      // Директно мењамо X координату центра
    k1.centar.y = 0.0;      // Директно мењамо Y координату центра
    
    // Штампамо вредности директним приступом атрибутима
    std::cout << "Novi poluprecnik: " << k1.poluprecnik << "\n";
    std::cout << "Novi centar: (" << k1.centar.x << ", " << k1.centar.y << ")\n";

    // 3. Провера нових прорачуна након директне измене
    k1.ispis();

    return 0;
}
