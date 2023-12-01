#include "ContentConverter.hpp"

ContentConverter::ContentConverter(std::string fileName) {
	this->fileName = fileName;
}

ContentConverter::~ContentConverter() {

}

int ContentConverter::replace(std::string source, std::string target) {
	std::ifstream inputFile(this->fileName);

	if (inputFile.is_open()) {
		std::stringstream buffer;
		buffer << inputFile.rdbuf();
		std::string content = buffer.str();
		inputFile.close();
		std::ofstream outputFile(this->fileName + ".replace");
		if (!outputFile.is_open()) {
			std::cerr << "Error : could not create the file." << "\n";
			return 1;
		}
		std::string result = this->replaceString(content, source, target);
		outputFile << result;
		return 0;
	} else {
		std::cerr << "Error : could not open the file." << "\n";
		return 1;
	}
}

std::string ContentConverter::replaceString(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str = str.substr(0, start_pos) + to + str.substr(start_pos + from.length());
        start_pos += to.length();
    }
	return str;
}