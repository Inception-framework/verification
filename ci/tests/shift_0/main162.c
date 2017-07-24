#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x4e"); 
  __asm volatile("LSL R8, R9, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
