/*
 * FizzBuzz demo with
 * added formatting.
*/


#include <iostream>

// Condensing elements
using std::cout, std::endl;

int main() {


    // Variable setup
    int lastNum = 200;
    int rowLength = 7;
    int foo = 1;
    int bar = 1;

    // Double iterative while loops for limited-length rows
    while (foo < lastNum) {
        while (bar <= rowLength && foo < lastNum){
            if (foo%15 == 0) {
                cout << "FizzBuzz, ";
            }
            else if (foo%3 == 0) {
                cout << "Fizz, ";
            }
            else if (foo%5 == 0) {
                cout << "Buzz, ";
            }
            else {
                cout << foo << ", ";
            }
            foo++; bar++;
        }
        if (foo != lastNum) { cout << endl; }
        bar = 0;
    }

    // Used for the last number, to add a period instead of a comma
    if (lastNum%15 == 0) {
        cout << "FizzBuzz." << endl;
    }
    else if (lastNum%3 == 0) {
        cout << "Fizz." << endl;
    }
    else if (lastNum%5 == 0) {
        cout << "Buzz." << endl;
    }
    else {
        cout << lastNum << "." << endl;
    }
}
