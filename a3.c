#include <stdio.h>

enum Type {
    INT_VALUE,
    FLOAT_VALUE,
    CHAR_VALUE
};

union Data {
    int i;
    float f;
    char c;
};

struct TaggedValue {
    enum Type tag;
    union Data val;
};

void printValue(struct TaggedValue tv)
{
    switch (tv.tag)
    {
        case INT_VALUE:
            printf("Integer value: %d\n", tv.val.i);
            break;
        case FLOAT_VALUE:
            printf("Float value: %.2f\n", tv.val.f);
            break;
        case CHAR_VALUE:
            printf("Character value: %c\n", tv.val.c);
            break;
        default:
            printf("Unknown type\n");
            break;
    }
}

int main()
{
    struct TaggedValue v1, v2, v3;

    v1.tag = INT_VALUE;
    v1.val.i = 105;

    v2.tag = FLOAT_VALUE;
    v2.val.f = 98.6f;

    v3.tag = CHAR_VALUE;
    v3.val.c = 'Z';

    printValue(v1);
    printValue(v2);
    printValue(v3);

    return 0;
}
