#include "std_lib_facilities.h"

/*
 * Find prime numbers.
 * primes
 */


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
    for (int p: primes) {
        if (num == p)   return true;
        if (num > p)    return false;
    }
    return false;
}


int main() {
    vector<int> primes(0);
    for (int n = 1; n <= 100; ++n) {
        
    }

}

