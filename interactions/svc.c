__attribute__((naked))
void trig() {
  __asm volatile("MOV R0, #0"); //set R0
  __asm volatile("MOV R1, #1"); //set R1
  __asm volatile("MOV R2, #2"); //set R2
  __asm volatile("MOV R3, #3"); //set R3
  __asm volatile("MOV R12, #3"); //set R12
  __asm volatile("svc #0");
  __asm volatile("bx lr");
}

__attribute__((naked))
void SVC_Handler() {
  __asm volatile("LDR R1, [SP, #24]"); //get PC
  // __asm volatile("LDR R1, [R1, #-2]"); //get imm8
  __asm volatile("bx lr");
}

void main() {
  trig();
}

