#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <spdlog/spdlog.h>
#include <spdlog/async_logger.h>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#ifdef DLLLOG_EXPORTS
#define DLLLOG_EXPORT __declspec(dllexport)
#else
#define DLLLOG_EXPORT __declspec(dllimport)
#endif
namespace dlllog {
	class DLLLOG_EXPORT Dlllog
	{
	public:
		static std::shared_ptr<spdlog::async_logger> SetupLogger();
		static void DestoryLogger();
		static void Log(std::string msg);
	};
}