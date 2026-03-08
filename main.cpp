// COMSC-200 | Assignment 3A | Loma Kim
#include <iostream>
#include <string>
using namespace std;

class Marble {
    private:
    static unsigned int count;  //STATIC MEMBER VARIABLE
    unsigned int number;
    double radius;

    public:
    //CONSTRUCTOR
    Marble(double);
    //ACCESSORS
    unsigned int getNumber() const { return number; }
    double getRadius() const { return radius; }
    //MUTATOR
    void setRadius(double r) { radius = r; }

    double getVolume() { return (4/3 * 3.14159 * radius * radius * radius); }

    //OVERLOADED OPERATORS
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


//STATIC MEMBER VARIABLE - definition; holds marble count
unsigned int Marble::count = 0;

//CONSTRUCTOR - increment count, assign marble number, assign marble radius
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
    Marble temp(radius);    //create temp Marble to hold radius value
    count--;                //decrement count; temp is not a real marble
    radius++;               //increment radius of this Marble
    return temp;            //return original value of this Marble
}

//OVERLOADED ADDITION OPERATOR
Marble Marble::operator+(const Marble& rhs) {
    count--;                //decrements count as temp is not a real marble
    Marble temp(radius + rhs.radius);   //create temp marble with sum of radii
    return temp;            //return temp marble
}

//OVERLOADED SUBTRACTION OPERATOR
Marble Marble::operator-(const Marble& rhs) {
    count--;                //decrements count as temp is not a real marble
    Marble temp(radius - rhs.radius);   //create temp marble with radii minuend
    return temp;            //return temp marble
}