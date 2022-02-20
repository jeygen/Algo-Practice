#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

typedef struct state_tag {
    char name;
    char zeroState;
    char oneState;
    int alive;
} state_t;

int main(int argc, char * argv[]) {
    state_t A = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    state_t B = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    state_t C = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    state_t D = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    state_t E = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    state_t F = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    state_t G = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    state_t G = { .name = 'A',
                  .zeroState = 'H',
                  .oneState = 'G',
                  .alive = 1};
    
   
    
    exit(0);
}

