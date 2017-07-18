#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xbb"); 
  __asm volatile("mov R9,#0x15"); 
  __asm volatile("ADCS R8, R5, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
