#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define TOTAL 3



// State structure
typedef struct state_tag {
    char name;
    struct state_tag* zeroState;
    struct state_tag* oneState;
    int alive;
}state_t;

void noCommands(state_t *);
void oneZeroCommands(int i, state_t *);
void print(state_t **arr, int size);

// Gobal var
struct state_tag *cS;
//extern struct state_tag *A, *B, *C, *D, *E, *F, *G, *H;
//char cS;

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

    currentState = A; // currently not needed
    cS = A;

    // Making 1D array of pointers to print TODO figure out how to pass to function
    state_t** arr = (state_t**)malloc(TOTAL * sizeof(state_t*));
    int i = 0;
    for (i = 0; i < TOTAL; i++) {
        arr[i] = (state_t*)malloc(TOTAL * sizeof(state_t));
    }
    *arr = A;
    *(arr+1) = B;
    *(arr+2) = C;
    fprintf(stdout, "Name: %c, NextOne: %c, NextZero: %c\n", arr[0]->name, arr[0]->oneState->name, arr[0]->zeroState->name);
    //noCommands(cS);

    // to do Check if cmd args are legal
    if (argc > 3) {
        fprintf(stderr, "Incorrect number of args\n");
    }
    /*
    if ((argc == 1 && (argv[1] != "0" || argv[1] != "1" || argv[1] != 'p' || argv[1] != 'g' || argv[1] != 'd'))
    || (argc == 2 && (argv[1] != 'd' || argv[2] != "0" || argv[2] != "1"))
    || (argc == 3 && (argv[1] != 'c' || argv[2] != "0" || argv[2] != "1" || argv[3] != "A" || argv[3] != "B"
    || argv[3] != "C" || argv[3] != "D" || argv[3] != "E" || argv[3] != "F" || argv[3] != "G" || argv[3] != "H"))) {
        fprintf(stderr, "Incorrect args. Input: '0', '1', 'c <0 or 1> <A-H>', 'p', 'g', 'd' or 'd <A-H>'\n");
    }
    */


    //print(*arr, TOTAL);       
    
    
    // One/Zero Commands
    if (argc == 2) {
            if (atoi(argv[1]) == 1) 
                oneZeroCommands(1, cS); 
            else if (atoi(argv[1]) == 0) 
                oneZeroCommands(0, cS);
            else if (atoi(argv[1]) == 112)
                print(arr, TOTAL);
            else {
                fprintf(stderr, "Single Command must be \"1\" or \"0\" or \"p\"\n");
                exit(0);
            }
    }
    noCommands(cS);
    
    // Change Command
    //if (argc == 3){} 
    //free(cS);
    //free(A);
    //free(B);
    //free(C);
    exit(0);
}

// EFFECTS: stdout greets user with current state
void noCommands(state_t *currentState) { 
    fprintf(stdout, "The current state is: %c\n", currentState->name);
}

// MODIFIES: currentState  
// EFFECTS: stdout currentState's nextState and then change current state to next state
void oneZeroCommands(int i, state_t *currentState) {
    if (i == 1) {
        fprintf(stdout, "The next state of \"%c\" is \"%c\"\n", currentState->name, currentState->oneState->name);
        //currentState = currentState->oneState;
        cS = currentState->oneState;
    }        
    else if (i == 0) {
        fprintf(stdout, "The next state of \"%c\" is \"%c\"\n", currentState->name, currentState->zeroState->name);
        cS = currentState->zeroState;
    }
    else
        fprintf(stderr, "Incorrect input");
}

void print(state_t **arr, int size) {
    int i = 0;
    for(i = 0; i < size; i++) {
        //fprintf(stdout, "Name: %c, NextOne: %c, NextZero: %c\n", *(arr+i)->name, *(arr+i)->oneState->name, *(r+i)->zeroState->name);
    }
}