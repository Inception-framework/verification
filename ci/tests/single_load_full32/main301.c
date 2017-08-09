#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R6,R6,#-1"); 
  __asm volatile("cmp R6,#0"); 
  __asm volatile("bvs loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
