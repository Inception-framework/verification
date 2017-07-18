#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x4b"); 
  __asm volatile("mov R4,#0x4f"); 
  __asm volatile("ADDS R0, R8, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
