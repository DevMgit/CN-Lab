#include <stdio.h>
#include <string.h>

void binarySum(char a[], char b[], char result[], int len) {
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int bitA = a[i] - '0';
        int bitB = b[i] - '0';
        int sum = bitA + bitB + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    if (carry) {
        char carryBlock[10] = "00000001";
        binarySum(result, carryBlock, result, len);
    }
}

int main() {
    char msg[100], block[10], sum[10] = "00000000", checksum[10];
    int blockLen, i = 0;

    printf("Enter binary message: ");
    scanf("%s", msg);
    printf("Block size: ");
    scanf("%d", &blockLen);

    while (msg[i]) {
        strncpy(block, &msg[i], blockLen);
        block[blockLen] = '\0';
        binarySum(sum, block, sum, blockLen);
        i += blockLen;
    }

    for (i = 0; i < blockLen; i++)
        checksum[i] = (sum[i] == '0') ? '1' : '0';
    checksum[blockLen] = '\0';

    printf("Checksum: %s\n", checksum);
    return 0;
}
