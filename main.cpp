#include <iostream>
#include <cctype>

using namespace std;

string encrypt_caesar(string str , int x) {
    for(int i = 0; i < str.length(); i++) {
        if(isupper(str[i]) && str[i] + x > 'Z') str[i] -= 26 - x;
        if(isupper(str[i]) && str[i] + x < 'A') str[i] += 26 + x;
        else if(isupper(str[i])) str[i] += x;

        if(islower(str[i]) && str[i] + x > 'z') str[i] -= 26 - x;
        else if(islower(str[i]) && str[i] + x < 'a') str[i] += 26 + x;
        else if(islower(str[i])) str[i] += x;
    }
    return str;
}

string decrypt_caesar(string str , int x){
    return encrypt_caesar(str , -x);
}

int main() {
    string str;
    int x;
    int answer;

    cout << "Enter string: ";
    getline(cin , str);
    cout << "Enter the number: ";
    cin >> x;

    cout << "You want encrypt or decrypt the massage? \nEnter ( 1 - encrypt , 2- decrypt): ";
    cin >> answer;

    if(answer == 1) cout << endl << encrypt_caesar(str , x) << endl;
    if(answer == 2) cout << endl << decrypt_caesar(str , x) << endl;
}
