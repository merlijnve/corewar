# bad op byte
./test.sh -c 5,6 "00 03 70 01"
./test.sh -c 5,6 "FF 03 70 01"
./test.sh -c 5,6 "10 03 70 01"
./test.sh -c 14,15 "00 11 21 80 81 F1 B0 A3 AE FF 03 70 01"

# bad register number
./test.sh -c 9,10 "02 D0 00 00 00 03 70 01"
./test.sh -c 9,10 "02 D0 00 00 11 03 70 01"
./test.sh -c 9,10 "03 70 00 00 00 03 70 01"
./test.sh -c 9,10 "03 50 11 01 03 70 01"
./test.sh -c 14,15 "04 54 00 02 01 03 70 01"
./test.sh -c 14,15 "04 54 01 11 01 03 70 01"
./test.sh -c 14,15 "04 54 01 01 41 03 70 01"
./test.sh -c 14,15 "05 54 00 02 01 03 70 01"
./test.sh -c 14,15 "05 54 01 11 01 03 70 01"
./test.sh -c 14,15 "05 54 01 01 41 03 70 01"
./test.sh -c 10,11 "06 74 00 00 00 01 03 70 01"
./test.sh -c 10,11 "06 94 00 00 00 00 11 01 03 70 01"
./test.sh -c 10,11,36 "06 E4 FF FC 00 00 00 00 41 03 70 01 00 00 09 00 06 03 70 01"
./test.sh -c 10,11 "07 54 11 0F 01 03 70 01"
./test.sh -c 10,11 "07 94 00 00 00 00 41 01 03 70 01"
./test.sh -c 10,11,36 "07 A4 00 00 00 00 00 00 00 00 00 03 70 01 00 00 09 00 06 03 70 01"
./test.sh -c 10,11 "08 64 41 12 34 56 78 01 03 70 01"
./test.sh -c 10,11 "08 D4 00 00 00 01 03 70 01"
./test.sh -c 10,11,36 "08 B4 00 00 00 00 FF FC 11 03 70 01 00 00 09 00 06 03 70 01"
./test.sh -c 29,30 "0A 64 41 00 00 01 03 70 01"
./test.sh -c 29,30 "0A D4 00 00 11 01 03 70 01"
./test.sh -c 29,30,55 "0A A4 00 00 FF FC 00 03 70 01 00 00 09 00 06 03 70 01"
./test.sh -c 29,30 "0B 68 00 00 FF FC 00 03 70 01"
./test.sh -c 29,30 "0B 58 01 11 00 00 03 70 01"
./test.sh -c 29,30 "0B 74 01 00 00 41 03 70 01"
./test.sh -c 14,15 "0D D0 00 00 00 03 70 01"
./test.sh -c 14,15,40 "0D 90 00 00 00 00 11 03 70 01 00 00 09 00 06 03 70 01"
./test.sh -c 54,55 "0E 64 41 00 00 01 03 70 01"
./test.sh -c 54,55 "0E D4 00 00 11 01 03 70 01"
./test.sh -c 54,55,80 "0E A4 00 00 FF FC 00 03 70 01 00 00 09 00 06 03 70 01"
./test.sh -c 6,7 "10 40 00 03 70 01"
./test.sh -c 6,7 "10 40 11 03 70 01"

# bad ACB
./test.sh -c 6,7 "10 00 03 70 01"
./test.sh -c 30,31 "06 00 09 0A 0F 03 70 0F"
./test.sh -c 10,11 "06 50 09 0A 03 70 03"
./test.sh -c 10,11 "06 55 09 0A 0F 03 70 0F"
./test.sh -c 29,30 "0B 6C 01 00 00 00 00 03 70 01"
./test.sh -c 29,30 "0B 5C 09 0A 00 00 03 70 01"
./test.sh -c 49,50 "0A 78 02 02 02 02 02 09 00 06 03 70 02"
./test.sh -c 6,7 "10 AA 00 00 00 00 03 70 01"
./test.sh -c 6,7 "10 E8 00 00 03 70 01"
./test.sh -c 54,55 "0E B0 00 00 00 00 03 70 01"
./test.sh -c 34,35 "05 AA 03 03 03 03 03 03 03 03 03 03 03 03 09 00 06 03 70 03"
./test.sh -c 14,15 "05 F5 00 00 00 00 00 03 70 01"
