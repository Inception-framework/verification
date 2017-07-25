#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x15"); 
  __asm volatile("LSL R8, R2, 5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
