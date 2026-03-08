// COMSC-200 | Assignment 3A | Loma Kim
#include <iostream>
using namespace std;

class Marble {
    private:
    static unsigned int count = 0;
    unsigned int number;
    double radius;

    public:
    Marble(double);
    //Accessor functions
    unsigned int getNumber() const { return number; }
    double getRadius() const { return radius; }
    //Mutator functions
    void setRadius(double r) { radius = r; }

    double getVolume() { return (4/3 * 3.14159 * r); }

};


int main() {
    return 0;
}


/*CONSTRUCTOR - default constructor which can accept an argument:
    - increments count
    - assigns count to marble number
    - assigns argument to radius                                 */
Marble::Marble(double r = 0){
    number = ++count;
    radius = r;
}