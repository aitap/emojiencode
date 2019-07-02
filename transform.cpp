#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>
#include <unordered_map>

#include "bigint.hpp"

void encode(const std::unordered_map<uint32_t, wchar_t> & map) {
	bigint<uint32_t, uint32_t> state(map.size(), 1U);
	char c;
	while (std::cin.get(c)) {
		state *= 256U;
		state += (unsigned char) c;
	}
	for (size_t i = 1; i <= state.digits.size(); ++i)
		if (!std::wcout.put(map.at(state.digits[state.digits.size() - i]))) return;
	std::wcout << std::endl;
}

void decode(const std::unordered_map<wchar_t, uint32_t> & map) {
	bigint<unsigned char, unsigned short> state(256U, 0U);
	wchar_t c;
	while (std::wcin.get(c)) {
		auto n = map.find(c);
		if (n == map.end()) continue;
		state *= map.size();
		state += n->second;
	}
	for (size_t i = 2; i <= state.digits.size(); ++i)
		if (!std::cout.put((char)state.digits[state.digits.size() - i])) return;
}

int main(int argc, char ** argv) {
	if (!std::setlocale(LC_ALL, "")) {
		std::cerr << "Failed to set locale" << std::endl;
		return -4;
	}

	if (argc != 2) {
		std::cerr << "Usage: <-e|-d> <chars.txt>" << std::endl;
		return -1;
	}

	std::wifstream dict(argv[2]);
	if (!dict) {
		std::cerr << "Couldn't open " << argv[2] << std::endl;
		return -3;
	}

	wchar_t wc;
	uint32_t i = 0;

	if (std::string(argv[1]) == "-e") {
		std::unordered_map<wchar_t, uint32_t> map;
	} else if (std::string(argv[1]) == "-d") {
	} else {
		std::cerr << "argv[1] must be '-e' or '-d'" << std::endl;
		return -2;
	}
}
