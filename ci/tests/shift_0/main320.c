#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xdf"); 
  __asm volatile("LSL R4, R4, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
