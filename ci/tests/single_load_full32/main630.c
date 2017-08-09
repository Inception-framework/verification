#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("add r1,r1,#1025");
  __asm volatile("mov r2,sp");
  __asm volatile("loop:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("add r2,#1025");
  __asm volatile("lsl r2,#2");
  __asm volatile("add r2,sp");
  __asm volatile("loop2:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop2");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("mov R6,sp"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0xc9"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xd4"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xd0"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x20"); 
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0x6d"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x9d"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xee"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xee"); 
  __asm volatile("mov R2,#0"); 
  __asm volatile("add R2,R2,#0xeb"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0xe7"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x18"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0xdf"); 
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0x71"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x1c"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x71"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x8a"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0x00"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x00"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x00"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xfe"); 
  __asm volatile("LDR R2, [R6]");
  #ifndef KLEE
  __asm volatile("stop: b stop");
  #else
  __asm volatile("bx lr");
  #endif
}
