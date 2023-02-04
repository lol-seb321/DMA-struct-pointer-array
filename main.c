// DMA array of struct pointer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Point
{
  int x;
  int y;
}Point;

// Function that dynamically allocates an array of structure (Point) pointers
Point **PointPointersFactory(int n, int maxXY)
{
  // we use a double pointer **p because we want to store the address of another pointer
  // block of memory that can accumulate many structure pointers
  Point **p = (Point **)malloc(n *sizeof(Point*));

  for(int i = 0; i < n; i++)
  {
    p[i] = (Point *)malloc(sizeof(Point));
    //p[i] = pointfactory(); we can write this instead of writing the line above 

    p[i]->x = rand()%maxXY;
    p[i]->y = rand()%maxXY;
        

  }
  return p;
}

// a function that takes structure pointer and sets random values for a dynamically allocated slot of memory
Point* pointfactory()
{
  // structure pointer that we set to dma of a single size of structure Point
  Point *p = (Point*)malloc(sizeof(Point));
  // the values are a random num. 0-99
  p->x = rand()%100;
  p->y = rand()%100;

  return p;
}

// a function that allocates a block of mem for an array of structures
Point *pointArrayFactory(int n)
{
  // creates a dynamic array of structures of size n and points to it with a structure pointer
  Point *p = (Point*)malloc(n*sizeof(Point));

  // loops through the array of structures and assigns a random value to each struct x and y
  for(int i = 0; i<n; i++)
    {
      p[i].x = rand()%100;
      p[i].y = rand()%100;

    }
  return p;
}



int main(void) {
  srand(time(0)); // change the seed of the random number generator
  int n;
  printf("How many points: \n");
  scanf("%d", &n);
  // calls function and puts it in a structure pointer
  //Point **points = pointArrayFactory(n);
  Point **ptrs = PointPointersFactory(n, 100);

  printf("All of the points: \n");
  for(int i = 0; i<n; i++)
    //printf("%d %d\n", points[i].x, points[i].y);
    printf("x:%d y:%d\n", ptrs[i]->x, ptrs[i]->y);

  for(int i = 0; i<n; i++)
    free(ptrs[i]);
  // free (ptrs);   !!!BIG MEMORY LEAK!!!
  
  return 0;
}