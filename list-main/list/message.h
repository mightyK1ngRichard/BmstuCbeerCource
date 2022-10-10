#pragma once
#include <iostream>
#include <string>

class message {
public:
	message() = default;
	message(const std::string&, const std::string&);
	~message() = default;
	std::string GetText() const;
	std::string GetNumber() const;
	void SetText(const std::string&);
	void SetNumber(const std::string&);
private:
	std::string _text;
	std::string _number;
};
inline message::message(const std::string& tepehone_number, const std::string& text_message)
	: _text(text_message), _number(tepehone_number) {}
inline std::string message::GetText() const {
	return _text;
}
inline std::string message::GetNumber() const {
	return _number;
}
inline void message::SetText(const std::string& text_message) {
	_text = text_message;
}
inline void message::SetNumber(const std::string& tepehone_number) {
	_number = tepehone_number;
}
