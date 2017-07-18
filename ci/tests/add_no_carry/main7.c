#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x68"); 
  __asm volatile("ADDS R5, R9, #0xf4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
