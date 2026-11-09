#include <stdio.h>

enum State {
    IDLE,
    COIN_INSERTED,
    DISPENSE,
    OUT_OF_STOCK
};

enum Command {
    INSERT_COIN,
    SELECT_ITEM,
    DISPENSE_ITEM,
    CANCEL
};

enum State nextState(enum State state, enum Command cmd, int *stock)
{
    switch (state)
    {
        case IDLE:
            if (cmd == INSERT_COIN)
            {
                if (*stock > 0)
                {
                    printf("State: IDLE -> Event: INSERT_COIN -> Next: COIN_INSERTED (Coin accepted)\n");
                    return COIN_INSERTED;
                }
                else
                {
                    printf("State: IDLE -> Event: INSERT_COIN -> Next: OUT_OF_STOCK (Machine empty)\n");
                    return OUT_OF_STOCK;
                }
            }
            printf("State: IDLE -> Invalid command! State remains IDLE\n");
            return IDLE;

        case COIN_INSERTED:
            if (cmd == SELECT_ITEM)
            {
                printf("State: COIN_INSERTED -> Event: SELECT_ITEM -> Next: DISPENSE\n");
                return DISPENSE;
            }
            else if (cmd == CANCEL)
            {
                printf("State: COIN_INSERTED -> Event: CANCEL -> Next: IDLE (Refunded)\n");
                return IDLE;
            }
            printf("State: COIN_INSERTED -> Invalid command! State remains COIN_INSERTED\n");
            return COIN_INSERTED;

        case DISPENSE:
            if (cmd == DISPENSE_ITEM)
            {
                (*stock)--;
                if (*stock > 0)
                {
                    printf("State: DISPENSE -> Event: DISPENSE_ITEM -> Next: IDLE (Item dispensed)\n");
                    return IDLE;
                }
                else
                {
                    printf("State: DISPENSE -> Event: DISPENSE_ITEM -> Next: OUT_OF_STOCK (Item dispensed, stock empty)\n");
                    return OUT_OF_STOCK;
                }
            }
            printf("State: DISPENSE -> Invalid command!\n");
            return DISPENSE;

        case OUT_OF_STOCK:
            printf("State: OUT_OF_STOCK -> Machine is empty!\n");
            return OUT_OF_STOCK;
    }
    return state;
}

int main()
{
    int stock = 1;
    enum State current = IDLE;

    printf("=== Vending Machine State Transitions ===\n\n");
    current = nextState(current, INSERT_COIN, &stock);
    current = nextState(current, SELECT_ITEM, &stock);
    current = nextState(current, DISPENSE_ITEM, &stock);

    current = nextState(current, SELECT_ITEM, &stock);
    current = nextState(current, INSERT_COIN, &stock);

    stock = 5;
    current = IDLE;
    printf("\nRestocked to 5 items.\n");
    current = nextState(current, INSERT_COIN, &stock);
    current = nextState(current, CANCEL, &stock);

    return 0;
}
