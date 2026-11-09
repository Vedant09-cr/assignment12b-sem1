#include <stdio.h>

enum Day {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main()
{
    int dayNum;
    printf("Enter day number (1-7): ");
    scanf("%d", &dayNum);

    if (dayNum < 1 || dayNum > 7)
    {
        printf("Invalid day number! Please enter between 1 and 7.\n");
        return 0;
    }

    enum Day today = (enum Day)dayNum;

    switch (today)
    {
        case MONDAY:
            printf("Day %d is Monday\n", today);
            break;
        case TUESDAY:
            printf("Day %d is Tuesday\n", today);
            break;
        case WEDNESDAY:
            printf("Day %d is Wednesday\n", today);
            break;
        case THURSDAY:
            printf("Day %d is Thursday\n", today);
            break;
        case FRIDAY:
            printf("Day %d is Friday\n", today);
            break;
        case SATURDAY:
            printf("Day %d is Saturday\n", today);
            break;
        case SUNDAY:
            printf("Day %d is Sunday\n", today);
            break;
        default:
            printf("Invalid day\n");
            break;
    }

    return 0;
}
