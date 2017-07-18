#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x24"); 
  __asm volatile("mov R4,#0xce"); 
  __asm volatile("ADCS R8, R11, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
