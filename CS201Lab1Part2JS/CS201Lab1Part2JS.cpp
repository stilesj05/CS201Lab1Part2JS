// CS201Lab1Part2JS.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cmath>   // For sqrt() and pow()
using namespace std;

int main() {
    //set up variables used
    string in1, in2, in3, in4;
    int x1, y1, x2, y2;
    float dist1, dist2;
    char choice;

    //get choice from user ‘e’ to enter values or ’g’ to generate values using random values
    cout << "How would you like to get the 4 values? (e for enter values, g for generate random values): ";
    cin >> choice;

    //if choice is e, get input
    if (choice == 'e') {
        cout << "Please enter 4 values (x1 y1 x2 y2): ";
        cin >> in1 >> in2 >> in3 >> in4;

        //verify input
        try {
            //strings to integers
            x1 = stoi(in1);
            y1 = stoi(in2);
            x2 = stoi(in3);
            y2 = stoi(in4);

            //check in values are in range
            if (x1 < -10 || x1 > 10 || y1 < -10 || y1 > 10 || x2 < -10 || x2 > 10 || y2 < -10 || y2 > 10) {
                cout << "Error: Values must be between -10 and 10." << endl;
                return 1;
            }
        }
        catch (...) {
            //use catch for exceptions. if input is not numeric, show error and end program
            cout << "Error: All inputs must be numeric." << endl;
            return 1;
        }
    }
    else if (choice == 'g') {
        //if choice is 'g', generate 4 random numbers between -10 & 10
        srand(time(0)); //seed the random number generator
        x1 = rand() % 21 - 10; //generate numbers between -10 and 10
        y1 = rand() % 21 - 10;
        x2 = rand() % 21 - 10;
        y2 = rand() % 21 - 10;

        // Print the generated values
        cout << "Generated values are: " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    else {
        // If the choice is neither 'e' nor 'g', print error and end program
        cout << "Invalid choice. Please enter 'e' or 'g'." << endl;
        return 1;
    }

    // Print both points
    cout << "Point 1: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Point 2: (" << x2 << ", " << y2 << ")" << endl;

    // Calculate distances from the origin
    dist1 = sqrt(x1 * x1 + y1 * y1); // Distance of the first point
    dist2 = sqrt(x2 * x2 + y2 * y2); // Distance of the second point

    // Determine which point is closer and print
    if (dist1 < dist2) {
        cout << "Point (" << x1 << ", " << y1 << ") is closer to the origin." << endl;
    }
    else if (dist2 < dist1) {
        cout << "Point (" << x2 << ", " << y2 << ") is closer to the origin." << endl;
    }
    else {
        cout << "Both points are equidistant from the origin." << endl;
    }

    return 0;
}
