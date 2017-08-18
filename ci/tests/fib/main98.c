#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R12,#8"); 
  __asm volatile("push	{R1}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R1, sp, #0"); 
  __asm volatile("str	R12, [R1, #4]"); 
  __asm volatile("movs	R9, #0"); 
  __asm volatile("str	R9, [R1, #20]"); 
  __asm volatile("movs	R9, #1"); 
  __asm volatile("str	R9, [R1, #16]"); 
  __asm volatile("movs	R9, #0"); 
  __asm volatile("str	R9, [R1, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R9, [R1, #8]"); 
  __asm volatile("cmp	R9, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R9, [R1, #8]"); 
  __asm volatile("str	R9, [R1, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R11, [R1, #20]"); 
  __asm volatile("ldr	R9, [R1, #16]"); 
  __asm volatile("add	R9, R11"); 
  __asm volatile("str	R9, [R1, #12]"); 
  __asm volatile("ldr	R9, [R1, #16]"); 
  __asm volatile("str	R9, [R1, #20]"); 
  __asm volatile("ldr	R9, [R1, #12]"); 
  __asm volatile("str	R9, [R1, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R9, [R1, #8]"); 
  __asm volatile("adds	R9, #1"); 
  __asm volatile("str	R9, [R1, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R11, [R1, #8]"); 
  __asm volatile("ldr	R9, [R1, #4]"); 
  __asm volatile("cmp	R11, R9"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R9, [R1, #12]"); 
  __asm volatile("mov	R12, R9"); 
  __asm volatile("adds	R1, #28"); 
  __asm volatile("mov	sp, R1"); 
  __asm volatile("ldr.w	R1, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
