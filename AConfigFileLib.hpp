#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio>

enum MODE
{
	FILE_READ = std::ios::in,
	FILE_WRITE = std::ios::out
};

class ConfigFile
{
	public:
		ConfigFile(std::string directory, MODE WRITE_OR_READ);
		std::string getValueOfAttribute(std::string attribute);
		bool setValueOfAttribute(std::string attribute, std::string value);
		void close();

	private:
		void remove(std::string &string, char remove);
		void removeCommentsInLine(std::string &string);
		void remove(std::string &string, std::string);

		std::string m_sFileDirectory;
		std::fstream m_ConfigFileStream;
		MODE m_WRITE_OR_READ;
};