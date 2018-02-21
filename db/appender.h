#ifndef APPENDER_H
#define APPENDER_H

#include <iostream>
class appender
{
public:
	appender(std::string file_name);
	void append();
private:
	std::string file;
}

#endif
