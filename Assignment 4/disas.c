#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * getReg(int n){
    switch(n){
        case 0b00000000:
            return "rax";
        case 0b00000001:
            return "rcx";
        case 0b00000010:
            return "rdx";
        case 0b00000011:
            return "rbx";
        case 0b00000100:
            return "rsp";
        case 0b00000101:
            return "rbp";
        case 0b00000110:
            return "rsi";
        case 0b00000111:
            return "rdi";
        default:
            return "DNE";
    }
}

void disassemble(const unsigned char *raw_instr){
    if(raw_instr[0] == 0b01101000){ //case 1
        for(int i = 0; i < 5; i++){ printf("%02x ", raw_instr[i]);}
        printf("    pushq $0x"); 
        for(int i = 2; i > 0; i--){ printf("%x", raw_instr[i]);}
        printf("\n");
    }
    else if((raw_instr[0] & 0b11111000) == 0b01010000){ //case 2
        //define
        int masked = raw_instr[1] & 0b00000111  ;  //0011 0010 & 00000111 == 0000 0010
        char * reg = getReg(masked);

        //print
        printf("%02x ", raw_instr[0]);
        printf("                pushq %%%s\n",reg);
        
    }
    else if(raw_instr[0] == 0b11111111){
        if(raw_instr[1]==0b01110100){ //case 5
            //define
            int scaledIndex = raw_instr[2] & 0b11000000; //blue
            int value = 0 ; //{1,2,4,8} --> 00,01,10,11
            switch(scaledIndex){
                case 0b00000000:
                    value = 1;
                case 0b01000000:
                    value = 2;
                case 0b10000000:
                    value = 3;
                case 0b11000000:
                    value = 4;
            }
            int masked1 = raw_instr[2] & 0b00000111  ;  //10001101 & 00000111 == 00000101
            char * reg1 = getReg(masked1);
            int masked2 = (raw_instr[2] & 0b00111000)>>3  ;  //10001101 & 00111000 == 00001000
            char * reg2 = getReg(masked2);

            //print
            for(int i = 0; i < 4; i++){ printf("%02x ", raw_instr[i]);}
            printf("       pushq %#x(%%%s,%%%s,%d)\n",raw_instr[0],reg1,reg2,value);

        }
        else if((0b11111000 & raw_instr[1]) == 0b00110000){ //case3 when 00110xxx
            //define
            int masked = raw_instr[1] & 0b00000111  ;  //0011 0010 & 00000111 == 0000 0010
            char * reg = getReg(masked);

            //print
            for(int i = 0; i < 2; i++){ printf("%02x ", raw_instr[i]);}
            printf("             pushq (%%%s)\n",reg);
        }
        else{ //case 4 when 01110xxx
            //define
            int masked = raw_instr[1] & 0b00000111  ;  //0011 0010 & 00000111 == 0000 0010
            char * reg = getReg(masked);

            //print
            for(int i = 0; i < 3; i++){ printf("%02x ", raw_instr[i]);}
            printf("          pushq %#x(%%%s)\n",raw_instr[2],reg);
        }    
    }
    else{
        printf("DNE");
    }
}

int main()
{
    // pushq $0x3f10
    unsigned char inst1[5] = {0x68,0x10,0x3f,0x00,0x00};
    // pushq %rbx
    inst2[1] = {0x53};
    // pushq (%rdx)
    unsigned char inst3[2] = {0xff, 0x32};
    // pushq 0x8(%rax)
    unsigned char inst4[3] = {0xff, 0x70, 0x08};
    // pushq 0xff(%rbp,%rcx,4)
    unsigned char inst5[4] = {0xff, 0x74, 0x8d, 0xff};
    disassemble(inst1);
    disassemble(inst2);
    disassemble(inst3);
    disassemble(inst4);
    disassemble(inst5);

    return 0;
}
