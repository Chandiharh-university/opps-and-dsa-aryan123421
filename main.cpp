#include <iostream>
using namespace std;
class Number {
private:
    double value; 
public:
    Number(double v = 0) : value(v) {}
    void setValue(double v) {
        value = v;
    }
    double getValue() const {
        return value;
    }
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }
    friend ostream& operator<<(ostream& out, const Number& num) {
        out << num.value;
        return out;
    }
};

int main() {
    Number num1, num2, sum;
    cout << "Enter the first number (integer, float, or fraction like 1/2): ";
    string input1;
    cin >> input1;

    cout << "Enter the second number (integer, float, or fraction like 3/4): ";
    string input2;
    cin >> input2;
    if (input1.find('/') != string::npos) { // Fraction format
        int numerator1 = stoi(input1.substr(0, input1.find('/')));
        int denominator1 = stoi(input1.substr(input1.find('/') + 1));
        num1.setValue(static_cast<double>(numerator1) / denominator1);
    } else { // Integer or float
        num1.setValue(stod(input1));
    }

    if (input2.find('/') != string::npos) { // Fraction format
        int numerator2 = stoi(input2.substr(0, input2.find('/')));
        int denominator2 = stoi(input2.substr(input2.find('/') + 1));
        num2.setValue(static_cast<double>(numerator2) / denominator2);
    } else { // Integer or float
        num2.setValue(stod(input2));
    } 
    sum = num1 + num2;
    cout << "The sum is: " << sum << endl;

    return 0;
}
