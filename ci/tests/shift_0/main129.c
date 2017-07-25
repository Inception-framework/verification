#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x97"); 
  __asm volatile("mov R12,#0x08"); 
  __asm volatile("LSL R10, R1, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
