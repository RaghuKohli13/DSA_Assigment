//Q4(A)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);

    s1 = s1 + s2; // concatenate
    cout << "Concatenated String: " << s1 << endl;
    return 0;
}

//Q4(B)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    reverse(s.begin(), s.end());
    cout << "Reversed String: " << s << endl;
    return 0;
}

//Q4(C)

include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string s, result = "";
    cout << "Enter a string: ";
    getline(cin, s);

    for (char c : s) {
        if (!isVowel(c)) result += c;
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}

//Q4(D)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // clear buffer

    string arr[n];
    cout << "Enter strings:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    sort(arr, arr + n);

    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
