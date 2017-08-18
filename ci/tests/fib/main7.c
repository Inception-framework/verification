#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R6,#4"); 
  __asm volatile("push	{R12}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R12, sp, #0"); 
  __asm volatile("str	R6, [R12, #4]"); 
  __asm volatile("movs	R0, #0"); 
  __asm volatile("str	R0, [R12, #20]"); 
  __asm volatile("movs	R0, #1"); 
  __asm volatile("str	R0, [R12, #16]"); 
  __asm volatile("movs	R0, #0"); 
  __asm volatile("str	R0, [R12, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R0, [R12, #8]"); 
  __asm volatile("cmp	R0, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R0, [R12, #8]"); 
  __asm volatile("str	R0, [R12, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R11, [R12, #20]"); 
  __asm volatile("ldr	R0, [R12, #16]"); 
  __asm volatile("add	R0, R11"); 
  __asm volatile("str	R0, [R12, #12]"); 
  __asm volatile("ldr	R0, [R12, #16]"); 
  __asm volatile("str	R0, [R12, #20]"); 
  __asm volatile("ldr	R0, [R12, #12]"); 
  __asm volatile("str	R0, [R12, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R0, [R12, #8]"); 
  __asm volatile("adds	R0, #1"); 
  __asm volatile("str	R0, [R12, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R11, [R12, #8]"); 
  __asm volatile("ldr	R0, [R12, #4]"); 
  __asm volatile("cmp	R11, R0"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R0, [R12, #12]"); 
  __asm volatile("mov	R6, R0"); 
  __asm volatile("adds	R12, #28"); 
  __asm volatile("mov	sp, R12"); 
  __asm volatile("ldr.w	R12, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
