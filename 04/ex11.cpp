#include "std_lib_facilities.h"

/*
 * Find prime numbers.
 * primes
 */

/*
void find_primes(int num, vector<int> primes) {
    int last = 0;
    if (primes.size() > 0)
        last = primes[primes.size() - 1];
    if (num <= last)
        return;

    for (; last <= num; ++last) {
        if (num <= primes[primes.size() -1])
        return false;

}


bool is_prime(int num, vector<int> primes) {
    if (num == 1)   return false;
    find_primes(num, primes);
    return false;
}
*/


bool is_prime_trial_division(int num, vector<int> primes) {
    if (num < 2)    return false;
    if (num == 2)   return true;

    int begin = 2;
    int end = sqrt(num);
    for (int num2 = begin; num2 <= end; ++num2) {
        if (num % num2 == 0)
            return false;
    }
    return true;
}


bool is_prime_factored(int num, vector<int> primes) {
    if (num < 2)    return false;
    if (num == 2)   return true;

    for (int p: primes) {
        if (num == p)   return true;
        if (p > num)    return false;
        if (num % p == 0)    return false;
    }

// complete the test if: num > last of primes

    return false;
}


int main() {
    vector<int> primes(0);
    for (int num = 1; num <= 100; ++num) {
        cout << num << "\t" << is_prime_trial_division(num, primes) << "\n";
    }

}

