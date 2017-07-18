#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x1f"); 
  __asm volatile("mov R10,#0x0b"); 
  __asm volatile("ADDS R11, R12, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
