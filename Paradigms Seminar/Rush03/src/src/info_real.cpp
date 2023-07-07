/*
** EPITECH PROJECT, 2023
** rush3
** File description:
** info_real.cpp
*/

#include "../classes/data/DataGraph.hpp"

const void system(std::string &_operatesystem, std::string &_kernelversion)
{
  struct utsname unameData;
  uname(&unameData);
  _operatesystem = unameData.sysname;
  _kernelversion = unameData.release;
}

const void info_user_host(std::string &_hostname, std::string &_logname)
{
  char hostname[HOST_NAME_MAX];
  char username[LOGIN_NAME_MAX];
  _hostname = gethostname(hostname, HOST_NAME_MAX);
  _logname = getlogin_r(username, LOGIN_NAME_MAX);
}

std::vector<DataGraph> DataGraph::init() const
{
  std::vector<DataGraph> dataGraph;
  DataGraph cpu("CPU", "/proc/cpuinfo", "cpu MHz", "Hz");
  DataGraph mem("Memory", "/proc/meminfo", "MemTotal", "kB");
  DataGraph memfree("MemoFree", "/proc/meminfo", "MemFree", "kB");
  DataGraph memAvailable("MemAvailable", "/proc/meminfo", "MemAvailable", "kB");
  DataGraph swap("Swap", "/proc/meminfo", "SwapTotal", "kB");
  //DataGraph uptime("Uptime", "/proc/uptime", "", );
  dataGraph.push_back(cpu);
  dataGraph.push_back(mem);
  dataGraph.push_back(memfree);
  dataGraph.push_back(memAvailable);
  dataGraph.push_back(swap);
  //dataGraph.push_back(uptime);

  return dataGraph;
}