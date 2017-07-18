#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x3c"); 
  __asm volatile("mov R8,#0x7f"); 
  __asm volatile("ADDS R8, R5, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
