
#ifndef LAB4_Entitate_H
#define LAB4_Entitate_H

#include <iostream>

class Entitate {
private:
    int latura1;
    int latura2;
    int latura3;
public:
    Entitate();
    Entitate(int latura1, int latura2, int latura3);
    Entitate(const Entitate &tr);
    int getLatura1() const;
    int getLatura2()const;
    int getLatura3()const;
    void setLatura1(int latura1);
    void setLatura2(int latura2);
    void setLatura3(int latura3);
    int arie() const;
    int get_perimetru();
    bool operator==(const Entitate &e);
    Entitate& operator=(const Entitate &e);
    Entitate& operator>(const Entitate &e);
    friend std::istream& operator>>(std::istream& is, Entitate& e);
    friend std::ostream& operator<<(std::ostream& os, Entitate& e);

/////// operator << de afisare pt entitate
//    std::ostream &operator<<(std::ostream &os, Entitate &e) {
//        os << "Entitatea: cu lat1 = " << e.getLatura1() << " si lat2 = " << e.getLatura2() << " si lat3 = " << e.getLatura3() << '\n';
//        return os;
//    }
};


#endif //LAB4_Entitate_H
