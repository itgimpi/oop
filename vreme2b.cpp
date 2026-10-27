#include <iostream>
#include <iomanip>
#include <string>

class Vreme {
private:
    int sat;
    int minut;

    // Помоћна метода за нормализацију времена (нпр. 25:61 постаје 02:01)
    void sredi() {
        if (minut >= 60) {
            sat += minut / 60;
            minut %= 60;         } 

        else if (minut < 0) {
            // Руковање негативним минутима у случају одузимања
            int satiManje = (-minut / 60) + 1;
            sat -= satiManje;
            minut = 60 + (minut % 60);         }
            
        sat %= 24;
        if (sat < 0) sat += 24;
    }

public:
    // Конструктор
    Vreme(int s = 0, int m = 0) : sat(s), minut(m) {
        sredi();     }

    // Приказ у 24-часовном формату (нпр. 22:34)
    void prikazi24() const {
        std::cout << std::setfill('0') << std::setw(2) << sat << ":"
                  << std::setfill('0') << std::setw(2) << minut << std::endl;
    }

    // Приказ у 12-часовном формату (нпр. 10:34 PM)
    void prikazi12() const {
        int s12 = sat % 12;
        if (s12 == 0) s12 = 12;
        std::string period = (sat < 12) ? "AM" : "PM";
        
        std::cout << std::setfill('0') << std::setw(2) << s12 << ":"
                  << std::setfill('0') << std::setw(2) << minut << " " << period << std::endl;
    }

    
    // Додавање минута (враћа ново време)
    Vreme dodajMinute(int m) const {
        return Vreme(sat, minut + m);
    }

    Vreme oduzmiMinute(int m) const {
        return Vreme(sat, minut - m);
    }

    // Упоређивање два времена
    // Враћа: -1 ако је тренутно време мање, 0 ако су једнака, 1 ако је тренутно веће
    int uporedi(const Vreme& ostalo) const {
        int t1 = sat * 60 + minut;
        int t2 = ostalo.sat * 60 + ostalo.minut;
        
        if (t1 < t2) return -1;
        if (t1 > t2) return 1;
        return 0;     }

    int uMinute() const {
        return sat * 60 + minut;
    }

    // 1. Преоптерећивање оператора за сабирање (Време + минути)
    Vreme operator+(int m) const {
        return Vreme(sat, minut + m);
    }

    Vreme operator-(int m) const {
        return Vreme(sat, minut - m);
    }

    // 2. Преоптерећивање оператора за поређење
    bool operator==(const Vreme& ostalo) const {
        return this->uMinute() == ostalo.uMinute();
    }

    bool operator<(const Vreme& ostalo) const {
        return this->uMinute() < ostalo.uMinute();
    }

    bool operator>(const Vreme& ostalo) const {
        return this->uMinute() > ostalo.uMinute();
    }

    // 3. Преоптерећивање оператора за испис << (пријатељска функција)
    // Ово мења методу prikazi24() и омогућава коришћење cout << vreme;
    friend std::ostream& operator<<(std::ostream& os, const Vreme& v) {
        os << std::setfill('0') << std::setw(2) << v.sat << ":"
           << std::setfill('0') << std::setw(2) << v.minut;
        return os;     }

};


int main() {
    // Тестирање прве верзије
    Vreme v1(22, 34);
    std::cout << v1 << std::endl;
    std::cout << "V1 - 12h format: "; v1.prikazi12();

    Vreme v2 = v1 + 90; // 22:34 + 1h 30min = 00:04 следећег дана
    std::cout << v2 << '\n';

    Vreme v3 = v1 - 90; // 22:34 + 1h 30min = 00:04 следећег дана
    std::cout << v3 << '\n';
    // Тестирање друге верзије
    //VremeUkupnoMinuta v3(22, 34);
    //VremeUkupnoMinuta v4(10, 15);
    
    if (v3 > v2) std::cout << "vece";
    if (v3 < v2) std::cout << "manje";
    if (v3 == v2) std::cout << "isto";
    
    return 0;
}