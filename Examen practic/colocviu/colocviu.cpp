// colocviu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

 
#include <iostream>
#include <string>

class Carte {
protected:
    std::string titlu;

public:
    Carte(const std::string& titlu) : titlu(titlu) {
        std::cout << "[Carte]: constructor with parameters" << std::endl;
    }

    // Copy constructor
    Carte(const Carte& carte) : titlu(carte.titlu) {
        std::cout << "[Carte]: copy constructor" << std::endl;
    }
};

class Manual : public Carte {
private:
    int nrLectii;

public:
    Manual(const std::string& titlu, int nrLectii) : Carte(titlu), nrLectii(nrLectii) {
        std::cout << "[Manual]: constructor with parameters" << std::endl;
    }

    // Copy constructor
    Manual(const Manual& manual) : Carte(manual), nrLectii(manual.nrLectii) {
        std::cout << "[Manual]: copy constructor" << std::endl;
    }
};

//adunarea a doua numere complexe
class Complex {

    private:
	int real;
	int imaginar;
    public:
        Complex(int real = 0, int imaginar = 0) {
                
            this->real = real;
			this->imaginar = imaginar;
        }
        Complex(const Complex& c) {
			real = c.real;
            imaginar = c.imaginar;

        }
        Complex operator+(Complex const& c) {
			Complex rez;
			rez.real = real + c.real;
			rez.imaginar = imaginar + c.imaginar;
			return rez;
		}
        Complex operator-(Complex const& c) {
			Complex rez;
			rez.real = real - c.real;
			rez.imaginar = imaginar - c.imaginar;
			return rez;
		}

        Complex operator*(Complex const& c) {
			Complex rez;
			rez.real = real * c.real;
			rez.imaginar = imaginar * c.imaginar;
			return rez;
		}
        Complex operator/(Complex const& c) {
			Complex rez;
			rez.real = real / c.real;
			rez.imaginar = imaginar / c.imaginar;
			return rez;
		}
        Complex operator=(Complex const& c) {
			real = c.real;
			imaginar = c.imaginar;
			return *this;
		}
        bool operator==(Complex const& c) {
			return (real == c.real && imaginar == c.imaginar);
		}
        bool operator!=(Complex const& c) {
			return (real != c.real && imaginar != c.imaginar);
		}
        bool operator>(Complex const& c) {
			return (real > c.real && imaginar > c.imaginar);
		}
        bool operator<(Complex const& c) {
			return (real < c.real && imaginar < c.imaginar);
		}
        bool operator>=(Complex const& c) {
			return (real >= c.real && imaginar >= c.imaginar);
		}
        bool operator<=(Complex const& c) {
			return (real <= c.real && imaginar <= c.imaginar);
		}
		friend std::ostream& operator<<(std::ostream& out, const Complex& c);
		friend std::istream& operator>>(std::istream& in, Complex& c);

};
int main() {
    Carte carte1("Titlu1");
    Carte carte2 = carte1; // Copy constructor called

    Manual manual1("Titlu2", 10);
    Manual manual2 = manual1; // Copy constructor called

    return 0;
}



 