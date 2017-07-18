#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x09"); 
  __asm volatile("mov R0,#0x14"); 
  __asm volatile("ADDS R2, R4, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
