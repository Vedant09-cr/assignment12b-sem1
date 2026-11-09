#include <stdio.h>

struct Permission {
    unsigned int read : 1;
    unsigned int write : 1;
    unsigned int execute : 1;
    unsigned int admin : 1;
};

void displayPermissions(struct Permission p)
{
    printf("Permissions string: ");
    printf("%c", p.read ? 'r' : '-');
    printf("%c", p.write ? 'w' : '-');
    printf("%c", p.execute ? 'x' : '-');
    printf("%c\n", p.admin ? 'A' : '-');
}

int main()
{
    struct Permission perm;
    unsigned int r, w, x, a;

    printf("Enter permissions (read write execute admin as 0 or 1): ");
    scanf("%u %u %u %u", &r, &w, &x, &a);

    if (r > 1 || w > 1 || x > 1 || a > 1)
    {
        printf("Invalid input! Values must be 0 or 1.\n");
        return 0;
    }

    perm.read = r;
    perm.write = w;
    perm.execute = x;
    perm.admin = a;

    printf("\nPermission Details:\n");
    printf("Read    : %u\n", perm.read);
    printf("Write   : %u\n", perm.write);
    printf("Execute : %u\n", perm.execute);
    printf("Admin   : %u\n", perm.admin);

    displayPermissions(perm);
    printf("Size of struct Permission: %zu bytes\n", sizeof(perm));

    return 0;
}
