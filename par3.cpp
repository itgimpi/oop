#include <iostream>
#include <string>
template <typename T1, typename T2>
class Par {
public:
    T1 prvi;
    T2 drugi;
    Par () {}
    Par (T1 p, T2 d) : prvi(p), drugi(d) {}
};


int main() {
    Par<int, int> p1(1,2);
    std::cout << p1.prvi << ' ' << p1.drugi << '\n';
    Par<int, double> p2(3, 3.14);
    std::cout << p2.prvi << ' ' << p2.drugi << '\n';
    Par<std::string, int> p3("qwerty", 12345);
    std::cout << p3.prvi << ' ' << p3.drugi << '\n';
    
    return 0;
}
