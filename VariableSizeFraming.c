#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    int pos = 0, len, frameSize;

    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';
    len = strlen(msg);

    while (pos < len) {
        printf("Enter frame size (%d left): ", len - pos);
        scanf("%d", &frameSize);
        if (frameSize <= 0 || frameSize > len - pos) continue;

        printf("Frame [%d]: ", frameSize);
        for (int i = 0; i < frameSize; i++)
            printf("%c", msg[pos + i]);
        printf("\n");
        pos += frameSize;
    }
    return 0;
}
