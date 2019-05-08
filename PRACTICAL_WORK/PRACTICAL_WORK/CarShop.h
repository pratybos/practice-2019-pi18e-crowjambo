#pragma once


struct CarListing{
	int price;
	char name[20];
	//would need to generate car object with all the stats too later on
};
typedef struct CarListing CarListing;

CarListing generateListing();

