#include <iostream>
using namespace std;


int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << "Adding two integers: " << add(3, 4) << endl;          
    cout << "Adding two floats: " << add(2.5f, 4.5f) << endl;   
    cout << "Adding three integers: " << add(1, 2, 3) << endl;     
    return 0;
}
