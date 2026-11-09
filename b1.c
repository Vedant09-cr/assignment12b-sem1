#include <stdio.h>

struct Flags {
    unsigned int isOn : 1;
    unsigned int isReady : 1;
};

int main()
{
    struct Flags f;
    unsigned int inputOn, inputReady;

    printf("Enter value for isOn (0 or 1): ");
    scanf("%u", &inputOn);

    printf("Enter value for isReady (0 or 1): ");
    scanf("%u", &inputReady);

    if (inputOn > 1 || inputReady > 1)
    {
        printf("Invalid input! Values must be 0 or 1.\n");
        return 0;
    }

    f.isOn = inputOn;
    f.isReady = inputReady;

    printf("\nFlags status:\n");
    printf("isOn    = %u\n", f.isOn);
    printf("isReady = %u\n", f.isReady);
    printf("Size of struct Flags = %zu bytes\n", sizeof(f));

    return 0;
}
