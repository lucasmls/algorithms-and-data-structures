#include <stdio.h>

void tower_of_hanoi(int disks, int initial_tower, int intermediate_tower, int final_tower)
{
  if (disks > 0)
  {
    tower_of_hanoi(disks - 1, initial_tower, final_tower, intermediate_tower);
    printf("Moving disk from %d to %d\n", initial_tower, final_tower);
    tower_of_hanoi(disks - 1, intermediate_tower, initial_tower, final_tower);
  }
}

int main()
{
  tower_of_hanoi(3, 1, 2, 3);
}