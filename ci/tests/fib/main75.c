#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R11,#2"); 
  __asm volatile("push	{R5}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R5, sp, #0"); 
  __asm volatile("str	R11, [R5, #4]"); 
  __asm volatile("movs	R7, #0"); 
  __asm volatile("str	R7, [R5, #20]"); 
  __asm volatile("movs	R7, #1"); 
  __asm volatile("str	R7, [R5, #16]"); 
  __asm volatile("movs	R7, #0"); 
  __asm volatile("str	R7, [R5, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R7, [R5, #8]"); 
  __asm volatile("cmp	R7, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R7, [R5, #8]"); 
  __asm volatile("str	R7, [R5, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R12, [R5, #20]"); 
  __asm volatile("ldr	R7, [R5, #16]"); 
  __asm volatile("add	R7, R12"); 
  __asm volatile("str	R7, [R5, #12]"); 
  __asm volatile("ldr	R7, [R5, #16]"); 
  __asm volatile("str	R7, [R5, #20]"); 
  __asm volatile("ldr	R7, [R5, #12]"); 
  __asm volatile("str	R7, [R5, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R7, [R5, #8]"); 
  __asm volatile("adds	R7, #1"); 
  __asm volatile("str	R7, [R5, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R12, [R5, #8]"); 
  __asm volatile("ldr	R7, [R5, #4]"); 
  __asm volatile("cmp	R12, R7"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R7, [R5, #12]"); 
  __asm volatile("mov	R11, R7"); 
  __asm volatile("adds	R5, #28"); 
  __asm volatile("mov	sp, R5"); 
  __asm volatile("ldr.w	R5, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
