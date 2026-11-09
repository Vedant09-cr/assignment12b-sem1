#include <stdio.h>

enum Result {
    FAIL,
    PASS,
    DISTINCTION
};

enum Result getResult(float avg)
{
    if (avg >= 75.0f)
        return DISTINCTION;
    else if (avg >= 40.0f)
        return PASS;
    else
        return FAIL;
}

int main()
{
    float m1, m2, m3;
    printf("Enter marks in three subjects: ");
    scanf("%f %f %f", &m1, &m2, &m3);

    float avg = (m1 + m2 + m3) / 3.0f;
    printf("Average marks: %.2f\n", avg);

    enum Result res = getResult(avg);

    switch (res)
    {
        case DISTINCTION:
            printf("Result: DISTINCTION (Value = %d)\n", res);
            break;
        case PASS:
            printf("Result: PASS (Value = %d)\n", res);
            break;
        case FAIL:
            printf("Result: FAIL (Value = %d)\n", res);
            break;
    }

    return 0;
}
