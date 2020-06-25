./Cgen > C.in
./C < C.in > C.out
./Cb < C.out > Cb.out
diff C.in Cb.out
