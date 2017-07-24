#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x91"); 
  __asm volatile("LSL R9, R1, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
