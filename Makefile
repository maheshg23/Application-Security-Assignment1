giftcardreader: giftcardreader.c
	gcc -o giftcardreader giftcardreader.c && ./giftcardreader 1 examplefile.gft && ./giftcardreader 1 part2/crash1.gft && ./giftcardreader 1 part2/crash2.gft && ./giftcardreader 1 part2/hang.gft && ./giftcardreader 1 part3/cov1.gft && ./giftcardreader 1 part3/cov2.gft && ./giftcardreader 1 part3/fuzzer1.gft && ./giftcardreader 1 part3/fuzzer2.gft 

giftcardexamplewriter:
	gcc -o giftcardexamplewriter giftcardexamplewriter.c && ./giftcardexamplewriter

