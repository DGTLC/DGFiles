#!/bin/sh
echo Usuwanie starych hashy...
rm base_d.txt base_f.txt low_d.txt low_f.txt normal_d.txt normal_f.txt high_d.txt high_f.txt
echo Hashowanie base...
./generateFiles base/
mv d.txt base_d.txt
mv f.txt base_f.txt
echo Hashowanie low...
./generateFiles low/
mv d.txt low_d.txt
mv f.txt low_f.txt
echo Hashowanie normal...
./generateFiles normal/
mv d.txt normal_d.txt
mv f.txt normal_f.txt
echo Hashowanie high...
./generateFiles high/
mv d.txt high_d.txt
mv f.txt high_f.txt
