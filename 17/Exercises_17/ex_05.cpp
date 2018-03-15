/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void print(char* s);


char* findx(const char* cs, const char* cx) {
    if(!*cx || !*cs)
        return nullptr;

    char* s = const_cast<char*>(cs);
    char* x = const_cast<char*>(cx);

    while (*s) {
        if(*s == *x) {
            char* s1 = s;
            char* x1 = x;
            while(*x1 && *s1 && *x1 == *s1) {
                ++x1;
                ++s1;
            }
            if(!*x1)
                return s;
        }
        ++s;
    }
    return nullptr;
}

void main_05() {

    char *s = new char[15] {'h', 'e', 'l', 'L', 'o', '\0'};
    print(s);

    char *x = new char[15] {'e', 'l', 'L', '\0'};
    print(x);

    char *p = findx(s, x);
    if(p)
        print(p);

    delete[] x;
    delete[] s;
}