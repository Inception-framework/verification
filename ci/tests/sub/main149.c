#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0xad"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x70"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x27"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xcf"); 
  __asm volatile("SUB R11, R10, #0x775");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
