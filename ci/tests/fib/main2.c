#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R0,#4"); 
  __asm volatile("push	{R7}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R7, sp, #0"); 
  __asm volatile("str	R0, [R7, #4]"); 
  __asm volatile("movs	R3, #0"); 
  __asm volatile("str	R3, [R7, #20]"); 
  __asm volatile("movs	R3, #1"); 
  __asm volatile("str	R3, [R7, #16]"); 
  __asm volatile("movs	R3, #0"); 
  __asm volatile("str	R3, [R7, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R3, [R7, #8]"); 
  __asm volatile("cmp	R3, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R3, [R7, #8]"); 
  __asm volatile("str	R3, [R7, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R2, [R7, #20]"); 
  __asm volatile("ldr	R3, [R7, #16]"); 
  __asm volatile("add	R3, R2"); 
  __asm volatile("str	R3, [R7, #12]"); 
  __asm volatile("ldr	R3, [R7, #16]"); 
  __asm volatile("str	R3, [R7, #20]"); 
  __asm volatile("ldr	R3, [R7, #12]"); 
  __asm volatile("str	R3, [R7, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R3, [R7, #8]"); 
  __asm volatile("adds	R3, #1"); 
  __asm volatile("str	R3, [R7, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R2, [R7, #8]"); 
  __asm volatile("ldr	R3, [R7, #4]"); 
  __asm volatile("cmp	R2, R3"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R3, [R7, #12]"); 
  __asm volatile("mov	R0, R3"); 
  __asm volatile("adds	R7, #28"); 
  __asm volatile("mov	sp, R7"); 
  __asm volatile("ldr.w	R7, [sp], #4"); 
  __asm volatile("bx	lr"); 
  __asm volatile("nop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
