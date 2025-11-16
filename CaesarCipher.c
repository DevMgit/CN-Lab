#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100];
    int ch, i; 
    printf("1.Encrypt  2.Decrypt: ");
    scanf("%d", &ch);
    scanf("%s", s);

    for(i = 0; s[i]; i++){
        if(isupper(s[i]))
            s[i] = ( (s[i] - 'A' + (ch==1?3:-3) + 26 ) % 26 ) + 'A';
        else
            s[i] = ( (s[i] - 'a' + (ch==1?3:-3) + 26 ) % 26 ) + 'a';
    }

    printf("%s", s);
    return 0;
}
