#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xd2"); 
  __asm volatile("ADCS R12, R5, #0x12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
