#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xa2"); 
  __asm volatile("ADDS R0, R5, #0xa4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
