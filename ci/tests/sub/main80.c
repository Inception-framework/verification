#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0xc1"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x2e"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xa9"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xb8"); 
  __asm volatile("SUB R8, R8, #0x944");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
