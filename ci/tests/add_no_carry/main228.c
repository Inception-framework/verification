#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x7f"); 
  __asm volatile("mov R7,#0x70"); 
  __asm volatile("ADDS R0, R2, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
