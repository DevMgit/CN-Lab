#include <stdio.h>
#include <string.h>
#define FLAG '$'
#define ESC '@'

int main() {
    char data[25], stuffed[50], destuffed[50];
    int i, j;

    printf("Enter message: ");
    scanf("%s", data);

    // Stuffing
    j = 0;
    stuffed[j++] = FLAG;
    for (i = 0; data[i]; i++) {
        if (data[i] == FLAG || data[i] == ESC)
            stuffed[j++] = ESC;
        stuffed[j++] = data[i];
    }
    stuffed[j++] = FLAG;
    stuffed[j] = '\0';

    printf("Stuffed: %s\n", stuffed);

    // Destuffing
    j = 0;
    for (i = 1; stuffed[i] != FLAG; i++) {
        if (stuffed[i] == ESC)
            i++;
        destuffed[j++] = stuffed[i];
    }
    destuffed[j] = '\0';

    printf("Destuffed: %s\n", destuffed);
    return 0;
}
