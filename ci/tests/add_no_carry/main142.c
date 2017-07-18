#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x76"); 
  __asm volatile("ADDS R2, R0, #0xbb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
