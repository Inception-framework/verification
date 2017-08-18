#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R11,#8"); 
  __asm volatile("push	{R0}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R0, sp, #0"); 
  __asm volatile("str	R11, [R0, #4]"); 
  __asm volatile("movs	R1, #0"); 
  __asm volatile("str	R1, [R0, #20]"); 
  __asm volatile("movs	R1, #1"); 
  __asm volatile("str	R1, [R0, #16]"); 
  __asm volatile("movs	R1, #0"); 
  __asm volatile("str	R1, [R0, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R1, [R0, #8]"); 
  __asm volatile("cmp	R1, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R1, [R0, #8]"); 
  __asm volatile("str	R1, [R0, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R10, [R0, #20]"); 
  __asm volatile("ldr	R1, [R0, #16]"); 
  __asm volatile("add	R1, R10"); 
  __asm volatile("str	R1, [R0, #12]"); 
  __asm volatile("ldr	R1, [R0, #16]"); 
  __asm volatile("str	R1, [R0, #20]"); 
  __asm volatile("ldr	R1, [R0, #12]"); 
  __asm volatile("str	R1, [R0, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R1, [R0, #8]"); 
  __asm volatile("adds	R1, #1"); 
  __asm volatile("str	R1, [R0, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R10, [R0, #8]"); 
  __asm volatile("ldr	R1, [R0, #4]"); 
  __asm volatile("cmp	R10, R1"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R1, [R0, #12]"); 
  __asm volatile("mov	R11, R1"); 
  __asm volatile("adds	R0, #28"); 
  __asm volatile("mov	sp, R0"); 
  __asm volatile("ldr.w	R0, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
