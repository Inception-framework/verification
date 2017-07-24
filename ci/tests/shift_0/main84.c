#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x2c"); 
  __asm volatile("LSL R12, R10, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
