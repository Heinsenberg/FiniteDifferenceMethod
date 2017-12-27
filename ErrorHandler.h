#ifndef	__ERRORHANDLER_H
#define __ERRORHANDLER_H

#include <stdexcept>
using namespace std;

class ErrorHandler {

public:
	ErrorHandler();
	~ErrorHandler();

	void setException(exception _exception) { m_exception = _exception; };
	exception getException() { return m_exception; };
	
	void setErrorFlag(bool _errorFlag) { m_isAnError = _errorFlag; };
	bool getErrorFlag() { return m_isAnError; };
	
protected:
	exception m_exception;
	bool m_isAnError;
};
#endif



