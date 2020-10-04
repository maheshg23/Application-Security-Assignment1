giftcardreader: giftcardreader.c
	gcc -o giftcardreader giftcardreader.c && ./giftcardreader 1 examplefile.gft && ./giftcardreader 1 part2/crash1.gft && ./giftcardreader 1 part2/crash2.gft && ./giftcardreader 1 part2/hang.gft 


giftcardexamplewriter:
	gcc -o giftcardexamplewriter giftcardexamplewriter.c && ./giftcardexamplewriter

