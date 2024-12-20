/*
 * mm.c
 *
 * Name: Vishvendra Reddy Bhoomidi
 *
 * Here we are goin to implement a dynamic storage allocator by modyfying the "mm_init", "malloc", "free", "realloc", and "mm_checkheap" functions.
 *
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include "mm.h"
#include "memlib.h"

/*
 * If you want to enable your debugging output and heap checker code,
 * uncomment the following line. Be sure not to have debugging enabled
 * in your final submission.
 */
// #define DEBUG

#ifdef DEBUG
// When debugging is enabled, the underlying functions get called
#define dbg_printf(...) printf(__VA_ARGS__)
#define dbg_assert(...) assert(__VA_ARGS__)
#else
// When debugging is disabled, no code gets generated
#define dbg_printf(...)
#define dbg_assert(...)
#endif // DEBUG

// do not change the following!
#ifdef DRIVER
// create aliases for driver tests
#define malloc mm_malloc
#define free mm_free
#define realloc mm_realloc
#define calloc mm_calloc
#define memset mm_memset
#define memcpy mm_memcpy
#endif // DRIVER

#define ALIGNMENT 16

// rounds up to the nearest multiple of ALIGNMENT
static size_t align(size_t x)
{
    return ALIGNMENT * ((x+ALIGNMENT-1)/ALIGNMENT);
}

/*
 * mm_init: returns false on error, true on success.
 */
bool mm_init(void)
{
    if(mem_sbrk(4*1024)==(void*)-1){
        return false;               //Fail
    }

    return true;                    //Success
}

/*
 * malloc
 */
void* malloc(size_t size)
{
    size_t temp = align(size);      //Using the align data structure to align the given size
    void* pay = mem_sbrk(temp);     //Alocating memory
    
    if(pay==(void*)-1){
        return NULL;                //Fail
    }
    
    return pay;
}

/*
 * free
 */
void free(void* ptr)
{
    if(ptr==NULL){      //the function willl do nothing
        return;
    }

    return;
}

/*
 * realloc
 */
void* realloc(void* oldptr, size_t size)
{
    size_t tempSize=1024;
    size_t newtempSize;

    if(size==0){
        free(oldptr);                   //frees the memory block
        return NULL;
    }

    if(oldptr==NULL){
        return malloc(size);            //allocates a new block of memory
    }
    
    size_t temp = align(size);           //Using the align data structure to align the given size
    void* newptr = malloc(temp);        //allocates a new block of memory
    
    if(newptr==NULL){
        return NULL;
    }

    if(tempSize<temp){
    newtempSize=tempSize;               //copies content from old block to new
    } else
    newtempSize=temp;

    memcpy(newptr,oldptr,newtempSize);
    free(oldptr);                       //fress the old block and returns the new one
    
    return newptr;
}

/*
 * calloc
 * This function is not tested by mdriver, and has been implemented for you.
 */
void* calloc(size_t nmemb, size_t size)
{
    void* ptr;
    size *= nmemb;
    ptr = malloc(size);
    if (ptr) {
        memset(ptr, 0, size);
    }
    return ptr;
}

/*
 * Returns whether the pointer is in the heap.
 * May be useful for debugging.
 */
static bool in_heap(const void* p)
{
    return p <= mm_heap_hi() && p >= mm_heap_lo();
}

/*
 * Returns whether the pointer is aligned.
 * May be useful for debugging.
 */
static bool aligned(const void* p)
{
    size_t ip = (size_t) p;
    return align(ip) == ip;
}

/*
 * mm_checkheap
 * You call the function via mm_checkheap(__LINE__)
 * The line number can be used to print the line number of the calling
 * function where there was an invalid heap.
 */
bool mm_checkheap(int line_number)
{
#ifdef DEBUG
    // Write code to check heap invariants here
    // IMPLEMENT THIS
#endif // DEBUG
    return true;
}
