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
    Marble(double r = 0.0);
    //ACCESSORS
    unsigned int getNumber() const { return number; }
    double getRadius() const { return radius; }
    //MUTATOR
    void setRadius(double r) { radius = r; }

    double getVolume();

    //OVERLOADED OPERATORS
    Marble operator++();
    Marble operator++(int);
    Marble operator+(const Marble &);
    Marble operator-(const Marble &);

};


int main() {
    const int SIZE = 5;     //Size for marble array
    double input;           //Variable that holds user input 
    Marble mArray[SIZE];    //Marble array

    //Get user input for the radii of the marbles in the array
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter the radius for Marble #" 
             << mArray[i].getNumber() << ": ";
        cin >> input;
        mArray[i].setRadius(input);
    }
    cout << endl;

    //Print the volume of the marbles in the array
    for (int i = 0; i < SIZE; i++) {
        cout << "The volume for Marble #" << mArray[i].getNumber() << ": ";
        cout << mArray[i].getVolume() << endl;
    }
    cout << endl;

    //Increment radii of marbles in the array
    for (int i = 0; i < SIZE; i++) {
        mArray[i]++;
        cout << "Updated marble #" << mArray[i].getNumber() << ": ";
        cout << mArray[i].getRadius() << endl;
    }

    //Create 2 new marbles with the sum and diff of the F/L marbles radii
    Marble m6 = (mArray[0] + mArray[4]);
    Marble m7 = (mArray[0] - mArray[4]);
    //Print radii of the new marbles
    cout << "\nThe radius of the new Marble that is the sum of the "
         << "first and last: " << m6.getRadius() << endl;
    cout << "\nThe radius of the new Marble that is the difference of the "
         << "first and last: " << m7.getRadius() << endl;
    return 0;
}


//STATIC MEMBER VARIABLE - definition; holds marble count
unsigned int Marble::count = 0;

//CONSTRUCTOR - increment count, assign marble number, assign marble radius
Marble::Marble(double r){
    number = ++count;
    radius = r;
}

//getVolume function - returns volume of the marble
double Marble::getVolume(){
    double vol;
    vol = ((4.0 / 3.0) * 3.14159 * (radius * radius * radius));
    return vol;
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
    Marble temp(radius - rhs.radius);   //create temp marble with radii diff
    return temp;            //return temp marble
}