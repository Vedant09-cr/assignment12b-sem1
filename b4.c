#include <stdio.h>

struct OrdinaryFlags {
    unsigned int flag1;
    unsigned int flag2;
    unsigned int flag3;
    unsigned int flag4;
};

struct BitFlags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int flag4 : 1;
};

int main()
{
    struct OrdinaryFlags o;
    struct BitFlags b;

    o.flag1 = 1;
    o.flag2 = 0;
    o.flag3 = 1;
    o.flag4 = 1;

    b.flag1 = 1;
    b.flag2 = 0;
    b.flag3 = 1;
    b.flag4 = 1;

    printf("=== Memory Comparison ===\n");
    printf("Size of struct OrdinaryFlags : %zu bytes (4 * 4 bytes)\n", sizeof(struct OrdinaryFlags));
    printf("Size of struct BitFlags      : %zu bytes (packed into 1 word)\n", sizeof(struct BitFlags));

    printf("\nOrdinary values: %u %u %u %u\n", o.flag1, o.flag2, o.flag3, o.flag4);
    printf("Bit-field values: %u %u %u %u\n", b.flag1, b.flag2, b.flag3, b.flag4);

    printf("\nMemory saved: %zu bytes (%.1f%% reduction)\n",
           sizeof(struct OrdinaryFlags) - sizeof(struct BitFlags),
           ((float)(sizeof(struct OrdinaryFlags) - sizeof(struct BitFlags)) / sizeof(struct OrdinaryFlags)) * 100.0f);

    printf("Note: Actual size and memory layout depend on compiler alignment and architecture.\n");

    return 0;
}
