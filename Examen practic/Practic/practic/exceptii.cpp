#include "exceptii.h"

/// <summary>
/// 
/// Valoarea primita ca parametru este atribuita campului message
/// </summary>
/// <param name="msg"></param>
ValidationException::ValidationException(string msg)
{
    this->message = msg;

}

/// <summary>
/// What returneaza un mesaj de eroare
/// </summary>
/// <returns></returns>
const char* ValidationException::what()
{
    return  this->message.c_str();
}
