#ifndef CONTENTCONVERTER_HPP
#define CONTENTCONVERTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class ContentConverter {
private:
	std::string fileName;
	std::string replaceString(std::string& str, const std::string& from, const std::string& to);

public:
	ContentConverter(std::string fileName);
	~ContentConverter();
	int replace(std::string source, std::string target);
};

#endif