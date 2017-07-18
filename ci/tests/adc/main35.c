#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xd1"); 
  __asm volatile("mov R9,#0x9f"); 
  __asm volatile("ADCS R0, R7, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
