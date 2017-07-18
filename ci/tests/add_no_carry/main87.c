#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x2b"); 
  __asm volatile("ADDS R1, R12, #0x65");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
