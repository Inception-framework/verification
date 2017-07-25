#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xbd"); 
  __asm volatile("mov R10,#0x03"); 
  __asm volatile("LSL R7, R10, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
