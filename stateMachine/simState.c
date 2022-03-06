#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define TOTAL 3
#define TOTAL2 5040



// State structure
typedef struct state_tag {
    char name;
    struct state_tag* zeroState;
    struct state_tag* oneState;
    int alive;
}state_t;

void noCommands(state_t *currentState);
void oneZeroCommands(int i, state_t *currentState);
void print(state_t **arr, int size);
void change(state_t *cs, int newZeroOrOne, state_t *newState);
void garbage(state_t **arr, state_t *cs);

int garbageBuddy(state_t *currentState);
void garbageAdd(char c);
void delete(int d, char c, state_t **arr, int size);


// Gobal var
struct state_tag *cS;
//extern struct state_tag *A, *B, *C, *D, *E, *F, *G, *H;
//char cS;
char staticControlArr[TOTAL2];
char staticGarbageList[TOTAL]; // for deleted states
int staticCount;
//state_t** arr;

// Driver
int main(int argc, char * argv[]) {
    int loop = 1; // Need to add constant running
    size_t bufferSize = 32;
    char *buffer = (char*)malloc(bufferSize * sizeof(char));
    size_t chars;
    int i = 0;

    for (i = 0; i < TOTAL2; i++) {
        staticControlArr[i] = 'z';
    }
    for (i = 0; i < TOTAL; i++) {
        staticGarbageList[i] = 'z';
    }
    

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
    A->zeroState = A;
    A->oneState = (state_t*)malloc(sizeof(state_t));
    A->oneState = A;
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



    // Making 1D array of pointers to print 
    state_t** arr = (state_t**)malloc(TOTAL * sizeof(state_t*));
    //arr = (state_t**)malloc(TOTAL * sizeof(state_t*));

    for (i = 0; i < TOTAL; i++) {
        arr[i] = (state_t*)malloc(TOTAL * sizeof(state_t));
    }
    *arr = A;
    *(arr+1) = B;
    *(arr+2) = C;
    
    
    // to do Check if cmd args are legal
    /*
    // This was for cmd line args, but program should accept args while running
    if (argc > 4) {
        fprintf(stderr, "Incorrect number of args\n");
    }
    
    if ((argc == 1 && (argv[1] != "0" || argv[1] != "1" || argv[1] != 'p' || argv[1] != 'g' || argv[1] != 'd'))
    || (argc == 2 && (argv[1] != 'd' || argv[2] != "0" || argv[2] != "1"))
    || (argc == 3 && (argv[1] != 'c' || argv[2] != "0" || argv[2] != "1" || argv[3] != "A" || argv[3] != "B"
    || argv[3] != "C" || argv[3] != "D" || argv[3] != "E" || argv[3] != "F" || argv[3] != "G" || argv[3] != "H"))) {
        fprintf(stderr, "Incorrect args. Input: '0', '1', 'c <0 or 1> <A-H>', 'p', 'g', 'd' or 'd <A-H>'\n");
    }
    */


    // One/Zero Commands

    /*
    // This was for cmd line args, but program should accept args while running
    while (argc == 2) {
            if (argv[1][0] == 'p') {
                print(arr, TOTAL);
                break;
            }
            else if (atoi(argv[1]) == 1){
                oneZeroCommands(1, cS);
                break;
            } 
            else if (atoi(argv[1]) == 0) {
                oneZeroCommands(0, cS);
                break;
            }
            else {
                fprintf(stderr, "Single Command must be \"1\" or \"0\" or \"p\"\n");
                exit(0);
            }
    }
    */
    
    // Change Command
    /*
    // This was for cmd line args, but program should accept args while running
    state_t *temp;
    while (argc == 4 && argv[1][0] == 'c') {
            if (((atoi(argv[2]) == 1 || atoi(argv[2]) == 0)) && ((argv[3][0] == 'A' || argv[3][0] == 'B' || argv[3][0] == 'C'))) {
                for (i = 0; i < TOTAL; i++) {
                    if (arr[i][0].name == argv[3][0])
                        temp = arr[i];
                }
                change(cS, atoi(argv[2]), temp);
                break;
            } 
            else {
                fprintf(stderr, "Change Command must be \"c\" then \"0\" or \"1\" then \"A-H\"\n");
                exit(0);
            }
    }
    //change(cS, 1, A); // dont worry about NULL, must point to existing state
    print(arr, TOTAL);
    */

    /*
    char inArr[3];
    fprintf(stdout, "How many args will you be inputing? (0 to 3) (O exits program)\n");

    int argCount = -1;
    for (;;) { 
        fprintf(stdout, "Input num between 0 and 3:\n");
        scanf("%d", &argCount);
        if (argCount > -1 && argCount < 4)
            break;
        scanf("%c", &argCount);
    }

    fprintf(stdout, "Please input args.\n");
    for (i = 0; i < argCount; i++) {
        scanf("%c", inArr[i]);
    }
    */

    fprintf(stdout, "\n***\nWelcome to state machine\n***\nInput options (case sensitive):\n");
    noCommands(cS);
    garbageBuddy(cS); // Need to run this now to make sure gobal values are fully initialized, actually this didnt fix it, can del

    LOOP: 

    fprintf(stdout, "\n***\n");
    fprintf(stdout, "Please input args.\n");
    char inChar; // = getchar();
    scanf(" %c", &inChar);
    
    int temp2;
    char tempChar;
    state_t *tempState;
    //int inInt = -1;
    //scanf("&d", &inInt);

    // Args to replay greeting and show current state
    if (inChar == 'r')
        noCommands(cS);

    // Args for oneZeroCommands
    if (inChar == '0')
        oneZeroCommands(0, cS);
    if (inChar == '1')
        oneZeroCommands(1, cS);

    // Args for print
    if (inChar == 'p')
        print(arr, TOTAL);

    // Args for garbage    
    if (inChar == 'g') {
        print(arr, TOTAL);
        garbage(arr, cS);
        //print(arr, TOTAL);
    }

    // Args for change
    if (inChar == 'c') {
        //fprintf(stdout, "Please input 0 or 1 to choose which state to modify.\n");
        scanf(" %d", &temp2);
        //fprintf(stdout, "Please which state to modify. <A-H>\n");
        scanf(" %c", &inChar);
        for (i = 0; i < TOTAL; i++) {
                    if (arr[i][0].name == inChar)
                        tempState = arr[i];
                }
        change(cS, temp2, tempState);
    }

    // Args for quit
    if (inChar == 'q') {
        fprintf(stdout, "Goodbye");    
        exit(0);
    }    

    if (inChar == 'd') {
        fprintf(stdout, "Input 0 to delete all garbage, otherwise input <A-H> to check status of specific state:\n");
        scanf(" %c", &inChar);
        if (inChar == '0')
            delete(0, 'z', arr, TOTAL);
        else 
           delete(1, inChar, arr, TOTAL);
        //fprintf(stdout, "Please input a state name to delete <A-H>\n");
        //scanf(" %c", &tempChar);
            //inChar = getchar();
        //delete(1, buffer, arr, TOTAL);
    }
    
    goto LOOP;


    //if (argc == 3){} 
    free(cS);
    //free(A);
    //free(B);
    //free(C);
    free(arr);
    //free(arr[0]);
    //free arr elements?

    exit(0);
}

// EFFECTS: stdout greets user with current state
void noCommands(state_t *currentState) { 
    fprintf(stdout, "---To change what the current state's zero state or one state value is: c <0 or 1> <A-H>\n");
    fprintf(stdout, "---To change current state to it's one or zero state: <0 or 1>\n");
    fprintf(stdout, "---To identify unreachable states: g\n");
    fprintf(stdout, "---To delete garbage or specified states: d or d <A-H>\n");
    fprintf(stdout, "---To quit: q\n");
    fprintf(stdout, "---To replay this message: r\n");
    fprintf(stdout, "***\nThe current state is: %c\n***\n", currentState->name);
}

// MODIFIES: currentState  
// EFFECTS: stdout currentState's nextState and then change current state to next state
void oneZeroCommands(int i, state_t *currentState) {
    if (i == 1) {
        fprintf(stdout, "The next state of \"%c\" is \"%c\"\n", currentState->name, currentState->oneState->name);
        //currentState = currentState->oneState;
        cS = currentState->oneState;
        fprintf(stdout, "New current state is \"%c\"\n", cS->name);
    }        
    else if (i == 0) {
        fprintf(stdout, "The next state of \"%c\" is \"%c\"\n", currentState->name, currentState->zeroState->name);
        cS = currentState->zeroState;
        fprintf(stdout, "New current state is \"%c\"\n", cS->name);
    }
    else
        fprintf(stderr, "Incorrect input");
}

// EFFECTS: Prints all states and each states Zero state and One state
void print(state_t **arr, int size) {
    int i = 0;
    for(i = 0; i < size; i++) {
        if (*(arr+i) == NULL)
            fprintf(stderr, "Pointing to NULL");
        if ((*(arr+i))->name == 'z' || (*(arr+i))->name == ' ')
            continue;
        fprintf(stdout, "----\nSTATE: %c\nNextZeroState: %c\nNextOneState: %c\n", arr[i][0].name, (*(arr+i))->zeroState->name, (*(arr+i))->oneState->name); 
        //fprintf(stdout, "----\nSTATE: %c\n", arr[i][0].name);
        //fprintf(stdout, "----\nSTATE: %c\n", (*(*(arr+i)+0)).name); // *(*(arr+i)+j pointer way for 2D array
    }
}

// MODIFIES: cS
// EFFECTS: Changes oneState or zeroState of cs
void change(state_t *cs, int newZeroOrOne, state_t *newState) {
    if (newZeroOrOne == 1) {
        cs->oneState = newState;
    }
    if (newZeroOrOne == 0) {
        cs->zeroState = newState;
    }
}

// EFFECTS: Print all states that are reachable and unreachable from current state
void garbage(state_t **arr, state_t *cs) {
    char controlArr[] = {'A', 'B', 'C'}; //, 'D', 'E', 'F', 'G'};
    int size = TOTAL;
    int i = 0;
    int j = 0;
    int k = 0;
    int counter = 0;
    int counter2 = 0;
        // experimental section
    garbageBuddy(cs);
    for(i = 0; i < TOTAL2; i++) {
        
        //fprintf(stdout, " %c ", staticControlArr[i]);
    }
    fprintf(stdout, "\nReachable states from (%c)'s perspective:", cs->name);
    for(i = 0; i < TOTAL2; i++) {
        if (staticControlArr[i] != 'z') { // && (cs->oneState->name == cs->name || cs->zeroState->name == cs->name)) { 
            fprintf(stdout, " %c ", staticControlArr[i]);
            counter++; 
        }
    }
    //if (counter == 1) {
    //    fprintf(stdout, "No garbage\n");
    //}
    fprintf(stdout, "\n");

    for(i = 0; i < TOTAL; i++) {
        for(j = 0; j < TOTAL2; j++) {
            if (controlArr[i] == staticControlArr[j]) // replacing the control arrays elements with dummy variable 'z' if they exist in a temp state array
                controlArr[i] = 'z';
                //counter2++;
        }
    }
    if (controlArr[i] != 'z') 
            fprintf(stdout, "Garbage:");
    for(i = 0; i < TOTAL; i++) {
        if (controlArr[i] != 'z' && (*(arr+i))->name != ' ') {// if in local control array and not nameless (' ') in passed pointer array
            fprintf(stdout, " %c ", controlArr[i]);
            staticGarbageList[i] = controlArr[i];
        }
        else
            counter2++;
    }
    if (counter2 == TOTAL)
        fprintf(stdout, " No garbage\n");

    /*
    if (counter2++ > 1) {
        fprintf(stdout, "Garbage states from (%c)'s perspective:", cs->name);
        for(i = 0; i < TOTAL; i++) {
            if (controlArr[i] != 'z') { // printing the elements in the control array that haven't been changed to dummy variable 'c'
                fprintf(stdout, " %c ", staticControlArr[i]);
                counter++; // if any dummy elements counter turns on which indicates that line 406 'no garbage' will not run
            }
        }
    }
    */

    for (i = 0; i < TOTAL2; i++) {
        staticControlArr[i] = 'z';
    }

    // experimental end


    /*
    for(i = 0; i < TOTAL; i++) {
        for(j = 1; j < TOTAL; j++) {
            if (tempArr[i] == tempArr[j])
               tempArr[j] = 'z'; 
        }
    }
    for(i = 0; i < TOTAL; i++) {
        for(j = 0; j < TOTAL; j++) {
            //if (arr[i][0].name == tempArr[j])
                //counter++;
        }
    }
    */

}

int garbageBuddy(state_t *currentState) {
    /*
    if (cS->zeroState->name == 'A' || cS->zeroState->name == 'B' || cS->zeroState->name == 'C' || cS->zeroState->name == 'D' ||
        cS->zeroState->name == 'E' || cS->zeroState->name == 'F' || cS->zeroState->name == 'G' || cS->zeroState->name == 'H') {
    */
    //char controlArr[] = {'A', 'B', 'C'}; //, 'D', 'E', 'F', 'G'};
    int i = 0;

    for (i = 0; i < TOTAL2; i++) {
        if (currentState->name == staticControlArr[i])
            return 0;
    }

    if (currentState->name == 'A' || currentState->name == 'B' || currentState->name == 'C'){ // || currentState->name == 'D' ||
        //cS->name == 'E' || cS->name == 'F' || cS->name == 'G' || cS->name == 'H') {
            garbageAdd(currentState->name);
            garbageBuddy(currentState->oneState);
            garbageBuddy(currentState->zeroState);
    }

    return 0;
    
    /*
    if (currentState->name == 'A' || currentState->name == 'B' || currentState->name == 'C'){ // || currentState->name == 'D' ||
        //cS->name == 'E' || cS->name == 'F' || cS->name == 'G' || cS->name == 'H') {
            garbageAdd(currentState->name);
    }
    */

    
} 

void garbageAdd(char c) {
    //int size = 5040
    //char controlArr[size];
    //int i = 0;

    //for (i = 0; i < size; i++) {
    //    controlArr[i] = 'z';
    //}
    staticControlArr[staticCount] = c;
    staticCount++;
}

void delete(int d, char c, state_t **arr, int size) {
    int i = 0;
    int j = 0;
    int counter = 0;

    if (d == 0) { // to delete all garbage states, if the state is on the staticGarbageList it is replaced with ' ', if any states removed counter becomes non-zero 
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if((*(arr+i))->zeroState->name == staticGarbageList[j]) {
                    (*(arr+i))->zeroState->name = ' ';
                    counter++;
                }
                if((*(arr+i))->oneState->name == staticGarbageList[j]) {
                    (*(arr+i))->oneState->name = ' ';
                    counter++;
                }
            }
        }
    }

    if (counter == 0) { // checks counter to see if any states deleted
        fprintf(stdout, "\nNo states deleted.\n");
    }

    /*
    if (counter != 0) { // Lists deleted states after deleting them
        fprintf(stdout, "List of deleted states: ");
        for (i = 0; i < TOTAL; i++) {
            if (staticGarbageList[i] != 'z')
                fprintf(stdout, " %c ", staticGarbageList[i]);
        }
    }
    fprintf(stdout, "\n");
    */
    j = 0;
    for (i = 0; i < TOTAL; i++) { // is staticGarbageList is empty (all 'z') then skip printing list of deleted states
        if (staticGarbageList[i] == 'z')
            j++;
        if (j == TOTAL-1)
            goto SKIP;
    }

    fprintf(stdout, "Current list of deleted states: ");
    for (i = 0; i < TOTAL; i++) {
        if (staticGarbageList[i] != 'z')
            fprintf(stdout, " %c ", staticGarbageList[i]);
    }
    fprintf(stdout, "\n");

    SKIP:

    counter = 0;
    if (d == 1) { 

        for (i = 0; i < TOTAL; i++) {
            if (staticGarbageList[i] == c) {
                fprintf(stdout, "%c is deleted\n", c);
                counter++;
            }
        }
        if (counter == 0) 
            fprintf(stdout, "%c is not deleted\n", c);
    }
}
       



