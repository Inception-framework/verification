#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x42"); 
  __asm volatile("mov R4,#0x3a"); 
  __asm volatile("ADDS R6, R8, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
