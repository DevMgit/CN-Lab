#include <stdio.h>
#include <string.h>

int main() {
    char input[50], stuffed[100] = "01111110"; // Start flag
    int i, count = 0;

    printf("Enter bit stream: ");
    scanf("%s", input);

    for (i = 0; input[i]; i++) {
        stuffed[strlen(stuffed)] = input[i];
        if (input[i] == '1') {
            count++;
            if (count == 5) {
                strcat(stuffed, "0");
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    strcat(stuffed, "01111110"); // End flag
    printf("Bit Stuffed: %s\n", stuffed);
    return 0;
}
