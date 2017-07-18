#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xca"); 
  __asm volatile("ADCS R10, R1, #0x03");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
