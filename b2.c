#include <stdio.h>

struct DeviceStatus {
    unsigned int power : 1;
    unsigned int mode : 2;
    unsigned int error : 1;
    unsigned int battery : 4;
};

int main()
{
    struct DeviceStatus dev;
    unsigned int p, m, e, b;

    printf("Enter power (0-1): ");
    scanf("%u", &p);

    printf("Enter mode (0-3): ");
    scanf("%u", &m);

    printf("Enter error status (0-1): ");
    scanf("%u", &e);

    printf("Enter battery level (0-15): ");
    scanf("%u", &b);

    if (p > 1 || m > 3 || e > 1 || b > 15)
    {
        printf("Validation error: One or more inputs exceed allowed bit-width limits!\n");
        return 0;
    }

    dev.power = p;
    dev.mode = m;
    dev.error = e;
    dev.battery = b;

    printf("\n--- Packed Device Status ---\n");
    printf("Power   : %u (%s)\n", dev.power, dev.power ? "ON" : "OFF");
    printf("Mode    : %u\n", dev.mode);
    printf("Error   : %u (%s)\n", dev.error, dev.error ? "YES" : "NO");
    printf("Battery : %u / 15\n", dev.battery);
    printf("Total size of packed struct: %zu bytes\n", sizeof(dev));
    printf("Note: Bit-field packing order and padding are implementation-defined by the compiler.\n");

    return 0;
}
