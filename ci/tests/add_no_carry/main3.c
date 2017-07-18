#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x30"); 
  __asm volatile("mov R9,#0x80"); 
  __asm volatile("ADDS R4, R2, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
