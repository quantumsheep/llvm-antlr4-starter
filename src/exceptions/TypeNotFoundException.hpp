#include <stdexcept>
#include <string>

namespace FooLang
{
class TypeNotFoundException : public std::logic_error
{
public:
    TypeNotFoundException(const std::string &name) : std::logic_error("Type not found: " + name) {}
};
} // namespace FooLang
