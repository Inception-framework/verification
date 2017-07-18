#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x5b"); 
  __asm volatile("ADDS R5, R8, #0x6a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
