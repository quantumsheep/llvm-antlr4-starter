#include <stdexcept>
#include <string>

namespace FooLang
{
class NotCallableException : public std::logic_error
{
public:
    NotCallableException(const std::string &name) : std::logic_error("Expression is not callable: " + name) {}
};
} // namespace FooLang
