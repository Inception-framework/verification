#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x4a"); 
  __asm volatile("mov R11,#0x70"); 
  __asm volatile("ADCS R1, R12, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
