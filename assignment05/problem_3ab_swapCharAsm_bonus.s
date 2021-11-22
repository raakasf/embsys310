swapCharsAsm
    LDR R2, [R0]
    LDR R3, [R1]
    STRB R3, [R0]
    STRB R2, [R1]
    CMP R3, R2      // Compare R2 and R3
    BNE False       // If not equal, branch to False
    MOV R0, #0      // else move 0 in R0
    B Exit          // and Exit
False
    MOV R0, #1      // Move 1 in R0
Exit
    BX LR           // and return

    END