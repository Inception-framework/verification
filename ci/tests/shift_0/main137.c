#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xda"); 
  __asm volatile("mov R9,#0x1b"); 
  __asm volatile("LSL R1, R2, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
