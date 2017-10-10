#include <assert.h>

__attribute__((naked))
int decrement(int x){
  __asm volatile ("push {lr}");
  __asm volatile ("sub r0,r0,#1");
  __asm volatile ("pop {pc}");
}


// b
// Tgt < entry point function
// Tgt = function2 entry point
__attribute__((naked))
int muldec(int x){
  __asm volatile ("push {lr}");
  __asm volatile ("lsl r0,r0,#1");
  __asm volatile ("pop {lr}");
  __asm volatile ("b decrement");
  __asm volatile ("pop {pc}");
}

// b
// Tgt > entry point function
// Tgt = function2 entry point
__attribute__((naked))
int mulinc(int x){
  __asm volatile ("push {lr}");
  __asm volatile ("lsl r0,r0,#1");
  __asm volatile ("pop {lr}");
  __asm volatile ("b increment");
  __asm volatile ("pop {pc}");
}

void main(void){
  int x,y;

  x = 5;
  y = mulinc(x);
  #ifndef NOPRINT
  printf("mulinc(%d) = %d\n",x,y);
  assert(y == (x << 1)+1);
  printf("ok");
  #endif

  y = muldec(x);
  #ifndef NOPRINT
  printf("muldec(%d) = %d\n",x,y);
  assert(y == (x << 1)-1);
  printf("ok");
  #endif
}

__attribute__((naked))
int increment(int x){
  __asm volatile ("push {lr}");
  __asm volatile ("add r0,r0,#1");
  __asm volatile ("pop {pc}");
}

