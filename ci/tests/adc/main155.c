#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xc7"); 
  __asm volatile("mov R6,#0xfb"); 
  __asm volatile("ADCS R7, R5, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
