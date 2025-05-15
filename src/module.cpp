#include "module.h"
#include <stdio.h>
#include <map>

using ModuleContainer = std::vector<ModulePtr>;
ModuleContainer &GetModuleContainer()
{
    static ModuleContainer module_container{};
    return module_container;
}

void RegisterModule(ModulePtr &&module)
{
    GetModuleContainer().push_back(std::move(module));
}

ErrorT InitModules()
{
    for (auto &module : GetModuleContainer())
    {
        const auto ret = module->Init();
        if (ret != SUCCESS)
        {
            return ret;
        }
    }
    return SUCCESS;
}

void ActivateModules()
{
    for (auto &module : GetModuleContainer())
    {
        module->Activate();
    }
}

using HandlerContainer = std::map<std::string, CommandHandler>;
static HandlerContainer handler_container;

void SignupHandler(const std::string &command, CommandHandler &&handler)
{
    handler_container[command] = std::move(handler);
}

std::string SyncInputCommand(const std::string &command)
{
    auto it = handler_container.find(command);
    if (it != handler_container.end())
    {
        return it->second(command);
    }

    for (const auto &pair : handler_container)
    {
        if (pair.first.find(command) == 0)
        {
            return pair.second(command);
        }
    }
    return "Error: no handler";
}