#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xb9"); 
  __asm volatile("mov R5,#0xf2"); 
  __asm volatile("ADCS R0, R3, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
