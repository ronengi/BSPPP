/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void print(char* s);


char* strdup(const char*s) {
    int len = 0;
    for(; s[len] != '\0'; ++len);
    char* copy = new char[len + 1];
    for(int i = 0; i < len; ++i)
        copy[i] = s[i];
    copy[len] = '\0';
    return copy;
}


void main_04() {

    char *s = new char[15] {'h', 'e', 'l', 'L', 'o', '\0'};
    print(s);

    char* copy =strdup(s);
    print(copy);
    delete[] copy;

    delete[] s;
}