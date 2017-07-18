#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x51"); 
  __asm volatile("ADCS R12, R10, #0x52");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
