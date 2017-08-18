#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R0,#3"); 
  __asm volatile("push	{R6}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R6, sp, #0"); 
  __asm volatile("str	R0, [R6, #4]"); 
  __asm volatile("movs	R1, #0"); 
  __asm volatile("str	R1, [R6, #20]"); 
  __asm volatile("movs	R1, #1"); 
  __asm volatile("str	R1, [R6, #16]"); 
  __asm volatile("movs	R1, #0"); 
  __asm volatile("str	R1, [R6, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R1, [R6, #8]"); 
  __asm volatile("cmp	R1, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R1, [R6, #8]"); 
  __asm volatile("str	R1, [R6, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R12, [R6, #20]"); 
  __asm volatile("ldr	R1, [R6, #16]"); 
  __asm volatile("add	R1, R12"); 
  __asm volatile("str	R1, [R6, #12]"); 
  __asm volatile("ldr	R1, [R6, #16]"); 
  __asm volatile("str	R1, [R6, #20]"); 
  __asm volatile("ldr	R1, [R6, #12]"); 
  __asm volatile("str	R1, [R6, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R1, [R6, #8]"); 
  __asm volatile("adds	R1, #1"); 
  __asm volatile("str	R1, [R6, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R12, [R6, #8]"); 
  __asm volatile("ldr	R1, [R6, #4]"); 
  __asm volatile("cmp	R12, R1"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R1, [R6, #12]"); 
  __asm volatile("mov	R0, R1"); 
  __asm volatile("adds	R6, #28"); 
  __asm volatile("mov	sp, R6"); 
  __asm volatile("ldr.w	R6, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
