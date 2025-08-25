#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
    string str = "thapar";
    string str1 = "Kavya";
    string str2 = "Singal";
    
    //a.Concatenate
    str1 += str2;  
    cout << "Concatenated string: " << str1 << endl;

    //b.Reverse
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;

    //c.Delete all vowels
    string result = "";
    for (char c : str) {
        if (!(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')) {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;

    //d.Sort the strings
    sort(str.begin(), str.end());
    cout << "Sorted string: " << str << endl;

    //e. Convert a char from ucase to lcase
    char c ='A';
    cout << "Lowercase: " << char(tolower(c)) << endl;

    return 0;
}

