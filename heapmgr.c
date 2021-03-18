#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static const int MAX_HEAP = 1024*1024;
static const int MIN_SIZE = 8;

/* 
* purpose: Ensure the intialization of the heap to be managed
* input:   None
* return:  The start of the heap
*/
static void *get_heap(){
 
  int *header;
  static void* start;
    
  //if we have a heap already, great, return the front of it
  if (start != 0){
    return start;
  }

  //allocate MAX_HEAP bytes for our heap manager by moving the break
  if ( (start = sbrk(MAX_HEAP+4)) <0){
    perror("sbrk");
    return NULL;
  }
  //payloads need to be on an 8 byte boundry and the headers are 4, so...
  start+=4;
  
    //set the header for the whole big chunk (ignoring a prologue)
  header=start;
  *header = MAX_HEAP;

  //set the footer for the whole big chunk (ignoring an epilogue)
  header = sbrk(0);
  *(header-1)=MAX_HEAP;      

  return start;
}

/*
* purpose: allocated memory on the heap using headers and footers
* input:   size - the amount of space to be allocated (w/o header and footer)
* return:  a pointer to the start of the payload
*/
void *my_malloc(unsigned int size){
  
  void *start;
  
  start = get_heap();
  
  return start;
  
}

/*
* purpose: mark memory as unused and coellese ajacent blocks
* input:   memloc - pointer to payload of memory location to free
* return:  nothing
*/ 
void my_free(void *memloc){
  
}

/*
* purpose: Print out the heap
* inputs:  None
* return:  None (printing out to the screen is a side effect
*/
void print_heap(){

}
