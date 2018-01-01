#include <iostream>
#include <iomanip>

using namespace std;


int randint(int max) {
  return rand() % (max + 1);
}

string rnd_str(int l) {
  string str = "";
  int rnd = randint(l);
  for (; rnd > 0; --rnd)
    str += 'a';
  return str;
}


int main() {
    /* drill 1-7 */
    int birth_year = 1970;
    cout << showbase;
    cout << "decimal:    \t" << dec << birth_year << "\n";
    cout << "hexadecimal:\t" << hex << birth_year << "\n";
    cout << "octal:      \t" << oct << birth_year << "\n";
    cout << dec;

    /* drill 8 */
    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    /* drill 9 */
    cout << setprecision(9);
    cout << defaultfloat << 1234567.89 << "\n";
    cout << fixed        << 1234567.89 << "\n";
    cout << scientific   << 1234567.89 << "\n";

    /* drill 10 */
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";
    cout << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << setw(15) << rnd_str(10) << " | " << "\n";

    cout << "\n";
}