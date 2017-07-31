#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0"); 
  __asm volatile("add R4,R4,#0xa2"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0xcb"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x5f"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x38"); 
  __asm volatile("SUB R4, R4, #0x5e3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
