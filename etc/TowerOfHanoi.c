//						TowerOfHanoi.c

// Solution to the Tower of Hanoi problem

#include <stdio.h>
#include <stdlib.h>

// Recursive function to solve Tower of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{
    // Base Case: If only 1 disk is left, move it directly
    if (n == 1) 
	{
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Step 1: Move top n-1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Step 2: Move the nth (largest) disk from source to destination rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // Step 3: Move the n-1 disks from auxiliary to destination rod
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(int argc, char **argv) 
{

	if (argc < 2)
	{
		printf ("Usage: %s <number of disks>\n", argv [0]);
		exit (0);
	}
    int n = atoi (argv [1]); // Number of disks

    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    
    // A = Source, C = Destination, B = Auxiliary
    towerOfHanoi(n, 'A', 'C', 'B'); 
    
    return 0;
}
