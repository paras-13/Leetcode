// Convert Roman to Integer
#include <iostream>
#include <unordered_map>
using namespace std;
int romanToInteger(string roman) {
    unordered_map <char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    int number = 0;
    for(int i=0; i<roman.length(); i++){
        if(map[roman[i]] < map[roman[i+1]])
            number -= map[roman[i]];
        else
            number += map[roman[i]];
    }
    return number;
}
int main() {
    string roman;
    cout << "Enter a roman number: ";
    cin >> roman;
    cout << "Converting roman number to integer value: ";
    cout << romanToInteger(roman);
}
