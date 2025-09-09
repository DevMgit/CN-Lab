#include <stdio.h>

unsigned short checksum(unsigned short *d, int n, int verify) {
    unsigned int s = 0;
    for (int i = 0; i < n; i++) s += d[i];
    while (s >> 16) s = (s & 0xFFFF) + (s >> 16);
    return verify ? s : ~s & 0xFFFF;   // if verify==1 → return sum, else checksum
}

int main() {
    int n; unsigned short w[25];
    printf("Enter the no. of 16-bit words: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("word%d: ", i + 1);
        scanf("%hx", &w[i]);
    }

    unsigned short cs = checksum(w, n, 0);
    printf("Calculated checksum: 0x%X\n", cs);

    w[n] = cs;  // append checksum

    printf("%s\n", checksum(w, n + 1, 1) == 0xFFFF ? "No Error." : "Error Detected.");
}
