#include "framework.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        spdlog::shutdown();
        break;
    }
    return TRUE;
}
namespace dlllog {
    std::shared_ptr<spdlog::async_logger> _logger;
    std::shared_ptr<spdlog::async_logger> Dlllog::SetupLogger() {
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        std::vector<spdlog::sink_ptr> sinks = { consoleSink };
        spdlog::init_thread_pool(8192, 1);
        _logger = std::make_shared<spdlog::async_logger>("DLLLOG", sinks.begin(), sinks.end(), spdlog::thread_pool());
        spdlog::set_default_logger(_logger);
        return _logger;
    }

     void Dlllog::Log(std::string msg) {
         SPDLOG_INFO(msg);
    }
}