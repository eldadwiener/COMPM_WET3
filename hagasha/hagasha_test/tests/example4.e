COPYI I1 0
COPYI I2 0
COPYI I3 0
COPYI I4 0
COPYI I5 0
COPYI I6 0
COPYI I7 0
JLINK 10
HALT
PRNTC 10
PRNTC 77
PRNTC 111
PRNTC 111
PRNTC 100
PRNTC 108
PRNTC 101
PRNTC 32
PRNTC 84
PRNTC 101
PRNTC 115
PRNTC 116
PRNTC 32
PRNTC 52
PRNTC 32
PRNTC 40
PRNTC 105
PRNTC 102
PRNTC 32
PRNTC 116
PRNTC 104
PRNTC 101
PRNTC 110
PRNTC 32
PRNTC 101
PRNTC 108
PRNTC 115
PRNTC 101
PRNTC 41
PRNTC 10
ADD2I I2 I2 4
ADD2I I2 I2 4
READF F0
CITOF F1 I1
STORF F0 F1 0
READF F0
CITOF F1 I1
STORF F0 F1 4
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
PRNTC 116
PRNTC 104
PRNTC 101
PRNTC 32
PRNTC 115
PRNTC 109
PRNTC 97
PRNTC 108
PRNTC 108
PRNTC 101
PRNTC 114
PRNTC 32
PRNTC 110
PRNTC 117
PRNTC 109
PRNTC 98
PRNTC 101
PRNTC 114
PRNTC 58
PRNTC 32
CITOF F0 I1
LOADF F0 F0 0
CITOF F1 I1
LOADF F1 F1 4
SLETF F2 F0 F1
CFTOI I3 F2
BNEQZ I3 86
UJUMP 90
CITOF F2 I1
LOADF F2 F2 0
PRNTF F2
UJUMP 93
CITOF F3 I1
LOADF F3 F3 4
PRNTF F3
PRNTC 10
PRNTC 69
PRNTC 120
PRNTC 97
PRNTC 109
PRNTC 112
PRNTC 108
PRNTC 101
PRNTC 32
PRNTC 100
PRNTC 111
PRNTC 110
PRNTC 101
PRNTC 10
COPYI I2 I1
RETRN
HALT
