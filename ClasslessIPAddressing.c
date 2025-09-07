#include <stdio.h>

int main() {
    int a, b, c, d, prefix;
    unsigned int ip, mask, network, broadcast, firstHost, lastHost;

    printf("Enter IP address and prefix (e.g., 192.168.1.1 24): ");
    scanf("%d.%d.%d.%d %d", &a, &b, &c, &d, &prefix);

    if (prefix < 0 || prefix > 32) {
        printf("Invalid prefix\n");
        return 1;
    }

    ip = (a << 24) | (b << 16) | (c << 8) | d;
    mask = prefix == 0 ? 0 : (~0U << (32 - prefix));
    network = ip & mask;
    broadcast = ip | ~mask;

    if (prefix == 32) {
        firstHost = lastHost = ip;
    } else if (prefix == 31) {
        firstHost = network;
        lastHost = broadcast;
    } else {
        firstHost = network + 1;
        lastHost = broadcast - 1;
    }

    printf("Subnet Mask: %u.%u.%u.%u\n",
           (mask >> 24) & 0xFF, (mask >> 16) & 0xFF,
           (mask >> 8) & 0xFF, mask & 0xFF);

    printf("First Host: %u.%u.%u.%u\n",
           (firstHost >> 24) & 0xFF, (firstHost >> 16) & 0xFF,
           (firstHost >> 8) & 0xFF, firstHost & 0xFF);

    printf("Last Host: %u.%u.%u.%u\n",
           (lastHost >> 24) & 0xFF, (lastHost >> 16) & 0xFF,
           (lastHost >> 8) & 0xFF, lastHost & 0xFF);

    return 0;
}
