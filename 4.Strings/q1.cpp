#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long long num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> numbers(n);
    long long q = 1e18;  // Initialize q to a very large number
    
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] < q) {
            q = numbers[i];
        }
    }
    
    long long p = q + 1;
    while (true) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (numbers[i] != q && p % numbers[i] != q) {
                valid = false;
                break;
            }
        }
        
        if (valid && isPrime(p)) {
            cout << p << endl;
            return 0;
        }
        
        p++;
    }
    
    cout << "None" << endl;
    
    return 0;
}