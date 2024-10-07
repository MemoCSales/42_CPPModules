#include "ScalarConverter.hpp"

bool isChar(const std::string& lit) {
	if (lit.length() == 1 && isprint(lit[0]) && !isdigit(lit[0])) {
		return true;
	}
	return false;	
}

bool isInt(const std::string& lit) {
	size_t start = 0;
	if (lit[0] == '+' || lit[0] == '-') {
		start = 1;
	}
	if (start == lit.size()) {
		return false; // String is just a sign, not a valid number
	}
	for (size_t i = start; i < lit.size(); i++)	{
		if (!isdigit(lit[i])) {
			return false;
		}
	}

	// Check range
	char* end;
	long num = std::strtol(lit.c_str(), &end, 10);

	if (*end != '\0' || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return false;
	
	return true;
}

bool isFloat(const std::string& lit) {
	// if (lit == "nanf" || lit == "+inff" || lit == "-inff") return false;

	if (lit[lit.size() - 1] != 'f') return false;

	// Create a substring without the trailing 'f'
	std::string numPart = lit.substr(0, lit.size() - 1);

	// Check if the remaining part has a point
	if (numPart.find('.') == std::string::npos) return false;

	// Check if the remaining part is a valid float
	std::istringstream iss(numPart);
	float num;
	iss >> num;

	// True if the extraction is successful and the end of the string was reach.
	return !iss.fail() && iss.eof();
}

bool isDouble(const std::string& lit) {
	if (lit[lit.size() - 1] == 'f') return true;

	std::istringstream iss(lit);
	double doubleNum;
	iss >> doubleNum;

	if (!(!iss.fail() && iss.eof())) return false;

	if (doubleNum < -std::numeric_limits<double>::max() || doubleNum > std::numeric_limits<double>::max())
		return false;
	
	return true;
}

void printChar(const std::string& lit) {
	// std::cout << "PRINTING CHAR" << std::endl;
	char c = lit[0];
	std::cout << "char: '" << lit << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(const std::string& lit) {
	// std::cout << "PRINTING INT" << std::endl;
	int num = std::atoi(lit.c_str());

	if (num >= 1 && num <= 127) {
		if (isprint(num)) {
			std::cout << "char: " << static_cast<char>(num) << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		} 
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	std::cout << "int: " << num << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void printFloat(const std::string& lit) {
	// std::cout << "PRINTING FLOAT" << std::endl;
	float floatNum = atof(lit.c_str());

	if (floatNum >= 1 && floatNum <= 127) {
		if (isprint(floatNum)) {
			std::cout << "char: " << static_cast<char>(floatNum) << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(floatNum) << std::endl;
	std::cout << "float: " << static_cast<float>(floatNum) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floatNum) << std::endl;
}

void printDouble(const std::string& lit) {
	// std::cout << "PRINTING DOUBLE" << std::endl;
	double doubleNum = atof(lit.c_str());

	if (doubleNum >= 1 && doubleNum <= 127) {
		if (isprint(doubleNum)) {
			std::cout << "char: " << static_cast<char>(doubleNum) << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	if (doubleNum > INT32_MAX && doubleNum < INT32_MIN) {
		std::cout << "int: " << static_cast<int>(doubleNum) << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}

	double doubleValue = atof(lit.c_str());
	std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "double: " << doubleValue << std::endl;

}

void printSpecialFloat(const std::string& lit) {
	// std::cout << "PRINTING SPECIAL FLOAT" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	float floatValue = atof(lit.c_str());
	std::cout << "float: " << static_cast<float>(floatValue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
}

void printSpecialDouble(const std::string& lit) {
	// std::cout << "PRINTING SPECIAL DOUBLE" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	double doubleValue = atof(lit.c_str());
	std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(doubleValue) << std::endl;
}
