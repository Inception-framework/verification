#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x9b"); 
  __asm volatile("ADCS R7, R4, #0xd0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
