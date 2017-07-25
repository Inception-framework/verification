#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x51"); 
  __asm volatile("mov R2,#0x15"); 
  __asm volatile("LSL R12, R0, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
