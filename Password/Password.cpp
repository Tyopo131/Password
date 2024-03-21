#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
std::istream* read_file = nullptr;

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

	}
}