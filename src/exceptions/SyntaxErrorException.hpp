#include <stdexcept>

namespace FooLang
{
class SyntaxErrorException : public std::logic_error
{
public:
    SyntaxErrorException() : std::logic_error("Syntax error.") {}
};
} // namespace FooLang
