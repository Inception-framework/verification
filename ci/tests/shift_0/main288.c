#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x16"); 
  __asm volatile("LSL R12, R2, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
