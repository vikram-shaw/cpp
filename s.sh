for((i = 1; ; ++i)); do
	echo $i
	./generator $i > input
	./july20b/chfnswaps < input > out2
	./july20b/temp < input > out1
	diff out1 out2 || break
done
