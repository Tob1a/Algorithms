#include <stdio.h>
int main()
{
    int a = 2, b = 1;
    // swap valori senza usare variabile intermezzo trammite la porta XOR
    a = a ^ b; // sarebbe a=^b
    b ^= a;
    a ^= b;
    printf("%d %d", a, b);
    return 0;
}