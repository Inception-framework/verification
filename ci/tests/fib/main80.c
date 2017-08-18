#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R5,#4"); 
  __asm volatile("push	{R9}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R9, sp, #0"); 
  __asm volatile("str	R5, [R9, #4]"); 
  __asm volatile("movs	R11, #0"); 
  __asm volatile("str	R11, [R9, #20]"); 
  __asm volatile("movs	R11, #1"); 
  __asm volatile("str	R11, [R9, #16]"); 
  __asm volatile("movs	R11, #0"); 
  __asm volatile("str	R11, [R9, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R11, [R9, #8]"); 
  __asm volatile("cmp	R11, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R11, [R9, #8]"); 
  __asm volatile("str	R11, [R9, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R0, [R9, #20]"); 
  __asm volatile("ldr	R11, [R9, #16]"); 
  __asm volatile("add	R11, R0"); 
  __asm volatile("str	R11, [R9, #12]"); 
  __asm volatile("ldr	R11, [R9, #16]"); 
  __asm volatile("str	R11, [R9, #20]"); 
  __asm volatile("ldr	R11, [R9, #12]"); 
  __asm volatile("str	R11, [R9, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R11, [R9, #8]"); 
  __asm volatile("adds	R11, #1"); 
  __asm volatile("str	R11, [R9, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R0, [R9, #8]"); 
  __asm volatile("ldr	R11, [R9, #4]"); 
  __asm volatile("cmp	R0, R11"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R11, [R9, #12]"); 
  __asm volatile("mov	R5, R11"); 
  __asm volatile("adds	R9, #28"); 
  __asm volatile("mov	sp, R9"); 
  __asm volatile("ldr.w	R9, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
