#include <iostream>
#include <cmath>

using namespace std;

// Function prototypes
void menu();
double calculateSquareArea(double side);
double calculateCircleArea(double radius);
double calculateTriangleArea(double base, double height);

int main() {
    int choice;
    double side, radius, base, height;
    
    do {
        // Display the menu
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                // Calculate area of a square
                cout << "Enter the side length of the square: ";
                cin >> side;
                cout << "Area of the square = " << calculateSquareArea(side) << endl;
                break;
            
            case 2:
                // Calculate area of a circle
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                cout << "Area of the circle = " << calculateCircleArea(radius) << endl;
                break;

            case 3:
                // Calculate area of a right triangle
                cout << "Enter the base of the right triangle: ";
                cin >> base;
                cout << "Enter the height of the right triangle: ";
                cin >> height;
                cout << "Area of the right triangle = " << calculateTriangleArea(base, height) << endl;
                break;

            case 4:
                // Quit the program
                cout << "Quitting the program..." << endl;
                break;

            default:
                // Handle invalid menu choice
                cout << "Error: Invalid choice. Please choose a valid option from the menu." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void menu() {
    cout << "Program to calculate areas of objects\n";
    cout << "1 -- Square\n";
    cout << "2 -- Circle\n";
    cout << "3 -- Right Triangle\n";
    cout << "4 -- Quit\n";
    cout << "Please enter your choice: ";
}

// Function to calculate the area of a square
double calculateSquareArea(double side) {
    return side * side;
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a right triangle
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}
