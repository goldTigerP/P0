#ifndef __MODULE_H__
#define __MODULE_H__

#include <string>
#include <functional>
#include <memory>
#include "error_code.h"
#include "common.h"

class Module
{
public:
    Module() = default;
    virtual ~Module() = default;

    virtual ErrorT Init() = 0;
    virtual void Activate() = 0;
};
using ModulePtr = std::unique_ptr<Module>;

void RegisterModule(ModulePtr &&module);

ErrorT InitModules();

void ActivateModules();

using CommandHandler = std::function<std::string(const std::string &)>;
void SignupHandler(const std::string &command, CommandHandler &&handler);

std::string SyncInputCommand(const std::string &command);

#define REGISTER_MODULE(module) \
    FUNCTION_BEFORE_MAIN(Register##module)() { RegisterModule(std::make_unique<module>()); }

#endif
