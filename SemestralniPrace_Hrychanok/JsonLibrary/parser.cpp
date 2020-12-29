#include "pch.h"
#include "parser.h"

Value* parser::deserealize(const std::string& string)
{
	std::string _numbers = "-0123456789.";
	skipWhiteSpace(string);
	if (position == string.length()) return new NullValue();
	char c = string[position];
	if (c == '{') return parseObject(string);
	else if (c == '[') return parseArray(string);
	else if (c == '\"') return parseString(string, '\"');
	else if (c == '\'') return parseString(string, '\'');
	else if (_numbers.find(c) != std::string::npos) return parseNumber(string);
	else if (c == 't') return parseLiteral(string, "true");
	else if (c == 'f') return parseLiteral(string, "false");
	else if (c == 'n') return parseLiteral(string, "null");
	throw std::exception("invalid json");
}

Value* parser::parseObject(const std::string& string)
{
	position++;
	ObjectValue* ov = new ObjectValue();
	char c;
	while (true) {
		skipWhiteSpace(string);
		if (string[position] == '}') {
			position++;
			return new NullValue();
		}
		Value* key = deserealize(string);
		skipWhiteSpace(string);
		c = string[position];
		if (c != ':') throw std::exception("Expecting :");
		position++;
		skipWhiteSpace(string);
		Value* value = deserealize(string);
		skipWhiteSpace(string);
		ov->append(KeyValuePair(dynamic_cast<StringValue*>(key)->get(), value));
		c = string[position];
		if (c == ',') {
			position++;
			skipWhiteSpace(string);
		}
		else break;
	}
	if (c != '}') {
		throw std::exception("Expecting }");
	}
	position++;
	return ov;
}

Value* parser::parseArray(const std::string& string)
{
	position++;
	skipWhiteSpace(string);
	if (string[position] == ']') {
		position++;
		return new ArrayValue();
	}
	ArrayValue* a = new ArrayValue();
	char c;
	while (true) {
		Value* value = deserealize(string);
		a->append(value);
		skipWhiteSpace(string);
		c = string[position];
		if (c == ',') {
			position++;
			skipWhiteSpace(string);
		}
		else break;
	}
	if (c != ']') {
		throw "Expecting ]";
	}
	position++;
	return a;
}

Value* parser::parseString(const std::string& string, char quote)
{
	size_t startIndex = ++position;
	char c;
	std::string str = "";
	while ((c = string[position]) != quote) {
		if (position < string.length()) {
			if (c == '\\') {
				position++;
				c = string[position];
				if (c == 'r') str += '\r';
				else if (c == 'n') str += '\n';
				else if (c == 't') str += '\t';
				else if (c == 'f') str += '\f';
				else str += c;
			}
			else str += c;
			position++;
		}
		else throw std::exception("Invalid JSON");
	}
	position++;
	return new StringValue(str);
}

Value* parser::parseNumber(const std::string& string)
{
	size_t startIndex = position;
	int len = 0;
	std::string _numbers = "-0123456789.";
	while (_numbers.find(string[position]) != std::string::npos) {
		position++;
		len++;
	}
	std::string substring = string.substr(startIndex, len);
	return new NumberValue(std::stod(substring));
}

Value* parser::parseLiteral(const std::string& string, std::string literal)
{
	if (literal.length() > string.length() - position) {
		throw "Expecting " + literal;
	}
	for (size_t i = 0; i < literal.length(); i++) {
		if (literal[i] != string[position++]) {
			throw "Expecting " + literal;
		}
	}
	if (literal == "true") {
		return new BoolValue(true);
	}
	else if (literal == "false") {
		return new BoolValue(false);
	}
	else {
		return new NullValue();
	}
}

void parser::skipWhiteSpace(const std::string& string)
{
	while (position < string.length() && isWhiteSpace(string[position])) position++;
}

bool parser::isWhiteSpace(char c)
{
	return c == ' ' || c == '\r' || c == '\n' || c == '\t';
}
