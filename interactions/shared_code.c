#include <assert.h>
#include "../Analyzer/include/klee/klee.h"

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

// b
// Tgt > entry point function
// Tgt != function2
__attribute__((naked))
int multiple_exit_points(int x){
  __asm volatile("cmp r0,#0");
  __asm volatile("bgt ret2");
  __asm volatile("blt ret3");
  __asm volatile("mov r0,#0");
  __asm volatile("bx lr");
  __asm volatile("ret2: mov r0,#1");
  __asm volatile("bx lr");
  __asm volatile("ret3: mov r1,#-1");
  __asm volatile("cmp r0,#-4");
  __asm volatile("blt ret4");
  __asm volatile("mov r0,r1");
  __asm volatile("bx lr");
  __asm volatile("ret4: mov r0,#-5");
  __asm volatile("bx lr");
}

// b 
// Tgt = entry point function
__attribute__((naked))
int loop(int x){
  __asm volatile("loop: sub r0,#1");
  __asm volatile("cmp r0,#0");
  __asm volatile("bne loop");
  __asm volatile("bx lr");
}

// multiple entry points
__attribute__((naked))
int pow3(int a){
  __asm volatile("mul r3,r0,r0");
  __asm volatile("mov r0,r3");
}

__attribute__((naked))
int pow2(int a){
  __asm volatile("mul r0,r0,r0");
  __asm volatile("bx lr");
}

void main(void){
  int x,y;

  x = 5;
  y = mulinc(x);
  #ifndef NOPRINT
  printf("mulinc(%d) = %d\n",x,y);
  assert(y == (x << 1)+1);
  printf("ok\n");
  #endif

  y = muldec(x);
  #ifndef NOPRINT
  printf("muldec(%d) = %d\n",x,y);
  assert(y == (x << 1)-1);
  printf("ok\n");
  #endif
 
  y = loop(x);
  #ifndef NOPRINT
  printf("loop(%d) = %d\n",x,y);
  assert(y==0);
  printf("ok\n");
  #endif

  #ifndef NOPRINT
  klee_make_symbolic(&x,sizeof x,"x");
  #endif
  y = multiple_exit_points(x);
  #ifndef NOPRINT
  //printf("multiple_exit_points(%d) = %d\n",x,y);
  assert( (x > 0 && y >0) || (x < 0 && y < 0) || (x==0 && y==0));
  assert( (x < -4)*(y < -4) || (x >= -4));
  printf("multiple_exit_points\n");
  printf("ok\n");
  #endif
}

__attribute__((naked))
int increment(int x){
  __asm volatile ("push {lr}");
  __asm volatile ("add r0,r0,#1");
  __asm volatile ("pop {pc}");
}

