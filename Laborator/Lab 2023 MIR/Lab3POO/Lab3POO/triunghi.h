#pragma once
#include <ostream>
#include <iostream>

using namespace std;

//class Patrat {
//private:
//	int latura;
//
//public:
//	Patrat();
//	Patrat(int latura);
//	Patrat(const Patrat& pt);
//
//	int getLatura();
//	void setLatura(int latura);
//	int getArie();
//	Patrat& operator=(const Patrat& pt);
//	~Patrat() {
//		//nimic de facut
//	}
//	friend ostream& operator<<(ostream& os, const Patrat& pt);
//};

class Triunghi {
private:
	int latura1;
	int latura2;
	int latura3;

public:
	//constr fara param
	Triunghi();

	//constr cu param
	Triunghi(int latura1, int latura2, int latura3);

	// copy constr
	Triunghi(const Triunghi& tr);

	// getter pentru latura a 1 a triunghiului
	int getLatura1(); 

	// getter pentru latura a 2 a triunghiului

	int getLatura2();
	// getter pentru latura a 3 a triunghiului
	int getLatura3();

	// setter pentru latura a 1 a triunghiului
	void setLatura1(int latura1);

	// setter pentru latura a 2 a triunghiului
	void setLatura2(int latura2);

	// setter pentru latura a 2 a triunghiului
	void setLatura3(int latura3);

	// returneaza aria triunghiului 
	int getArie();

	// returneaza perimetrul triunghiului
	int getPerimetru();

	//op de atribuire
	Triunghi& operator=(const Triunghi& tr);

	// destructor
	~Triunghi() {
		//delete[] Triunghi;
	}
	friend ostream& operator<<(ostream& os, const Triunghi& tr);
};








//class Triunghi {
//private:
//	double a;
//	double b;
//	double c;
//
//public:
//	// Constructor with parameters
//	Triunghi(double side_a, double side_b, double side_c) {
//		a = side_a;
//		b = side_b;
//		c = side_c;
//	}
//
//	// Setters
//	void setA(double side_a) {
//		a = side_a;
//	}
//
//	void setB(double side_b) {
//		b = side_b;
//	}
//
//	void setC(double side_c) {
//		c = side_c;
//	}
//
//	// Getters
//	double getA() const {
//		return a;
//	}
//
//	double getB() const {
//		return b;
//	}
//
//	double getC() const {
//		return c;
//	}
//
//	// Destructor
//	~Triunghi() {
//		std::cout << "Triunghi destroyed." << std::endl;
//	}
//
//	// Calculates the perimeter of the triangle
//	double perimeter() const {
//		return a + b + c;
//	}
//
//	// Calculates the area of the triangle using Heron's formula
//	double area() const {
//		double s = (a + b + c) / 2.0;
//		return std::sqrt(s * (s - a) * (s - b) * (s - c));
//	}
//};





// #include <cmath>
/*
class Complex {
private:
	double real;
	double imag;

public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	double getReal() const { return real; }
	double getImag() const { return imag; }

	void setReal(double r) { real = r; }
	void setImag(double i) { imag = i; }

	double magnitude() const { return std::sqrt(real * real + imag * imag); }

	Complex operator+(const Complex& other) const {
		return Complex(real + other.real, imag + other.imag);
	}

	Complex operator*(const Complex& other) const {
		return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
	}

	~Complex() {
		cout << "Destroying complex number (" << real << ", " << imag << ")" << endl;
	}
}; */

/*
class Triangle {
private:
	double side1;
	double side2;
	double side3;

public:
	Triangle(double s1 = 0.0, double s2 = 0.0, double s3 = 0.0) : side1(s1), side2(s2), side3(s3) {}

	double getSide1() const { return side1; }
	double getSide2() const { return side2; }
	double getSide3() const { return side3; }

	void setSide1(double s) { side1 = s; }
	void setSide2(double s) { side2 = s; }
	void setSide3(double s) { side3 = s; }

	double area() const {
		double s = (side1 + side2 + side3) / 2.0;
		return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
	}

	double perimeter() const { return side1 + side2 + side3; }

	~Triangle() {
		std::cout << "Destroying triangle with sides (" << side1 << ", " << side2 << ", " << side3 << ")" << std::endl;
	}
};*/

/*
class Triangle {
private:
	double side1;
	double side2;
	double side3;

public:
	// Constructor with parameters
	Triangle(double s1, double s2, double s3) {
		side1 = s1;
		side2 = s2;
		side3 = s3;
	}

	// Setters
	void setSide1(double s) { side1 = s; }
	void setSide2(double s) { side2 = s; }
	void setSide3(double s) { side3 = s; }

	// Getters
	double getSide1() { return side1; }
	double getSide2() { return side2; }
	double getSide3() { return side3; }

	// Destructor
	~Triangle() {
		// Here you can add any code that needs to be executed when the object is destroyed.
		// For example, releasing any resources or closing any open files.
	}
};*/

/*


*/


/*
class Circle {
private:
	double radius;

public:
	// Constructor with parameters
	Circle(double r) {
		radius = r;
	}

	// Getters and setters
	double getRadius() const {
		return radius;
	}

	void setRadius(double r) {
		radius = r;
	}

	// Destructor
	~Circle() {
		std::cout << "Circle object destroyed" << std::endl;
	}

	// Other methods
	double getArea() const {
		return M_PI * radius * radius;
	}

	double getCircumference() const {
		return 2 * M_PI * radius;
	}
};
*/


/*
class Rectangle {
private:
	double width;
	double height;

public:
	// Constructor with parameters
	Rectangle(double w, double h) {
		width = w;
		height = h;
	}

	// Getters and setters
	double getWidth() const {
		return width;
	}

	void setWidth(double w) {
		width = w;
	}

	double getHeight() const {
		return height;
	}

	void setHeight(double h) {
		height = h;
	}

	// Destructor
	~Rectangle() {
		std::cout << "Rectangle object destroyed" << std::endl;
	}

	// Other methods
	double getArea() const {
		return width * height;
	}

	double getPerimeter() const {
		return 2 * (width + height);
	}
};
*/