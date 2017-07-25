#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xfc"); 
  __asm volatile("LSL R4, R7, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
