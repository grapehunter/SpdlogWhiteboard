#include "framework.h"
#define REGISTE_DEFAULT_LOGGER 1
BOOL APIENTRY DllMain(HMODULE hModule,
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
		break;
	}
	return TRUE;
}
namespace dlllog {
	std::shared_ptr<spdlog::async_logger> _logger;
	std::shared_ptr<spdlog::async_logger> Dlllog::SetupLogger() {
		auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		consoleSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%P] [%t] [%n] [%^%l%$] [%s(%#)] %v");
		std::vector<spdlog::sink_ptr> sinks = { consoleSink };
		spdlog::init_thread_pool(8192, 10);
		_logger = std::make_shared<spdlog::async_logger>("DLLLOG", sinks.begin(), sinks.end(), spdlog::thread_pool());
#if REGISTE_DEFAULT_LOGGER
		spdlog::set_default_logger(_logger);
#else
		spdlog::register_logger(_logger);
#endif
		return _logger;
	}

	void Dlllog::Log(std::string msg) {
#if REGISTE_DEFAULT_LOGGER
		SPDLOG_INFO(msg);
#else
		_logger->info(msg);
#endif
	}

	void Dlllog::DestoryLogger() {
		spdlog::shutdown();
	}
	}