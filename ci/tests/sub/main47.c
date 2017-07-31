#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0x9c"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xb0"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x17"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xc1"); 
  __asm volatile("SUB R10, R8, #0x618");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
