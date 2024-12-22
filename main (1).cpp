#include <iostream>
using namespace std;

void passByValue(int value) { value += 10; cout << "Pass-by-value: " << value << endl; }
void passByReference(int& ref) { ref += 10; cout << "Pass-by-reference: " << ref << endl; }

int main() {
    static int staticVar = 5; cout << "Static: " << staticVar++ << endl;
    int* dynamicVar = new int(10); cout << "Dynamic: " << (*dynamicVar)++ << endl; delete dynamicVar;
    int x = 20, y = 30;
    passByValue(x); cout << "After value: " << x << endl;
    passByReference(y); cout << "After reference: " << y << endl;
    return 0;
}
