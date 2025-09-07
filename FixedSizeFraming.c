#include <stdio.h>
#include <string.h>
#define SIZE 5

int main() {
    char msg[100];
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';

    printf("Fixed Frames:\n");
    for (int i = 0; msg[i]; i++) {
        if (i % SIZE == 0) printf("\nFrame: ");
        printf("%c", msg[i]);
    }
    return 0;
}
