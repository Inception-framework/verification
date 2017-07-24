#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x5f"); 
  __asm volatile("LSL R2, R3, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
