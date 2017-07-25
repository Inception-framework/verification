#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xc4"); 
  __asm volatile("mov R12,#0x1b"); 
  __asm volatile("LSL R8, R10, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
