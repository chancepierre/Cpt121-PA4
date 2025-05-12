#include "header.h"

int menu()
{
    int c;

    while (1)
    {
        printf("\n");
        printf("\n1 -- new game \n");
        printf("2 --- rules\n");
        printf("3 ---- exit game\n");

        printf("\n");

        printf("Enter a no. 1-3 :");

        scanf("%d", &c);

        switch (c)
        {

        case 1:

            main_game_logic();

            break;

        case 2:

            print_game_rules();

            break;

        case 3:

            printf("Exiting see byeeee! \n");

            return 0;

        default:

            printf("Invalid choice bro. enter 1,2 or 3.\n");
        }
    }
}
void print_game_rules(void)
{

    printf("Yo welcome to Craps, Here are the rules are If the sum is 7 or 11 on the first throw, you win\n");

    printf("If the sum is 2, 3, or 12 on the first throw, you lose. and if the sum is 4, 5, 6, 8, 9, or 10 on the first throw, that becomes your point\n");

    printf("To win the game, you gotta roll the dice again until you make your point. You lose if you roll a 7 before making your point\n");

}

double get_bank_balance(void)
{
    double balance;

    printf("Put in youre bank balance: ");

    scanf("%lf", &balance);

    return balance;
}

int check_wager_amount(double wager, double balance)
{
    if (wager < balance)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int roll_die(void)
{
    return (rand() % 6) + 1;
}

int calculate_sum_dice(int die1_value, int die2_value)
{
    return die1_value + die2_value;
}

int is_win_loss_or_point(int sum_dice)
{
    if (sum_dice == 7 || sum_dice == 11)
    {
        return 1;
    }
    else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int is_point_loss_or_neither(int sum_dice, int point_value)
{
    if (sum_dice == point_value)
    {
        return 1;
    }
    else if (sum_dice == 7)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
    if (add_or_subtract == 1)
    {
        return bank_balance + wager_amount;
    }
    else if (add_or_subtract == 0)
    {
        return bank_balance - wager_amount;
    }
    else
    {
        return bank_balance;
    }
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
    printf("No. of rolls: %d\n", number_rolls);

    printf("Intial balance: %.2lf\n", initial_bank_balance);

    printf("Current balance: %.2lf\n", current_bank_balance);


    if (number_rolls == 1)
    {
        printf("Let's see if you can make your point...\n");
    }

    else if (number_rolls > 1 && current_bank_balance > initial_bank_balance)
    {
        printf("Your up right now!,will cash in.....\n");
    }

    else if (number_rolls > 1 && current_bank_balance < initial_bank_balance)
    {
        printf("Damn sorry, you lost this one!\n");
    }

    else if (win_loss_neither == 1)
    {
        printf("Nice dawg, you got this!\n");
    }

    else if (win_loss_neither == 0)
    {
        printf("Me personally I would go for it twin!\n");
    }

}

void main_game_logic(void)
{
    srand(time(NULL));

    double initial_bank_balance = get_bank_balance();

    double curr_balance = initial_bank_balance;

    printf("Your intial bank balance : $ % .2lf\n", initial_bank_balance);

    int number_rolls = 0;

    int point = 0;

    int result = 0;

    while (1)
    {
        double wager;

        printf("Enter your wager buddy. goodluck: $");

        scanf("%lf", &wager);

        if (check_wager_amount(wager, curr_balance))
        {
            printf("Your wager is valid. You're betting $%.2lf.\n", wager);

            int dice1_val = roll_die();

            int dice2_val = roll_die();

            int sum_dice = calculate_sum_dice(dice1_val, dice2_val);

            printf("You rolled a %d and %d, total: %d.\n", dice1_val, dice2_val, sum_dice);


            if (point == 0)
            {

                result = is_win_loss_or_point(sum_dice);

                if (result == 1)
                {

                    printf("congrats twin you won. we gotta share that!\n");

                    curr_balance = adjust_bank_balance(curr_balance, wager, 1);
                }
                else if (result == 0)
                {

                    printf("Oop you lost maybe next time.CRAPS");

                    curr_balance = adjust_bank_balance(curr_balance, wager, 0);
                }
                else 
                {
                    printf("The point is %d. Keep going twin..... \n", sum_dice);

                    point = sum_dice;
                }
            }
            else 
            {
                result = is_point_loss_or_neither(sum_dice, point);

                if (result == 1)
                {

                    printf("You made your point twin!\n");

                    curr_balance = adjust_bank_balance(curr_balance, wager, 1);

                    point = 0;
                }
                else if (result == 0)
                {

                    printf("You rolled a 7 and lost bad luck dawg good try though");

                    curr_balance = adjust_bank_balance(initial_bank_balance, wager, 0);

                    point = 0;
                }
                else
                {

                    printf("just continue rolling to make the point twin I know I would.\n");

                }
            }

            number_rolls++;

            chatter_messages(number_rolls, result, initial_bank_balance, curr_balance);


        }
        else
        {

            printf("You don't got money like that bro.That's invalid wager enter your availabe blanace.\n");
        }

    }
}