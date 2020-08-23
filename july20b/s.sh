for((i = 1; ; ++i)); do
	echo $i
	./generator $i > input
	./yy < input > out2
	./chfnswaps < input > out1
	diff out1 out2 || break
done
