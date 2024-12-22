#include <iostream>
#include <map>
using namespace std;

int main() {
    int arr[8];

    cout << "Enter 8 elements: ";
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    map<int, int> frequency;
    for (int i = 0; i < 8; i++) {
        frequency[arr[i]]++;
    }

    cout << "Element frequencies:" << endl;
    for (auto pair : frequency) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
