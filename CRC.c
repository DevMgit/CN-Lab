#include <stdio.h>
#include <string.h>

char data[50], generator[20], temp[20];

void XOR() {
    for (int i = 0; i < strlen(generator); i++)
        temp[i] = (temp[i] == generator[i]) ? '0' : '1';
}

void CRC() {
    int i, j;
    for (j = 0; j < strlen(generator); j++)
        temp[j] = data[j];

    for (i = 0; i <= strlen(data) - strlen(generator); i++) {
        if (temp[0] == '1')
            XOR();
        for (j = 0; j < strlen(generator) - 1; j++)
            temp[j] = temp[j + 1];
        temp[j] = data[i + strlen(generator)];
    }
}

int main() {
    strcpy(generator, "1101");  // Example generator polynomial
    printf("Enter data: ");
    gets(data);

    int dataLen = strlen(data);
    int genLen = strlen(generator);

    // Append zeros to data
    for (int i = 0; i < genLen - 1; i++)
        data[dataLen + i] = '0';
    data[dataLen + genLen - 1] = '\0';

    printf("Modified data: %s\n", data);
    CRC();

    printf("CRC Remainder: %s\n", temp);

    // Append remainder to original data
    for (int i = 0; i < genLen - 1; i++)
        data[dataLen + i] = temp[i];

    printf("Transmitted data: %s\n", data);
    return 0;
}
