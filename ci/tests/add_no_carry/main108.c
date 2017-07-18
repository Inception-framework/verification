#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x4c"); 
  __asm volatile("mov R10,#0xeb"); 
  __asm volatile("ADDS R2, R12, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
