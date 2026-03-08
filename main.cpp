// COMSC-200 | Assignment 3A | Loma Kim
#include <iostream>
#include <string>
using namespace std;

class Marble {
    private:
    static unsigned int count;
    unsigned int number;
    double radius;

    public:
    Marble(double);
    //Accessor functions
    unsigned int getNumber() const { return number; }
    double getRadius() const { return radius; }
    //Mutator functions
    void setRadius(double r) { radius = r; }

    double getVolume() { return (4/3 * 3.14159 * radius * radius * radius); }
    Marble operator++();
    Marble operator++(int);
    Marble operator+(const Marble &);
    Marble operator-(const Marble &);

};


int main() {
    Marble m1(1.3);
    cout << "Radius: " << m1.getRadius() << endl;
    cout << "Volume: " << m1.getVolume() << endl;
    cout << "Number: " << m1.getNumber() << endl;
    m1++;
    cout << "New Radius: " << m1.getRadius() << endl;
    ++m1;
    cout << "New Radius: " << m1.getRadius() << endl;

    return 0;
}

unsigned int Marble::count = 0;

/*CONSTRUCTOR - default constructor which can accept an argument:
    - increments count
    - assigns count to marble number
    - assigns argument to radius                                 */
Marble::Marble(double r = 0){
    number = ++count;
    radius = r;
}

//OVERLOADED PREFIX INCREMENT OPERATOR
Marble Marble::operator++() {
    ++radius;
    return *this;
}

//OVERLOADED POSTFIX INCREMENT OPERATOR
Marble Marble::operator++(int) {
    Marble temp(radius);    // create temp Marble to hold radius value
    count--;                // decrement count value as temp is not a part of the marble count
    radius++;               // increment radius of this Marble
    return temp;            // return original value of this Marble
}

//OVERLOADED ADDITION OPERATOR
Marble Marble::operator+(const Marble& rhs) {
    Marble temp;
    return temp;
}

//OVERLOADED SUBTRACTION OPERATOR
Marble Marble::operator-(const Marble& rhs) {
    Marble temp;
    return temp;
}