#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x6f"); 
  __asm volatile("ADDS R7, R5, #0x47");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
