
#define	EXIT_FAILURE	1	/* Failing exit status.  */
#define	EXIT_SUCCESS	0	/* Successful exit status.  */

/* The largest number rand will return (same as INT_MAX).  */
#define	RAND_MAX	2147483647

void exit(){
  asm{
    syscall sys_terminate_proc
  }
}

int atoi(char *str) {
    int result = 0;  // Initialize result
    int sign = 1;    // Initialize sign as positive

    // Skip leading whitespaces
    while (*str == ' ') str++;

    // Check for optional sign
    if (*str == '-' || *str == '+') {
        if (*str == '-') sign = -1;
        str++;
    }

    // Loop through all digits of input string
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}


/* Return a random integer between 0 and RAND_MAX inclusive.  */
int rand(){
  int  sec;
  asm{
      mov al, 0
      syscall sys_rtc					; get seconds
      mov al, ah
      addr mov d, sec
      mov al, [d]
      mov ah, 0
  }
  return sec;
}

/* Seed the random number generator with the given number.  */
void srand (unsigned int seed){

}

/* Allocate SIZE bytes of memory.  */
void *malloc (size_t size){

}

/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
void *calloc (size_t nmemb, size_t size){

}

/* Re-allocate the previously allocated block
   in PTR, making the new block SIZE bytes long.  */
void *realloc (void *ptr, size_t size){

}

// heap and heap_top are defined internally by the compiler
// so that 'heap' is the last variable in memory and therefore can grow upwards
// towards the stack
char *alloc(int bytes){
  heap_top = heap_top + bytes;
  return heap_top - bytes;
}

/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
char *free(int bytes){
  return heap_top = heap_top - bytes;
}