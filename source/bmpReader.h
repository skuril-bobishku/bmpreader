#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>

class bmpReader {
public:
	bmpReader();
	bmpReader(const std::string& fileName);
	~bmpReader();

	bool openBMP(const std::string& fileName);
	void displayBMP();
	void closeBMP();

private:
	const int bitDepth = 24;
	const char BLACK_PIXEL = '#';
	const char WHITE_PIXEL = ' ';
	const char UNKNOWN_PIXEL = '?';
	const int BLACK_BRIGHT = 0;
	const int WHITE_BRIGHT = 255;

	std::ifstream fileStream;

	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER infoFileHeader;

	int width, height, rowSize;
	
	std::vector<uint8_t> bmpData;
};

