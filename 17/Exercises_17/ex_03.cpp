/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void print(char* s);


void to_lower(char* s) {
    char dd = 'A' - 'a';

    for(int i = 0; s[i] != '\0'; ++i) {
        if('A' <= s[i] && s[i] <= 'Z') {
            s[i] -= dd;
        }
    }
}


void main_03() {

    char *s = new char[15] {'h', 'e', 'l', 'L', 'o', '\0'};
    print(s);

    to_lower(s);
    print(s);

    delete[] s;
}