#include "bmpReader.h"

bmpReader::bmpReader() {
	// openBMP
}

bmpReader::bmpReader(const std::string& fileName) {
	if (openBMP(fileName)) {
		displayBMP();
	}
}

bmpReader::~bmpReader() {
	closeBMP();
}

bool bmpReader::openBMP(const std::string& fileName) {
	fileStream.open(fileName, std::ios::binary);
	if (!fileStream.is_open()) {
		std::cout << "Ошибка открытия файла: " << fileName << "\n";
		return false;
	}
	
	fileStream.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));

	if (bmpFileHeader.bfType != 0x4D42) {   // 'BM' в little-endian (0x4d42 | 0x4349 | 0x5450)
		std::cout << "Заголовок файла не удовлетворяет BMP формату\n";
		return false;
	}
	
	fileStream.read(reinterpret_cast<char*>(&infoFileHeader), sizeof(infoFileHeader));

	width = infoFileHeader.biWidth;
	height = infoFileHeader.biHeight;

	std::cout << "Ширина: " << width << "\n";
	std::cout << "Высота: " << height << "\n";
	std::cout << "Разрядность: " << infoFileHeader.biBitCount << " бит\n";

	if (infoFileHeader.biBitCount != bitDepth) {
		std::cout << "Разрядность BMP файла не соответсвует требуемой (24 бит)\n";
		return false;
	}

	fileStream.seekg(bmpFileHeader.bfOffBits, std::ios::beg);

	rowSize = ((infoFileHeader.biBitCount * infoFileHeader.biWidth + 31) / 32) * 4;
	int bufferSize = rowSize * std::abs(infoFileHeader.biHeight);
	bmpData.resize(bufferSize);
	fileStream.read(reinterpret_cast<char*>(bmpData.data()), bufferSize);

	return true;
}

void bmpReader::displayBMP() {
	for (int y = height - 1; y >= 0; --y) {
		for (int x = 0; x < width; ++x) {
			int i = y * rowSize + x * 3;

			uint8_t b = bmpData[i];
			uint8_t g = bmpData[i + 1];
			uint8_t r = bmpData[i + 2];

			if (b == BLACK_BRIGHT && g == BLACK_BRIGHT && r == BLACK_BRIGHT) {
				std::cout << BLACK_PIXEL;
			}
			else if (b == WHITE_BRIGHT && g == WHITE_BRIGHT && r == WHITE_BRIGHT) {
				std::cout << WHITE_PIXEL;
			}
			else {
				std::cout << UNKNOWN_PIXEL;
			}
		}
		std::cout << "\n";
	}
}

void bmpReader::closeBMP() {
	fileStream.close();
	bmpData.clear(); // ??? сам чистится
}
