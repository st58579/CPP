#pragma once
#ifndef PARSER_H
#define PARSER_H

#include "api.h"
class parser {
public:
	Value* deserealize(const std::string& string);
	Value* parseObject(const std::string& string);
	Value* parseArray(const std::string& string);
	Value* parseString(const std::string& string, char quote);
	Value* parseNumber(const std::string& string);
	Value* parseLiteral(const std::string& string, std::string literal);
	void skipWhiteSpace(const std::string& string);
	bool isWhiteSpace(char c);
private:
	size_t position = 0;
};

#endif