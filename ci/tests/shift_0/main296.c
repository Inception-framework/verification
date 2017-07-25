#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x4f"); 
  __asm volatile("LSL R0, R9, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
