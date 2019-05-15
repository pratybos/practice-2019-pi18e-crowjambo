#pragma once


struct Point {
	int angle;
	int length;
	int availableLines;
	int LeftRight;
	
};
typedef struct Point Point;

struct Map {
	Point points[50];

};
typedef struct Map Map;



Map map_init();