#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x0c"); 
  __asm volatile("mov R12,#0x42"); 
  __asm volatile("ADDS R9, R10, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
