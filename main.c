#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 1
#define CPU 2
#define DRAW 3
#define GRASS 0
#define FIRE 1
#define WATER 2

int player_choice;
int cpu_choice;
int winner;
const char* plays[3] = { "Planta", "Fuego", "Agua" };

void init_seed()
{
    srand(time(NULL));
}

void print_instructions()
{
    printf("Bienvenido al juego de planta, fuego, agua \n");
    printf("Elegiras una opcion de entre tres disponibles y lucharas contra la cpu, que escogera otra \n");
    printf("A continuacion te mostrare las opciones que puedes seleccionar \n\n");
    printf("Planta: %d \n", GRASS);
    printf("Fuego: %d \n", FIRE);
    printf("Agua: %d \n", WATER);
    printf("\n");
}

void read_player_choice()
{
    printf("Introduce tu jugada: \n");
    scanf("%d", &player_choice);
}

void print_players_choice()
{
    printf("Has seleccionado %s \n", plays[player_choice]);
}

int check_valid_input()
{
    if(player_choice > 2 || player_choice < 0) return 0;
    return 1;
}

void cpu_play()
{
    int r = rand() % 3;
    cpu_choice = r;
}

void print_cpu_choice()
{
    printf("La cpu ha seleccionado %s \n", plays[cpu_choice]);
}

void check_winner()
{
    if(player_choice == GRASS)
    {
        if(cpu_choice == FIRE)
            winner = CPU;
        else if(cpu_choice == GRASS)
            winner = DRAW;
        else
            winner = PLAYER;
    }
    else if(player_choice == FIRE)
    {
         if(cpu_choice == WATER)
            winner = CPU;
        else if(cpu_choice == FIRE)
            winner = DRAW;
        else
            winner = PLAYER;
    }
    else if(player_choice == WATER)
    {
         if(cpu_choice == GRASS)
            winner = CPU;
        else if(cpu_choice == WATER)
            winner = DRAW;
        else
            winner = PLAYER;
    }
 }

void print_winner()
{
    switch(winner)
    {
        case PLAYER:
            printf("Has ganado el duelo. \n");
            break;
        case DRAW:
            printf("Has quedado empate. \n");
            break;
        case CPU:
            printf("Has perdido el duelo. \n");
            break;
    }
}

int main()
{
    int looping = 1;
    init_seed();
    print_instructions();
    while(looping == 1)
    {
        read_player_choice();
        if(check_valid_input() == 1) {
            print_players_choice();
            cpu_play();
            print_cpu_choice();
            check_winner();
            print_winner();
        }
    }
    return 0;
}
