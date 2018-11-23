#include <iostream>
#include <string>

#define WHITESPACE ' '

using namespace std;

int myAtoi(string str) {
    int i(0);
    while (i < str.size()) {
        if (str[i] == WHITESPACE)
            ++i;
        else if (str[i] != WHITESPACE)
            break;
    }
    int integer(0);

    if (0 <= str[i] - '0' && str[i] - '0' <= 9) {   /**/
        while (0 <= str[i] - '0' && str[i] - '0' <= 9 && i < str.size()) {
            if (integer <= 214748363 || (integer == 214748364 && str[i] - '0' <= 7)) {
                integer = integer * 10 + str[i] - '0';
                ++i;
            } else
                return INT_FAST32_MAX;
        }
        return integer;
    }

    if (str[i] == '+') {
        ++i;
        if (0 <= str[i] - '0' && str[i] - '0' <= 9) {
            while (0 <= str[i] - '0' && str[i] - '0' <= 9 && i < str.size()) {
                if (integer <= 214748363 || (integer == 214748364 && str[i] - '0' <= 7)) {
                    integer = integer * 10 + str[i] - '0';
                    ++i;
                } else
                    return INT_FAST32_MAX;
            }
            return integer;
        } else
            return 0;
    }

    if (str[i] == '-') {
        ++i;
        if (0 <= str[i] - '0' && str[i] - '0' <= 9) {
            while (0 <= str[i] - '0' && str[i] - '0' <= 9 && i < str.size()) {
                if (integer <= 214748363 || (integer == 214748364 && str[i] - '0' <= 7)) {
                    integer = integer * 10 + str[i] - '0';
                    ++i;
                } else
                    return INT_FAST32_MIN;
            }
            return 0 - integer;
        } else
            return 0;
    }
    
    return 0;
}
int main() {
    string str("-91283472332");
    int integer = myAtoi(str);
    cout << integer;
    return 0;
}
