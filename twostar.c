#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float left;
    float right;
} ears;
typedef struct {
    char name[13];
    int weight;
    ears eararea;
} monkey;
int sort_monkey( const void *, const void *);
int sort_order( const void* a, const void* b)
{
    if      ( *((char*)a) < *((char*)b) )     return -1 ;
    else if ( *((char*)a) > *((char*)b) )     return  1 ;
    else                                      return  0 ;
}
int main(void)
{   monkey* monkeys[4];

    int i;
    char alfa[6] = { 'C', 'E', 'A', 'D', 'F', 'B' };
    qsort( (char*)alfa, 6, sizeof(char), sort_order);
    for (i=0 ; i<5 ; i++)  // now in order?
        printf("\nchar %d = %c",i, alfa[i]);
    printf("\n");

    for(i=0; i<4; i++) {
        monkeys[i]= (monkey* )malloc(sizeof(monkey));
        monkeys[i]->weight=i;
    }

    qsort((void* ) monkeys, 4, sizeof(monkey* ), sort_monkey);
    for (i=0 ; i<4; i++)  // now in order?
        printf("\nchar %d = %i",i, monkeys[i]->weight);
    return 0;
}



// Sorted by weight
int sort_monkey( const void* a, const void* b) {
    if((**((monkey** )a)).weight < (**((monkey** )b)).weight) return -1 ;
    else if ((**((monkey** )a)).weight > (**((monkey** )b)).weight ) return  1 ;
    else return  0 ;
}
