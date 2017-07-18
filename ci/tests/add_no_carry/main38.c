#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xb7"); 
  __asm volatile("mov R11,#0xf0"); 
  __asm volatile("ADDS R3, R4, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
