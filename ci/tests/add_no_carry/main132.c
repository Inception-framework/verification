#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x26"); 
  __asm volatile("ADDS R7, R5, #0x16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
