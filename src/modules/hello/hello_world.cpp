
#include "src/module.h"
#include "src/common.h"

class HelloWorldModule : public Module
{
public:
    HelloWorldModule() = default;
    ~HelloWorldModule() override = default;

    ErrorT Init() override;
    void Activate() override;
};


ErrorT HelloWorldModule::Init()
{
    SignupHandler("Hello", [](const std::string & /*command */)
                  { return "Hello, World!"; });
    return SUCCESS;
}

void HelloWorldModule::Activate() {}

void Test()
{
    printf("Hello World\n");
}

REGISTER_MODULE(HelloWorldModule)