#include <iostream>
#include <iomanip>
#include <string>

#include <iostream>
#include <iomanip>
#include <string>

class Vreme {
private:
    int ukupnoMinuta; // Од 0 до 1439 (24 * 60 - 1)

    void normalizuj() {
        ukupnoMinuta %= 1440;
        if (ukupnoMinuta < 0) {
            ukupnoMinuta += 1440;
        }
    }

public:
    // Конструктор
    Vreme(int s = 0, int m = 0) {
        ukupnoMinuta = s * 60 + m;
        normalizuj();
    }

    // Приказ у 24-часовном формату
    void prikazi24() const {
        int sat = ukupnoMinuta / 60;
        int minut = ukupnoMinuta % 60;
        std::cout << std::setfill('0') << std::setw(2) << sat << ":"
                  << std::setfill('0') << std::setw(2) << minut << std::endl;
    }

    // Приказ у 12-часовном формату
    void prikazi12() const {
        int sat = ukupnoMinuta / 60;
        int minut = ukupnoMinuta % 60;
        
        int s12 = sat % 12;
        if (s12 == 0) s12 = 12;
        std::string period = (sat < 12) ? "AM" : "PM";
        
        std::cout << std::setfill('0') << std::setw(2) << s12 << ":"
                  << std::setfill('0') << std::setw(2) << minut << " " << period << std::endl;
    }

    // Додавање минута
    Vreme dodajMinute(int m) const {
        Vreme novo;
        novo.ukupnoMinuta = this->ukupnoMinuta + m;
        novo.normalizuj();
        return novo;
    }

    // Упоређивање два vremena
    int uporedi(const Vreme& ostalo) const {
        if (ukupnoMinuta < ostalo.ukupnoMinuta) return -1;
        if (ukupnoMinuta > ostalo.ukupnoMinuta) return 1;
        return 0;
    }
};



int main() {
    // Тестирање прве верзије
    Vreme v1(22, 34);
    std::cout << "V1 - 24h format: "; v1.prikazi24();
    std::cout << "V1 - 12h format: "; v1.prikazi12();

    Vreme v2 = v1.dodajMinute(90); // 22:34 + 1h 30min = 00:04 следећег дана
    std::cout << "V1 nakon +90 min: "; v2.prikazi24();

    // Тестирање друге верзије
    //Vreme v3(22, 34);
    //Vreme v4(10, 15);
    
    //std::cout << "\nUsporedba V3 i V4: " << v3.uporedi(v4) << " (1 znaci da je V3 vece)";
    
    return 0;
}