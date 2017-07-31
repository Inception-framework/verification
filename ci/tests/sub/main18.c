#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0x46"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x74"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x37"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x41"); 
  __asm volatile("SUB R10, R9, #0xfc");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
