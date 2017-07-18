#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xe6"); 
  __asm volatile("ADDS R9, R4, #0xfc");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
