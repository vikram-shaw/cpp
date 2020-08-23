for((i = 1; ; ++i)); do
	echo $i
	./generator $i > input
	./chefwed < input > out2
	./chefwed_right < input > out1
	diff out1 out2 || break
done
