#define _CRT_SECURE_NO_WARNINGS

#ifndef PASSIGNMENT_H
#define PASSIGNMENT_H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
void print_game_rules(void);
int menu();
void main_game_logic(void);
double get_bank_balance(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

#endif