#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xc0"); 
  __asm volatile("mov R12,#0x2c"); 
  __asm volatile("ADD R2, R10, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
