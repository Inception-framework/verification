#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x6e"); 
  __asm volatile("LSL R8, R10, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
