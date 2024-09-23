#include <iostream>
#include <filesystem>
#include "bmpReader.h"

bool isBmp(std::filesystem::path bmpPath) {
	using namespace std::filesystem;

	if (exists(bmpPath) && bmpPath.extension() == ".bmp") {
		return true;
	}
	else {
		std::cout << "Неверный путь к файлу в параметрах запуска\n";
	}
}

int main(int argc, char* argv[]) {
	// с 866
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Enter
	std::filesystem::path bmpPath;

	if (argc > 1) {
		bmpPath = argv[1];
	}
	while (!isBmp(bmpPath)) {
		system("cls");
		std::cout << "Введите путь к файлу: ";
		std::cin >> bmpPath;
	}
	system("cls");

	/*// BMP 1-й способ
	bmpReader bmp;
	if (bmp.openBMP(bmpPath.string())) {
		bmp.displayBMP();
		//bmp.closeBMP(); // Если нужен вызов, а так он в деструкторе
	}*/

	// BMP 2-й способ
	bmpReader bmp(bmpPath.string());

	return 0;
}