#include <stdio.h>

int main() {
    int a, b, c, d;
    printf("Enter IP address (format: a.b.c.d): ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    if (a >= 0 && a <= 255) {
        if (a >= 0 && a <= 127) {
            printf("Class A\n");
            printf("Network ID: %d.0.0.0\n", a);
            printf("Host ID: 0.%d.%d.%d\n", b, c, d);
        } else if (a >= 128 && a <= 191) {
            printf("Class B\n");
            printf("Network ID: %d.%d.0.0\n", a, b);
            printf("Host ID: 0.0.%d.%d\n", c, d);
        } else if (a >= 192 && a <= 223) {
            printf("Class C\n");
            printf("Network ID: %d.%d.%d.0\n", a, b, c);
            printf("Host ID: 0.0.0.%d\n", d);
        } else if (a >= 224 && a <= 239) {
            printf("Class D (Multicast)\n");
            printf("Multicast Address: %d.%d.%d.%d\n", a, b, c, d);
        } else {
            printf("Class E (Reserved)\n");
            printf("Reserved Address: %d.%d.%d.%d\n", a, b, c, d);
        }
    } else {
        printf("Invalid IP address\n");
    }

    return 0;
}
