#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x5b"); 
  __asm volatile("LSL R0, R4, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
