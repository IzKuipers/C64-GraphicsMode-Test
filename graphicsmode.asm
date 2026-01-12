; Compiled with 1.32.266.0
--------------------------------------------------------------------
startup: ; startup
0801 : 0b __ __ INV
0802 : 08 __ __ PHP
0803 : 0a __ __ ASL
0804 : 00 __ __ BRK
0805 : 9e __ __ INV
0806 : 32 __ __ INV
0807 : 30 36 __ BMI $083f ; (startup + 62)
0809 : 31 00 __ AND ($00),y 
080b : 00 __ __ BRK
080c : 00 __ __ BRK
080d : ba __ __ TSX
080e : 8e d2 0a STX $0ad2 ; (spentry + 0)
0811 : a2 0b __ LDX #$0b
0813 : a0 38 __ LDY #$38
0815 : a9 00 __ LDA #$00
0817 : 85 19 __ STA IP + 0 
0819 : 86 1a __ STX IP + 1 
081b : e0 0b __ CPX #$0b
081d : f0 0b __ BEQ $082a ; (startup + 41)
081f : 91 19 __ STA (IP + 0),y 
0821 : c8 __ __ INY
0822 : d0 fb __ BNE $081f ; (startup + 30)
0824 : e8 __ __ INX
0825 : d0 f2 __ BNE $0819 ; (startup + 24)
0827 : 91 19 __ STA (IP + 0),y 
0829 : c8 __ __ INY
082a : c0 38 __ CPY #$38
082c : d0 f9 __ BNE $0827 ; (startup + 38)
082e : a9 00 __ LDA #$00
0830 : a2 f7 __ LDX #$f7
0832 : d0 03 __ BNE $0837 ; (startup + 54)
0834 : 95 00 __ STA $00,x 
0836 : e8 __ __ INX
0837 : e0 f7 __ CPX #$f7
0839 : d0 f9 __ BNE $0834 ; (startup + 51)
083b : a9 fe __ LDA #$fe
083d : 85 23 __ STA SP + 0 
083f : a9 9f __ LDA #$9f
0841 : 85 24 __ STA SP + 1 
0843 : 20 80 08 JSR $0880 ; (main.s4 + 0)
0846 : a9 4c __ LDA #$4c
0848 : 85 54 __ STA $54 
084a : a9 00 __ LDA #$00
084c : 85 13 __ STA P6 
084e : a9 19 __ LDA #$19
0850 : 85 16 __ STA P9 
0852 : 60 __ __ RTS
--------------------------------------------------------------------
main: ; main()->i16
;  30, "Y:/C64/graphicsmode/graphicsmode.c"
.s4:
0880 : 20 37 09 JSR $0937 ; (mmap_trampoline.s4 + 0)
0883 : a9 00 __ LDA #$00
0885 : 85 0f __ STA P2 
0887 : 85 10 __ STA P3 
0889 : a9 30 __ LDA #$30
088b : 85 01 __ STA $01 
088d : a9 40 __ LDA #$40
088f : 85 11 __ STA P4 
0891 : a9 1f __ LDA #$1f
0893 : 85 12 __ STA P5 
0895 : a9 01 __ LDA #$01
0897 : a2 fa __ LDX #$fa
.l6:
0899 : ca __ __ DEX
089a : 9d 00 d0 STA $d000,x 
089d : 9d fa d0 STA $d0fa,x 
08a0 : 9d f4 d1 STA $d1f4,x 
08a3 : 9d ee d2 STA $d2ee,x 
08a6 : d0 f1 __ BNE $0899 ; (main.l6 + 0)
.s5:
08a8 : a9 00 __ LDA #$00
08aa : 85 0d __ STA P0 
08ac : a9 e0 __ LDA #$e0
08ae : 85 0e __ STA P1 
08b0 : 20 81 09 JSR $0981 ; (memset.s4 + 0)
08b3 : a9 00 __ LDA #$00
08b5 : 85 10 __ STA P3 
08b7 : 85 0e __ STA P1 
08b9 : a9 35 __ LDA #$35
08bb : 85 01 __ STA $01 
08bd : a9 03 __ LDA #$03
08bf : 85 0d __ STA P0 
08c1 : a9 e0 __ LDA #$e0
08c3 : 85 11 __ STA P4 
08c5 : a9 d0 __ LDA #$d0
08c7 : 85 0f __ STA P2 
08c9 : 20 a5 09 JSR $09a5 ; (vic_setmode.s4 + 0)
08cc : a9 00 __ LDA #$00
08ce : 85 11 __ STA P4 
08d0 : 85 12 __ STA P5 
08d2 : 85 13 __ STA P6 
08d4 : 85 14 __ STA P7 
08d6 : a9 01 __ LDA #$01
08d8 : 85 16 __ STA P9 
08da : 8d 20 d0 STA $d020 
08dd : a9 40 __ LDA #$40
08df : 85 15 __ STA P8 
08e1 : 20 f7 09 JSR $09f7 ; (draw_hline.s4 + 0)
08e4 : a9 00 __ LDA #$00
08e6 : 85 11 __ STA P4 
08e8 : 85 12 __ STA P5 
08ea : a9 0c __ LDA #$0c
08ec : 85 13 __ STA P6 
08ee : a9 01 __ LDA #$01
08f0 : 85 16 __ STA P9 
08f2 : a9 40 __ LDA #$40
08f4 : 85 15 __ STA P8 
08f6 : 20 f7 09 JSR $09f7 ; (draw_hline.s4 + 0)
08f9 : a9 00 __ LDA #$00
08fb : 85 11 __ STA P4 
08fd : 85 12 __ STA P5 
08ff : a9 c7 __ LDA #$c7
0901 : 85 13 __ STA P6 
0903 : a9 01 __ LDA #$01
0905 : 85 16 __ STA P9 
0907 : a9 40 __ LDA #$40
0909 : 85 15 __ STA P8 
090b : 20 f7 09 JSR $09f7 ; (draw_hline.s4 + 0)
090e : a9 00 __ LDA #$00
0910 : 85 11 __ STA P4 
0912 : 85 12 __ STA P5 
0914 : 85 13 __ STA P6 
0916 : 85 16 __ STA P9 
0918 : a9 c8 __ LDA #$c8
091a : 85 15 __ STA P8 
091c : 20 8e 0a JSR $0a8e ; (draw_vline.s4 + 0)
091f : e6 12 __ INC P5 
0921 : a9 3f __ LDA #$3f
0923 : 85 11 __ STA P4 
0925 : a9 00 __ LDA #$00
0927 : 85 13 __ STA P6 
0929 : 85 14 __ STA P7 
092b : 85 16 __ STA P9 
092d : a9 c8 __ LDA #$c8
092f : 85 15 __ STA P8 
0931 : 20 8e 0a JSR $0a8e ; (draw_vline.s4 + 0)
.l7:
0934 : 4c 34 09 JMP $0934 ; (main.l7 + 0)
--------------------------------------------------------------------
mmap_trampoline: ; mmap_trampoline()->void
;  18, "C:/Program Files/oscar64/include/c64/memmap.h"
.s4:
0937 : a9 4c __ LDA #$4c
0939 : 8d fa ff STA $fffa 
093c : a9 09 __ LDA #$09
093e : 8d fb ff STA $fffb 
0941 : a9 6a __ LDA #$6a
0943 : 8d fe ff STA $fffe 
0946 : a9 09 __ LDA #$09
0948 : 8d ff ff STA $ffff 
.s3:
094b : 60 __ __ RTS
--------------------------------------------------------------------
NMITrampoline: ; NMITrampoline
094c : 48 __ __ PHA
094d : 8a __ __ TXA
094e : 48 __ __ PHA
094f : a9 09 __ LDA #$09
0951 : 48 __ __ PHA
0952 : a9 63 __ LDA #$63
0954 : 48 __ __ PHA
0955 : ba __ __ TSX
0956 : bd 05 01 LDA $0105,x 
0959 : 48 __ __ PHA
095a : a6 01 __ LDX $01 
095c : a9 36 __ LDA #$36
095e : 85 01 __ STA $01 
0960 : 6c fa ff JMP ($fffa)
--------------------------------------------------------------------
DoneTrampoline: ; DoneTrampoline
0963 : 86 01 __ STX $01 
0965 : 68 __ __ PLA
0966 : aa __ __ TAX
0967 : 68 __ __ PLA
0968 : 40 __ __ RTI
0969 : 60 __ __ RTS
--------------------------------------------------------------------
IRQTrampoline: ; IRQTrampoline
096a : 48 __ __ PHA
096b : 8a __ __ TXA
096c : 48 __ __ PHA
096d : a9 09 __ LDA #$09
096f : 48 __ __ PHA
0970 : a9 63 __ LDA #$63
0972 : 48 __ __ PHA
0973 : ba __ __ TSX
0974 : bd 05 01 LDA $0105,x 
0977 : 48 __ __ PHA
0978 : a6 01 __ LDX $01 
097a : a9 36 __ LDA #$36
097c : 85 01 __ STA $01 
097e : 6c fe ff JMP ($fffe)
--------------------------------------------------------------------
memset: ; memset(void*,i16,i16)->void*
;  28, "C:/Program Files/oscar64/include/string.h"
.s4:
0981 : a5 0f __ LDA P2 
0983 : a6 12 __ LDX P5 
0985 : f0 0c __ BEQ $0993 ; (memset.s4 + 18)
0987 : a0 00 __ LDY #$00
0989 : 91 0d __ STA (P0),y ; (dst + 0)
098b : c8 __ __ INY
098c : d0 fb __ BNE $0989 ; (memset.s4 + 8)
098e : e6 0e __ INC P1 ; (dst + 1)
0990 : ca __ __ DEX
0991 : d0 f6 __ BNE $0989 ; (memset.s4 + 8)
0993 : a4 11 __ LDY P4 
0995 : f0 05 __ BEQ $099c ; (memset.s4 + 27)
0997 : 88 __ __ DEY
0998 : 91 0d __ STA (P0),y ; (dst + 0)
099a : d0 fb __ BNE $0997 ; (memset.s4 + 22)
099c : a5 0d __ LDA P0 ; (dst + 0)
099e : 85 1b __ STA ACCU + 0 
09a0 : a5 0e __ LDA P1 ; (dst + 1)
09a2 : 85 1c __ STA ACCU + 1 
.s3:
09a4 : 60 __ __ RTS
--------------------------------------------------------------------
vic_setmode: ; vic_setmode(enum VicMode,const u8*,const u8*)->void
;  94, "C:/Program Files/oscar64/include/c64/vic.h"
.s4:
09a5 : a4 0d __ LDY P0 ; (mode + 0)
09a7 : c0 02 __ CPY #$02
09a9 : d0 09 __ BNE $09b4 ; (vic_setmode.s5 + 0)
.s10:
09ab : a9 5b __ LDA #$5b
09ad : 8d 11 d0 STA $d011 
.s8:
09b0 : a9 08 __ LDA #$08
09b2 : d0 0c __ BNE $09c0 ; (vic_setmode.s7 + 0)
.s5:
09b4 : b0 36 __ BCS $09ec ; (vic_setmode.s6 + 0)
.s9:
09b6 : a9 1b __ LDA #$1b
09b8 : 8d 11 d0 STA $d011 
09bb : 98 __ __ TYA
09bc : f0 f2 __ BEQ $09b0 ; (vic_setmode.s8 + 0)
.s11:
09be : a9 18 __ LDA #$18
.s7:
09c0 : 8d 16 d0 STA $d016 
09c3 : ad 00 dd LDA $dd00 
09c6 : 29 fc __ AND #$fc
09c8 : 85 1b __ STA ACCU + 0 
09ca : a5 0f __ LDA P2 ; (text + 1)
09cc : 0a __ __ ASL
09cd : 2a __ __ ROL
09ce : 29 01 __ AND #$01
09d0 : 2a __ __ ROL
09d1 : 49 03 __ EOR #$03
09d3 : 05 1b __ ORA ACCU + 0 
09d5 : 8d 00 dd STA $dd00 
09d8 : a5 0f __ LDA P2 ; (text + 1)
09da : 29 3c __ AND #$3c
09dc : 0a __ __ ASL
09dd : 0a __ __ ASL
09de : 85 1b __ STA ACCU + 0 
09e0 : a5 11 __ LDA P4 ; (font + 1)
09e2 : 29 38 __ AND #$38
09e4 : 4a __ __ LSR
09e5 : 4a __ __ LSR
09e6 : 05 1b __ ORA ACCU + 0 
09e8 : 8d 18 d0 STA $d018 
.s3:
09eb : 60 __ __ RTS
.s6:
09ec : a9 3b __ LDA #$3b
09ee : 8d 11 d0 STA $d011 
09f1 : c0 03 __ CPY #$03
09f3 : d0 c9 __ BNE $09be ; (vic_setmode.s11 + 0)
09f5 : f0 b9 __ BEQ $09b0 ; (vic_setmode.s8 + 0)
--------------------------------------------------------------------
draw_hline: ; draw_hline(i16,i16,i16)->void
;  18, "Y:/C64/graphicsmode/graphicsmode.c"
.s4:
09f7 : 18 __ __ CLC
09f8 : a5 15 __ LDA P8 ; (len + 0)
09fa : 65 11 __ ADC P4 ; (x + 0)
09fc : 85 15 __ STA P8 ; (len + 0)
09fe : a5 16 __ LDA P9 ; (len + 1)
0a00 : 65 12 __ ADC P5 ; (x + 1)
0a02 : 85 16 __ STA P9 ; (len + 1)
0a04 : a5 12 __ LDA P5 ; (x + 1)
0a06 : c5 16 __ CMP P9 ; (len + 1)
0a08 : f0 2a __ BEQ $0a34 ; (draw_hline.l9 + 0)
.s7:
0a0a : 45 16 __ EOR P9 ; (len + 1)
0a0c : 10 2a __ BPL $0a38 ; (draw_hline.l8 + 0)
.s6:
0a0e : 90 2a __ BCC $0a3a ; (draw_hline.s3 + 0)
.l5:
0a10 : a5 11 __ LDA P4 ; (x + 0)
0a12 : 85 0d __ STA P0 
0a14 : a5 12 __ LDA P5 ; (x + 1)
0a16 : 85 0e __ STA P1 
0a18 : a5 13 __ LDA P6 ; (y + 0)
0a1a : 85 0f __ STA P2 
0a1c : a5 14 __ LDA P7 ; (y + 1)
0a1e : 85 10 __ STA P3 
0a20 : 20 3b 0a JSR $0a3b ; (set.s4 + 0)
0a23 : 18 __ __ CLC
0a24 : a5 0d __ LDA P0 
0a26 : 69 01 __ ADC #$01
0a28 : 85 11 __ STA P4 ; (x + 0)
0a2a : a5 0e __ LDA P1 
0a2c : 69 00 __ ADC #$00
0a2e : 85 12 __ STA P5 ; (x + 1)
0a30 : c5 16 __ CMP P9 ; (len + 1)
0a32 : d0 d6 __ BNE $0a0a ; (draw_hline.s7 + 0)
.l9:
0a34 : a5 11 __ LDA P4 ; (x + 0)
0a36 : c5 15 __ CMP P8 ; (len + 0)
.l8:
0a38 : 90 d6 __ BCC $0a10 ; (draw_hline.l5 + 0)
.s3:
0a3a : 60 __ __ RTS
--------------------------------------------------------------------
set: ; set(i16,i16)->void
;   9, "Y:/C64/graphicsmode/graphicsmode.c"
.s4:
0a3b : a5 0e __ LDA P1 ; (x + 1)
0a3d : a6 0d __ LDX P0 ; (x + 0)
0a3f : c9 01 __ CMP #$01
0a41 : d0 02 __ BNE $0a45 ; (set.s9 + 0)
.s8:
0a43 : e0 40 __ CPX #$40
.s9:
0a45 : b0 46 __ BCS $0a8d ; (set.s3 + 0)
.s5:
0a47 : a5 10 __ LDA P3 ; (y + 1)
0a49 : d0 42 __ BNE $0a8d ; (set.s3 + 0)
.s7:
0a4b : a5 0f __ LDA P2 ; (y + 0)
0a4d : c9 c8 __ CMP #$c8
0a4f : b0 3c __ BCS $0a8d ; (set.s3 + 0)
.s6:
0a51 : 8a __ __ TXA
0a52 : 29 07 __ AND #$07
0a54 : a8 __ __ TAY
0a55 : b9 20 0b LDA $0b20,y ; (bitshift[0] + 32)
0a58 : 85 1d __ STA ACCU + 2 
0a5a : a5 0f __ LDA P2 ; (y + 0)
0a5c : 29 07 __ AND #$07
0a5e : 85 1c __ STA ACCU + 1 
0a60 : a5 0f __ LDA P2 ; (y + 0)
0a62 : 29 f8 __ AND #$f8
0a64 : 85 1b __ STA ACCU + 0 
0a66 : 4a __ __ LSR
0a67 : 4a __ __ LSR
0a68 : 65 1b __ ADC ACCU + 0 
0a6a : 4a __ __ LSR
0a6b : 6a __ __ ROR
0a6c : 6a __ __ ROR
0a6d : a8 __ __ TAY
0a6e : 29 c0 __ AND #$c0
0a70 : 6a __ __ ROR
0a71 : 05 1c __ ORA ACCU + 1 
0a73 : 85 1b __ STA ACCU + 0 
0a75 : 8a __ __ TXA
0a76 : 29 f8 __ AND #$f8
0a78 : 65 1b __ ADC ACCU + 0 
0a7a : 85 1b __ STA ACCU + 0 
0a7c : 98 __ __ TYA
0a7d : 29 1f __ AND #$1f
0a7f : 09 e0 __ ORA #$e0
0a81 : 65 0e __ ADC P1 ; (x + 1)
0a83 : 85 1c __ STA ACCU + 1 
0a85 : a0 00 __ LDY #$00
0a87 : b1 1b __ LDA (ACCU + 0),y 
0a89 : 05 1d __ ORA ACCU + 2 
0a8b : 91 1b __ STA (ACCU + 0),y 
.s3:
0a8d : 60 __ __ RTS
--------------------------------------------------------------------
draw_vline: ; draw_vline(i16,i16,i16)->void
;  24, "Y:/C64/graphicsmode/graphicsmode.c"
.s4:
0a8e : 18 __ __ CLC
0a8f : a5 15 __ LDA P8 ; (len + 0)
0a91 : 65 13 __ ADC P6 ; (y + 0)
0a93 : 85 15 __ STA P8 ; (len + 0)
0a95 : a5 16 __ LDA P9 ; (len + 1)
0a97 : 65 14 __ ADC P7 ; (y + 1)
0a99 : 85 16 __ STA P9 ; (len + 1)
0a9b : a5 14 __ LDA P7 ; (y + 1)
0a9d : c5 16 __ CMP P9 ; (len + 1)
0a9f : f0 2a __ BEQ $0acb ; (draw_vline.l9 + 0)
.s7:
0aa1 : 45 16 __ EOR P9 ; (len + 1)
0aa3 : 10 2a __ BPL $0acf ; (draw_vline.l8 + 0)
.s6:
0aa5 : 90 2a __ BCC $0ad1 ; (draw_vline.s3 + 0)
.l5:
0aa7 : a5 11 __ LDA P4 ; (x + 0)
0aa9 : 85 0d __ STA P0 
0aab : a5 12 __ LDA P5 ; (x + 1)
0aad : 85 0e __ STA P1 
0aaf : a5 13 __ LDA P6 ; (y + 0)
0ab1 : 85 0f __ STA P2 
0ab3 : a5 14 __ LDA P7 ; (y + 1)
0ab5 : 85 10 __ STA P3 
0ab7 : 20 3b 0a JSR $0a3b ; (set.s4 + 0)
0aba : 18 __ __ CLC
0abb : a5 0f __ LDA P2 
0abd : 69 01 __ ADC #$01
0abf : 85 13 __ STA P6 ; (y + 0)
0ac1 : a5 10 __ LDA P3 
0ac3 : 69 00 __ ADC #$00
0ac5 : 85 14 __ STA P7 ; (y + 1)
0ac7 : c5 16 __ CMP P9 ; (len + 1)
0ac9 : d0 d6 __ BNE $0aa1 ; (draw_vline.s7 + 0)
.l9:
0acb : a5 13 __ LDA P6 ; (y + 0)
0acd : c5 15 __ CMP P8 ; (len + 0)
.l8:
0acf : 90 d6 __ BCC $0aa7 ; (draw_vline.l5 + 0)
.s3:
0ad1 : 60 __ __ RTS
--------------------------------------------------------------------
spentry:
0ad2 : __ __ __ BYT 00                                              : .
--------------------------------------------------------------------
bitshift:
0b00 : __ __ __ BYT 00 00 00 00 00 00 00 00 01 02 04 08 10 20 40 80 : ............. @.
0b10 : __ __ __ BYT 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 : ................
0b20 : __ __ __ BYT 80 40 20 10 08 04 02 01 00 00 00 00 00 00 00 00 : .@ .............
0b30 : __ __ __ BYT 00 00 00 00 00 00 00 00                         : ........
