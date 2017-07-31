#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0xb5"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x81"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x6b"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x74"); 
  __asm volatile("SUB R12, R10, #0x54d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
