COPYI I1 0
COPYI I2 0
COPYI I3 0
COPYI I4 0
COPYI I5 0
COPYI I6 0
COPYI I7 0
JLINK 24
HALT
CITOF F0 I1
LOADF F0 F0 -16
CITOF F1 I1
LOADF F1 F1 -20
ADD2F F0 F0 F1
PRNTF F0
LOADI I3 I1 -8
LOADI I4 I1 -12
ADD2I I3 I3 I4
STORI I3 I1 -4
COPYI I2 I1
RETRN
COPYI I2 I1
RETRN
PRNTC 10
PRNTC 84
PRNTC 101
PRNTC 115
PRNTC 116
PRNTC 58
PRNTC 32
PRNTC 99
PRNTC 104
PRNTC 101
PRNTC 99
PRNTC 107
PRNTC 32
PRNTC 109
PRNTC 117
PRNTC 108
PRNTC 116
PRNTC 105
PRNTC 112
PRNTC 108
PRNTC 101
PRNTC 32
PRNTC 100
PRNTC 101
PRNTC 102
PRNTC 105
PRNTC 110
PRNTC 105
PRNTC 116
PRNTC 105
PRNTC 111
PRNTC 110
PRNTC 115
PRNTC 32
PRNTC 111
PRNTC 102
PRNTC 32
PRNTC 115
PRNTC 97
PRNTC 109
PRNTC 101
PRNTC 32
PRNTC 116
PRNTC 121
PRNTC 112
PRNTC 101
PRNTC 32
PRNTC 10
ADD2I I2 I2 12
ADD2I I2 I2 12
COPYI I3 1
STORI I3 I1 0
COPYI I4 2
STORI I4 I1 4
LOADI I5 I1 0
LOADI I6 I1 4
ADD2I I5 I5 I6
STORI I5 I1 8
PRNTC 115
PRNTC 104
PRNTC 111
PRNTC 117
PRNTC 108
PRNTC 100
PRNTC 32
PRNTC 98
PRNTC 101
PRNTC 32
PRNTC 51
PRNTC 58
PRNTC 32
LOADI I7 I1 8
PRNTI I7
PRNTC 10
COPYF F0 1.2
CITOF F1 I1
STORF F0 F1 12
COPYF F1 2.4
CITOF F2 I1
STORF F1 F2 16
CITOF F2 I1
LOADF F2 F2 12
CITOF F3 I1
LOADF F3 F3 16
ADD2F F2 F2 F3
CITOF F4 I1
STORF F2 F4 20
PRNTC 115
PRNTC 104
PRNTC 111
PRNTC 117
PRNTC 108
PRNTC 100
PRNTC 32
PRNTC 98
PRNTC 101
PRNTC 32
PRNTC 51
PRNTC 46
PRNTC 54
PRNTC 58
PRNTC 32
CITOF F4 I1
LOADF F4 F4 20
PRNTF F4
PRNTC 10
PRNTC 115
PRNTC 104
PRNTC 111
PRNTC 117
PRNTC 108
PRNTC 100
PRNTC 32
PRNTC 98
PRNTC 101
PRNTC 32
PRNTC 51
PRNTC 46
PRNTC 54
PRNTC 58
PRNTC 32
LOADI I8 I1 0
LOADI I9 I1 4
CITOF F5 I1
LOADF F5 F5 12
CITOF F6 I1
LOADF F6 F6 16
STORI I0 I2 0
STORI I1 I2 4
STORI I2 I2 8
STORI I3 I2 12
STORI I4 I2 16
STORI I5 I2 20
STORI I6 I2 24
STORI I7 I2 28
STORI I8 I2 32
STORI I9 I2 36
CITOF F7 I2
STORF F0 F7 40
STORF F1 F7 44
STORF F2 F7 48
STORF F3 F7 52
STORF F4 F7 56
STORF F5 F7 60
STORF F6 F7 64
STORF F6 F7 68
STORF F5 F7 72
STORI I9 I2 76
STORI I8 I2 80
ADD2I I2 I2 88
COPYI I1 I2
JLINK 10
SUBTI I2 I2 88
LOADI I0 I2 0
LOADI I1 I2 4
LOADI I2 I2 8
LOADI I3 I2 12
LOADI I4 I2 16
LOADI I5 I2 20
LOADI I6 I2 24
LOADI I7 I2 28
LOADI I8 I2 32
LOADI I9 I2 36
CITOF F7 I2
LOADF F0 F7 40
LOADF F1 F7 44
LOADF F2 F7 48
LOADF F3 F7 52
LOADF F4 F7 56
LOADF F5 F7 60
LOADF F6 F7 64
LOADI I10 I2 84
STORI I10 I1 0
PRNTC 10
PRNTC 115
PRNTC 104
PRNTC 111
PRNTC 117
PRNTC 108
PRNTC 100
PRNTC 32
PRNTC 98
PRNTC 101
PRNTC 32
PRNTC 51
PRNTC 58
PRNTC 32
LOADI I11 I1 0
PRNTI I11
PRNTC 10
COPYI I2 I1
RETRN
HALT