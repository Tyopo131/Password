#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>

// Include exit-choice-lib:
#ifdef _DEBUG
#pragma comment(lib, "StandaloneExitChoice.debug.lib")
#else
#pragma comment(lib, "StandaloneExitChoice.release.lib")
#endif
#include "StandaloneExitChoice.h"
using namespace stdln;

using namespace std::filesystem;
int main() {
	const char* fileName = "password.pass";
	path filePath{ fileName };
	bool fileExists = exists(filePath);
	std::string password;
	if (!fileExists) {
		std::ofstream fileWrite;
	choosePassword:
		std::cout << "Passwords must have 1 special character and must be at least 5 letters long.\n\n";
		std::cout << "Enter a unique password: ";
		std::cin >> password;


		bool passwordValid = false;
		if (password.length() >= 5) {

			for (int timer = 0; timer < password.length(); timer++) {
				if ((password[timer] > 32 && password[timer] < 48) || (password[timer] > 57 && password[timer] < 65)) {
					passwordValid = true;
					break;
				}

			}
		}
		if (!passwordValid) goto choosePassword;
		std::cout << "Password saved";
		fileWrite.open(fileName);
		fileWrite << password;
		passwordValid = true;
		system("CLS");
		fileWrite.close();
	}
	else {
	enterPassword:
		std::string passwordEntered;
		std::ifstream read_password(fileName);
		std::string password; read_password >> password;
		std::cout << "Enter password: "; std::cin >> passwordEntered;
		if (password == passwordEntered) {
			std::cout << "Correct!\n\n";
		choosePassword2:
			std::cout << "Passwords must have 1 special character and must be at least 5 letters long.\n\nEnter new password: ";
			read_password.close();
			std::cin >> password; // We're not using password anymore, might as well save memory by reusing it.
			bool passwordValid = false;
			if (password.length() >= 5) {

				for (int timer = 0; timer < password.length(); timer++) {
					if ((password[timer] > 32 && password[timer] < 48) || (password[timer] > 57 && password[timer] < 65)) {
						passwordValid = true;
						break;
					}

				}
			}
			if (passwordValid) {
				std::ofstream write_password(fileName);
				write_password << password;
				write_password.close();
			}
			else goto choosePassword2;

		}
		else {
			std::cout << "Incorrect!\n\n";
			goto enterPassword;
		}


	}
	std::cout << "Press A to change password or E to exit: ";
	restartKey1 = 'a';
	restartKey2 = 'A';
	exitKey1 = 'e';
	exitKey2 = 'E';
	exitchoice();
}