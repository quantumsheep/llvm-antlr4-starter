#include <stdexcept>
#include <string>

namespace FooLang
{
class VariableNotFoundException : public std::logic_error
{
public:
    VariableNotFoundException(const std::string &name) : std::logic_error("Variable not found: " + name) {}
};
} // namespace FooLang
