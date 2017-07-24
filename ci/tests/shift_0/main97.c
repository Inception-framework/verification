#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xcf"); 
  __asm volatile("mov R10,#0x1b"); 
  __asm volatile("LSL R2, R9, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
