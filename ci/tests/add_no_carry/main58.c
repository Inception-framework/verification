#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x9f"); 
  __asm volatile("mov R7,#0x19"); 
  __asm volatile("ADDS R7, R5, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
