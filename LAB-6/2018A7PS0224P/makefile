compRecMS : mergeSortRec.c merge.c helper.c merge.h helper.h
	@gcc -o rec mergeSortRec.c merge.c helper.c

compIterMS : mergeSortIter.c merge.c helper.c merge.h helper.h
	@gcc -o iter mergeSortIter.c merge.c helper.c

runRecMS : compRecMS 
	@./rec 1024.txt 2048.txt 4096.txt 5120.txt 10240.txt

runIterMS : compIterMS
	@./iter 1024.txt 2048.txt 4096.txt 5120.txt 10240.txt

compare : compIterMS compRecMS
	@python plot.py