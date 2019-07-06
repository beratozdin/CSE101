load R1,String
load R2,1
load R0,0
load R3,-1
load R4,[R1] ;R4 is stored starting adress of string
NextChar:load R5,[R1] ;Loop goes finishing adress of string
jmpEQ R5=R0,Ready
addi R1,R1,R2
jmp NextChar

Ready:
load R0,[R4] 
next:  ;Loop goes starting adress of string by starting final of string;
addi R1,R1,R3 
load RF,[R1]
jmpEQ RF=R0,jumpp
jmp next
jumpp:
halt

org 20h
String:
db "test"
db 0
