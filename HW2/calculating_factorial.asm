load R6,48

load R0,0   
load R1,1
load R2,0  ;R2 is result of factorial process
load R3,0
load R4,1 
load R5,3  ;R5 register is assigned to factorial value. You can change to calculate factorial of a value

jmpEQ R5=R0,zero_one_value  ;If factorial zero or one result is will be one.
load R0,1
jmpEQ R5=R0,zero_one_value   
load R0,2 

next: 
addi R2,R2,R1   ;R3 is number repeating of loop, R2 is result of factorial
addi R3,R3,R4
jmpEQ R3=R0,increase 
jmp next
increase:
jmpEQ R5=R0,finish 
load R1,0
addi R1,R1,R2
load R3,0
load R2,0
addi R0,R0,R4
jmp next

finish:
move R7,R2;Resullt of factorial is stored in R7
addi R7,R7,R6
move RF,R7
halt
zero_one_value:
load R7,1
addi R7,R7,R6
move RF,R7
halt


