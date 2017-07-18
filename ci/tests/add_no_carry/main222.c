#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x04"); 
  __asm volatile("ADDS R8, R1, #0xeb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
