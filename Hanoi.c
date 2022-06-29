#include <stdio.h>
#include <stdlib.h>

int move_disk(int disk, int *source, int *target, int *aux, int numOfDisks, int **rods);
void print_tower(int size, int *A, int *B, int *C);

int main()
{
    int numOfDisks, moves;
    int *A, *B, *C;
    int *rods[3];

    printf("\nTOWER OF HANOI SOLVER\n\n");
    printf("Enter the number of disks: ");
    scanf("%d", &numOfDisks);

    A = malloc(numOfDisks * sizeof(int));
    B = malloc(numOfDisks * sizeof(int));
    C = malloc(numOfDisks * sizeof(int));

    for(int i = 0; i < numOfDisks; i++)
    {
        A[i] = numOfDisks - i;
        B[i] = 0;
        C[i] = 0;
    }

    rods[0] = A;
    rods[1] = B;
    rods[2] = C;

    print_tower(numOfDisks, A, B, C);

    moves = move_disk(numOfDisks, A, C, B, numOfDisks, rods);

    printf("\nSolved in %d moves\n\n", moves);

    return 0;
}

int move_disk(int disk, int *source, int *target, int *aux, int numOfDisks, int **rods)
{
    if(disk > 0)
    {
        int moves = 1;

        moves += move_disk(disk - 1, source, aux, target, numOfDisks, rods);

        int i = 0, j = 0;

        while (source[i] != disk) i++;
        while (target[j] != 0) j++;  

        target[j] = source[i];
        source[i] = 0;

        print_tower(numOfDisks, rods[0], rods[1], rods[2]);

        moves += move_disk(disk - 1, aux, target, source, numOfDisks, rods);

        return moves;
    }
    return 0;
}

void print_tower(int size, int *A, int *B, int *C)
{
    printf("\nA( ");
    for(int i = 0; i < size; i++) printf("%d ",A[i]);
    printf(") B( ");
    for(int i = 0; i < size; i++) printf("%d ",B[i]);
    printf(") C( ");
    for(int i = 0; i < size; i++) printf("%d ",C[i]);
    printf(")\n");
}
