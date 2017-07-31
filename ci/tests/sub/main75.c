#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0xc8"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xbf"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x23"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xfb"); 
  __asm volatile("SUB R0, R8, #0xc2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
