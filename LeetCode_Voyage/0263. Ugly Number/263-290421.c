// Hao Ren
// 29 April, 2021
// 263. Ugly Number

bool isUgly(int n){
    if (n < 1) return false;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
}
