#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xa4"); 
  __asm volatile("ADCS R0, R6, #0xe1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
