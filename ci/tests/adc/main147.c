#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xfd"); 
  __asm volatile("mov R0,#0x6e"); 
  __asm volatile("ADCS R4, R2, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
