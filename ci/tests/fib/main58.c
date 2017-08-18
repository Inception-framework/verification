#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R5,#10"); 
  __asm volatile("push	{R11}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R11, sp, #0"); 
  __asm volatile("str	R5, [R11, #4]"); 
  __asm volatile("movs	R7, #0"); 
  __asm volatile("str	R7, [R11, #20]"); 
  __asm volatile("movs	R7, #1"); 
  __asm volatile("str	R7, [R11, #16]"); 
  __asm volatile("movs	R7, #0"); 
  __asm volatile("str	R7, [R11, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R7, [R11, #8]"); 
  __asm volatile("cmp	R7, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R7, [R11, #8]"); 
  __asm volatile("str	R7, [R11, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R4, [R11, #20]"); 
  __asm volatile("ldr	R7, [R11, #16]"); 
  __asm volatile("add	R7, R4"); 
  __asm volatile("str	R7, [R11, #12]"); 
  __asm volatile("ldr	R7, [R11, #16]"); 
  __asm volatile("str	R7, [R11, #20]"); 
  __asm volatile("ldr	R7, [R11, #12]"); 
  __asm volatile("str	R7, [R11, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R7, [R11, #8]"); 
  __asm volatile("adds	R7, #1"); 
  __asm volatile("str	R7, [R11, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R4, [R11, #8]"); 
  __asm volatile("ldr	R7, [R11, #4]"); 
  __asm volatile("cmp	R4, R7"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R7, [R11, #12]"); 
  __asm volatile("mov	R5, R7"); 
  __asm volatile("adds	R11, #28"); 
  __asm volatile("mov	sp, R11"); 
  __asm volatile("ldr.w	R11, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
