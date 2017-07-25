#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x2c"); 
  __asm volatile("mov R11,#0x12"); 
  __asm volatile("LSL R9, R4, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
