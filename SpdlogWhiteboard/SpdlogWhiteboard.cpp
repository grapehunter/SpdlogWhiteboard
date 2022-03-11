#include "framework.h"
using namespace dlllog;
int main()
{
    auto logger = Dlllog::SetupLogger();
    Dlllog::Log("Helloworld 1");
    Dlllog::Log("Helloworld 2");
    Dlllog::Log("Helloworld 3");
    Dlllog::Log("Helloworld 4");
    Dlllog::Log("Helloworld 5");
    spdlog::set_default_logger(logger->clone("main"));
    SPDLOG_INFO("Helloworld 1");
    SPDLOG_INFO("Helloworld 2");
    SPDLOG_INFO("Helloworld 3");
    SPDLOG_INFO("Helloworld 4");
    SPDLOG_INFO("Helloworld 5");
    //spdlog::shutdown();
}
