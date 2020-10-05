/*
 * Gift Card Example Writer
 * Original Author: Shoddycorp's Cut-Rate Contracting
 * Maintainer: ???
 * Comments added by Justin Cappos (JAC)
 * Modification Date: 8 July 2020
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "giftcard.h"

struct this_gift_card examplegc;
struct gift_card_data examplegcd;
struct gift_card_record_data examplegcrd;
struct gift_card_amount_change examplegcac;
struct gift_card_program examplegcp2;

// Break it up so that we don't have long functions!  Good programming style!
//  (JAC: This is so wrong.  Global variable use / initialization is a
//  terrible thing to do.)
void setupgc()
{
	examplegc.num_bytes = 500;
	examplegc.gift_card_data = (void *)&examplegcd;
	examplegcd.merchant_id = "GiftCardz.com                   ";
	examplegcd.customer_id = "DuaneGreenes Store 1451         ";
	examplegcd.number_of_gift_card_records = 1;

	/* JAC: Something seems fishy... */
	// IR: malloc not done properly
	examplegcd.gift_card_record_data = malloc(examplegcd.number_of_gift_card_records * examplegcrd.record_size_in_bytes);
	/* JAC: here too! */
	examplegcd.gift_card_record_data[0] = (void *)&examplegcrd;
	examplegcrd.record_size_in_bytes = 300;
	examplegcrd.type_of_record = 3; // JAC: Should be enum!  amount_change
	examplegcrd.actual_record = (void *)&examplegcp2;
	examplegcp2.message = "message";
}

// moved into separate files to avoid erroenous style checker error...
/* JAC: opening and writing a fixed filename using a global is terrible style.
 *     the style checker was right!  This code is terrible   
 */
void writegc()
{
	FILE *fd1;
	// JAC: Why don't any of these check for error return codes?!?
	fd1 = fopen("cov3.gft", "w");
	fwrite(&examplegc.num_bytes, 4, 1, fd1);
	fwrite(examplegcd.merchant_id, 32, 1, fd1);
	fwrite(examplegcd.customer_id, 32, 1, fd1);
	fwrite(&examplegcd.number_of_gift_card_records, 4, 1, fd1);
	fwrite(&examplegcrd.record_size_in_bytes, 4, 1, fd1);
	fwrite(&examplegcrd.type_of_record, 4, 1, fd1);
	unsigned char message[32] = "message";
	fwrite(message, 32, 1, fd1);
	unsigned char pgm[256] = {
		// 	//hang
		// 	// 0x09, (130), 0xaa,

		// 	//crash2
		// 	// 0x01,
		// 	// (127),
		// 	// 0xaa

		0x01,
		(10),
		(12),

		0x02,
		(10),
		(12),

		0x04,
		(10),
		(12),

		0x06,
		(10),
		(12),

		0x07,
		0xff,
		0xff,

		0x08,
		0xff,
		0xff,

	};
	fwrite(pgm, 256, 1, fd1);

	fclose(fd1);
}

/* JAC: No args and return -1 for no reason!?! */
int main(void)
{

	setupgc();
	writegc();
	return -1;
}
