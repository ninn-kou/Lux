// Hao Ren
// 25 October, 2020
// 1486. XOR Operation in an Array

int xorOperation(int n, int start) {
    int xor = 0;
    for (int i = 0; i < n; i++) {
        xor ^= (start + 2 * i);
    }
    return xor;
}
