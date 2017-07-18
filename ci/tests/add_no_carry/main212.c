#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x47"); 
  __asm volatile("ADDS R10, R0, #0x20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
