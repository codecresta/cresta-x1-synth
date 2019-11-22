#ifndef _MATEXCEPTION_INCLUDED
#define _MATEXCEPTION_INCLUDED

#include <vector>
#include <tchar.h>

// Throw a first exception, without parent exception
#define EXCEP(desc, from) throw(MATExceptions(__LINE__, __FILE__, 0, from, desc));

class MATException
{
	long m_line;
	long m_level;
	std::string m_file;
	std::string m_from;
	std::string m_desc;
public:
	MATException(long line, const std::string file, long level, const std::string from, const std::string desc);
	MATException(const MATException &obj);
	MATException& operator=(const MATException &obj);
	long getLine()const{ return m_line; } 
	long getLevel()const{ return m_level; } 
	std::string getFile()const{ return m_file; }
	std::string getFrom()const{ return m_from; }
	std::string getDesc()const{ return m_desc; }
};

class MATExceptions
{
	std::vector<MATException> m_exceptions;
public:

	MATExceptions();
	MATExceptions(long line, const std::string file, long level, const std::string from, const std::string desc);
	MATExceptions(const MATExceptions &obj);
	MATExceptions& operator=(const MATExceptions &obj);
	void add(long line, const std::string file, long level, const std::string from, const std::string desc);
	void add(const MATExceptions &e);
	int size()const;
	const MATException* getException(int pos)const;
	std::string getAllExceptionStr();
};

#endif