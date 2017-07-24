#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x04"); 
  __asm volatile("LSL R9, R4, 8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
