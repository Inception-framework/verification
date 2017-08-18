#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R5,#6"); 
  __asm volatile("push	{R7}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R7, sp, #0"); 
  __asm volatile("str	R5, [R7, #4]"); 
  __asm volatile("movs	R9, #0"); 
  __asm volatile("str	R9, [R7, #20]"); 
  __asm volatile("movs	R9, #1"); 
  __asm volatile("str	R9, [R7, #16]"); 
  __asm volatile("movs	R9, #0"); 
  __asm volatile("str	R9, [R7, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R9, [R7, #8]"); 
  __asm volatile("cmp	R9, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R9, [R7, #8]"); 
  __asm volatile("str	R9, [R7, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R1, [R7, #20]"); 
  __asm volatile("ldr	R9, [R7, #16]"); 
  __asm volatile("add	R9, R1"); 
  __asm volatile("str	R9, [R7, #12]"); 
  __asm volatile("ldr	R9, [R7, #16]"); 
  __asm volatile("str	R9, [R7, #20]"); 
  __asm volatile("ldr	R9, [R7, #12]"); 
  __asm volatile("str	R9, [R7, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R9, [R7, #8]"); 
  __asm volatile("adds	R9, #1"); 
  __asm volatile("str	R9, [R7, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R1, [R7, #8]"); 
  __asm volatile("ldr	R9, [R7, #4]"); 
  __asm volatile("cmp	R1, R9"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R9, [R7, #12]"); 
  __asm volatile("mov	R5, R9"); 
  __asm volatile("adds	R7, #28"); 
  __asm volatile("mov	sp, R7"); 
  __asm volatile("ldr.w	R7, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
