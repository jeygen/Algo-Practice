#include <stdio.h>
#include <stdlib.h>
#include "commands.h"



// State structure
typedef struct state_tag {
    char name;
    struct state_tag* zeroState;
    struct state_tag* oneState;
    int alive;
}state_t;

void noCommands(state_t *);
void oneZeroCommands(int i, state_t *);

// Gobal var
//extern struct state_tag currentState;
//extern struct state_tag *A, *B, *C, *D, *E, *F, *G, *H;

// Driver
int main(int argc, char * argv[]) {
    //state_t A, B, C, D, E, F, G, H;
    state_t *currentState, *A, *B, *C, *D, *E, *F, *G, *H;
    
    //currentState = (state_t*)malloc(sizeof(state_t));
    A = (state_t*)malloc(sizeof(state_t));
    B = (state_t*)malloc(sizeof(state_t));
    C = (state_t*)malloc(sizeof(state_t));
    D = (state_t*)malloc(sizeof(state_t));
    E = (state_t*)malloc(sizeof(state_t));
    F = (state_t*)malloc(sizeof(state_t));
    G = (state_t*)malloc(sizeof(state_t));
    H = (state_t*)malloc(sizeof(state_t));

    A->name = 'A';
    A->zeroState = (state_t*)malloc(sizeof(state_t));
    A->zeroState = B;
    A->oneState = (state_t*)malloc(sizeof(state_t));
    A->oneState = C;
    A->alive = 1;

    B->name = 'B';
    B->zeroState = (state_t*)malloc(sizeof(state_t));
    B->zeroState = A;
    B->oneState = (state_t*)malloc(sizeof(state_t));
    B->oneState = C;
    B->alive = 1;

    C->name = 'C';
    C->zeroState = (state_t*)malloc(sizeof(state_t));
    C->zeroState = B;
    C->oneState = (state_t*)malloc(sizeof(state_t));
    C->oneState = C;
    C->alive = 1;
/*
    D->name = 'D';
    D->zeroState = B;
    D->oneState = E;
    D->alive = 1;

    E->name = 'E';
    E->zeroState = G;
    E->oneState = F;
    E->alive = 1;

    F->name = 'F';
    F->zeroState = D;
    F->oneState = A;
    F->alive = 1;

    G->name = 'G';
    G->zeroState = A;
    G->oneState = B;
    G->alive = 1;

    H->name = 'H';
    H->zeroState = H;
    H->oneState = C;
    H->alive = 1;
   
*/
    /*
    state_t A = { .name = 'A',
                  .zeroState = H,
                  .oneState = G,
                  .alive = 1};
                  
    //state_t *Ap = &A;
    state_t B = { .name = 'B',
                  .zeroState = E,
                  .oneState = H,
                  .alive = 1};
    state_t *Bp = &B;
    state_t C = { .name = 'C',
                  .zeroState = F,
                  .oneState = D,
                  .alive = 1};
    state_t *Cp = &C;
    state_t D = { .name = 'D',
                  .zeroState = B,
                  .oneState = E,
                  .alive = 1};
    state_t *Dp = &D;
    state_t E = { .name = 'E',
                  .zeroState = G,
                  .oneState = F,
                  .alive = 1};
    state_t *Ep = &E;
    state_t F = { .name = 'F',
                  .zeroState = D,
                  .oneState = A,
                  .alive = 1};
    state_t *Fp = &F;
    state_t G = { .name = 'G',
                  .zeroState = A,
                  .oneState = B,
                  .alive = 1};
    state_t *Gp = &G;
    state_t H = { .name = 'H',
                  .zeroState = H,
                  .oneState = C,
                  .alive = 1};
    state_t *Hp = &H;
    */

    currentState = A;
    
    noCommands(currentState);

    // Check if cmd args are legal
    if (argc == 2) {
            if (atoi(argv[1]) == 1) 
                oneZeroCommands(1, currentState);
            if (atoi(argv[1]) == 0)
                oneZeroCommands(0, currentState);
            else {
                fprintf(stderr, "Command must be \"1\" or \"0\"");
                exit(0);
            }
    }
    noCommands(currentState);
    
    exit(0);
}

// Greets user with current state
void noCommands(state_t *currentState) {
    fprintf(stdout, "The current state is: %c\n", currentState->name);
}


void oneZeroCommands(int i, state_t *currentState) {
    if (i == 1) {
        fprintf(stdout, "The next state of \"%c\" is \"%c\"\n", currentState->name, currentState->oneState->name);
        //currentState = currentState->oneState;
    }        
    if (i == 0) {
        fprintf(stdout, "The next state of \"%c\" is \"%c\"\n", currentState->name, currentState->zeroState->name);
        //currentState = currentState->zeroState;
    }
    else
        fprintf(stderr, "Incorrect input");
}

