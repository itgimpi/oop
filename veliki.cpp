#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>

class Veliki {
public:    
//private:
    // Цифре се чувају у обрнутом редоследу (нпр. 123 се чува као {3, 2, 1})
    std::vector<int> cifre;

    /*
    void nule() {
        while (cifre.size() > 1 && cifre.back() == 0) {
            cifre.pop_back();
        }
    } */

//public:
    // Конструктор на основу стринга
    Veliki(std::string s) {
        if (s.empty()) {
            cifre.push_back(0);
            return;  }

        // Убацивање цифара у обрнутом редоследу
        for (int i = s.length() - 1; i >= 0; --i) 
            cifre.push_back(s[i] - '0');            
            //if (isdigit(s[i])) {
                //cifre.push_back(s[i] - '0');            }        }
        //nule();    }
}
    // Подразумевани конструктор (вредност 0)
    Veliki() {
        cifre.push_back(0);     }

    // Функција за испис броја
    void ispis() const {
        for (int i = cifre.size() - 1; i >= 0; --i) {
            std::cout << cifre[i];
        }
        std::cout << std::endl;
    }

    // Оператор поређења (мање од)
    bool operator<(const Veliki& drugi) const {
        if (cifre.size() != drugi.cifre.size()) {
            return cifre.size() < drugi.cifre.size();         }

        for (int i = cifre.size() - 1; i >= 0; --i) {
            if (cifre[i] != drugi.cifre[i]) {
                return cifre[i] < drugi.cifre[i];             }          }
        return false; // isti
    }

    // Оператор сабирања (+)
    Veliki operator+(const Veliki& drugi) const {
        Veliki zbir;
        //zbir.cifre.clear();
        zbir.cifre.pop_back();

        int prenos = 0;
        size_t i = 0;

        // Пролазак кроз обе цифре док их има, уз узимање у обзир преноса
        while (i < cifre.size() || i < drugi.cifre.size() || prenos) {

            int dodaj = prenos;
            if (i < cifre.size()) dodaj += cifre[i];
            if (i < drugi.cifre.size()) dodaj += drugi.cifre[i];

            zbir.cifre.push_back(dodaj % 10);
            prenos = dodaj / 10;
            i++;
        }

        return zbir;
    }

    // Оператор множења (*)
    Veliki operator*(const Veliki& drugi) const {
        // Ако је било који број 0, резултат је 0
        if ((cifre.size() == 1 && cifre[0] == 0) || (drugi.cifre.size() == 1 && drugi.cifre[0] == 0)) {
            return Veliki("0");
        }

        Veliki zbir;
        zbir.cifre.assign(cifre.size() + drugi.cifre.size(), 0);

        // Класично "потписивање" и множење сваке цифре са сваком
        for (size_t i = 0; i < cifre.size(); ++i) {
            int prenos = 0;
            for (size_t j = 0; j < drugi.cifre.size() || prenos; ++j) {
                long long trenutni = zbir.cifre[i + j] + (long long)cifre[i] * (j < drugi.cifre.size() ? drugi.cifre[j] : 0) + prenos;
                zbir.cifre[i + j] = trenutni % 10;
                prenos = trenutni / 10;
            }
        }

        //zbir.nule();
        return zbir;
    }
};

int main() {
    // Тестирање класе са великим бројевима
    Veliki a("999");
    Veliki b("123");

    a.ispis();
    b.ispis();

    Veliki zbir = a + b;
    zbir.ispis();

    //Veliki proizvod = a * b;
    //proizvod.ispis();

    std::cout << "prvi " << (a < b ? "je manji" : "nije manji") << std::endl;

    return 0;
}
