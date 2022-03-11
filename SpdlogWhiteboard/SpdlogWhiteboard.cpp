#include "framework.h"
using namespace dlllog;
#define REGISTE_DEFAULT_LOGGER 1
int main()
{
    auto logger = Dlllog::SetupLogger();
    Dlllog::Log("Helloworld 1");
    Dlllog::Log("Helloworld 2");
    Dlllog::Log("Helloworld 3");
    Dlllog::Log("Helloworld 4");
    Dlllog::Log("Helloworld 5");
    //spdlog::set_default_logger(logger->clone("main"));
    auto _logger = logger->clone("main");
    
#if REGISTE_DEFAULT_LOGGER
    spdlog::set_default_logger(_logger);
    SPDLOG_INFO("Helloworld 1");
    SPDLOG_INFO("Helloworld 2");
    SPDLOG_INFO("Helloworld 3");
    SPDLOG_INFO("Helloworld 4");
    SPDLOG_INFO("Helloworld 5");
#else
    spdlog::register_logger(_logger);
    _logger->info("Helloworld 1");
    _logger->info("Helloworld 2");
    _logger->info("Helloworld 3");
    _logger->info("Helloworld 4");
    _logger->info("Helloworld 5");
#endif
    
    //spdlog::shutdown();
    Dlllog::DestoryLogger();
}
