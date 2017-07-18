#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x95"); 
  __asm volatile("mov R5,#0xd6"); 
  __asm volatile("ADDS R12, R2, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
