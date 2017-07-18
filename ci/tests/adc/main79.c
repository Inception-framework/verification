#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xa2"); 
  __asm volatile("mov R5,#0x12"); 
  __asm volatile("ADCS R0, R5, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
