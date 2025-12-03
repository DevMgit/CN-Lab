#include <stdio.h>
#include <string.h>

#define F '$'
#define E '@'

int main() {
    char in[50], s[100], d[100];
    int i, j;

    scanf("%s", in);

    // Stuff
    s[0] = F; j = 1;
    for (i = 0; in[i]; i++) {
        if (in[i] == F || in[i] == E) s[j++] = E;
        s[j++] = in[i];
    }
    s[j++] = F; s[j] = 0;

    printf("Stuffed: %s\n", s);

    // De-stuff
    for (i = 1, j = 0; s[i] != F; i++) {
        if (s[i] == E) i++;
        d[j++] = s[i];
    }
    d[j] = 0;

    printf("Destuffed: %s\n", d);
}
