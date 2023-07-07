/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** ncurses.cpp
*/

#include "fonction.hpp"

std::string getInfoFromList(std::string str, int index)
{
    char *ptr; // declare a ptr pointer
    ptr = strtok(const_cast<char*>(str.data()), " "); // use strtok() function to separate string using comma (,) delimiter.
    for (int i = 0; ptr != NULL || i < index; i++)
    {
        if (i == index) {
            return ptr;
        }
        ptr = strtok (NULL, " ");
    }
    return "";
}

std::string getInfosVirt(int pid, int index, int index2)
{
    std::string line;
    std::ifstream file("/proc/" + std::to_string(pid) + "/" + "status");
    if (file.is_open()) {
        for (int i = 0; i < index; i++) {
            std::getline(file, line);
        }
        //std::cout << line.substr(0, 4) << std::endl;
        if (line.substr(0, 4) == "VmPe")
            return line.substr(8, index2);
        return "";
    }
    return "N/A";
}

std::string getInfosFromStatus(int pid, int index, int index2)
{
    std::string line;
    std::ifstream file("/proc/" + std::to_string(pid) + "/" + "status");
    if (file.is_open()) {
        for (int i = 0; i < index; i++) {
            std::getline(file, line);
        }
        //std::cout << line.substr(0, 4) << std::endl;
        if (line.substr(0, 4) == "Uid:" && line.substr(5, 6) == "1000\t1")
            return "user";
        return "root";
    }
    return "N/A";
}

std::string getInfosFromProc(int pid, std::string filename, int index)
{
    std::string line;
    std::ifstream file("/proc/" + std::to_string(pid) + "/" + filename);
    if (file.is_open()) {
        std::getline(file, line);
        return getInfoFromList(line, index);
    }
    return "N/A";
}

void drawHeader(WINDOW *win)
{
    struct sysinfo info;
    sysinfo(&info);

    // Display system information
    mvwprintw(win, 0, 0, "System information:\n");
    mvwprintw(win, 1, 0, "Uptime: %ld\n", info.uptime);
    mvwprintw(win, 2, 0, "Load average: %ld, %ld, %ld\n", info.loads[0], info.loads[1], info.loads[2]);
    mvwprintw(win, 3, 0, "Total RAM: %ld MB\n", info.totalram / 1024 / 1024);
    mvwprintw(win, 4, 0, "Free RAM: %ld MB\n", info.freeram / 1024 / 1024);
    mvwprintw(win, 5, 0, "");
    mvwprintw(win, 6, 0, "");
}

void drawHeaderProcesses(WINDOW *win)
{
    mvwprintw(win, 2, 10 * 0, "pid");
    mvwprintw(win, 2, 10 * 1, "owner");
    mvwprintw(win, 2, 10 * 2 + 2, "PRI");
    mvwprintw(win, 2, 10 * 3, "NI");
    mvwprintw(win, 2, 10 * 4, "virt");
    mvwprintw(win, 2, 10 * 5 + 2, "res");
    mvwprintw(win, 2, 10 * 6, "shared");
    mvwprintw(win, 2, 10 * 7, "S");
    //mvwprintw(win, 2, 10 * 10, "cpu");
    mvwprintw(win, 2, 10 * 8, "mem");
    mvwprintw(win, 2, 10 * 9, "time");
    mvwprintw(win, 2, 10 * 10, "command");
}

void drawProcesses(WINDOW *win, int pid, int lineDisplay)
{
    struct sysinfo info;
    sysinfo(&info);
    mvwprintw(win, lineDisplay, 10 * 0, "%d", pid);//pid
    mvwprintw(win, lineDisplay, 10 *1, "%s", getInfosFromStatus(pid, 9, 10).c_str());//owner
    mvwprintw(win, lineDisplay, 10 *2 + 2, "%s", getInfosFromProc(pid, "/stat", 17).c_str());//PRI
    mvwprintw(win, lineDisplay, 10 *3, "%s", getInfosFromProc(pid, "/stat", 18).c_str());//NI
    mvwprintw(win, lineDisplay, 10 *4 - 5, "%s", getInfosVirt(pid, 17, 20).c_str());//virt
    mvwprintw(win, lineDisplay, 10 * 5 + 2, "%s", getInfosFromProc(pid, "/statm", 1).c_str());//res
    mvwprintw(win, lineDisplay, 10 *6, "%s", getInfosFromProc(pid, "/statm", 2).c_str());//shared
    mvwprintw(win, lineDisplay, 10 *7, "%s", getInfosFromProc(pid, "/stat", 2).c_str());//S
    //mvwprintw(win, lineDisplay, 10 *8 - 7, "%s", getInfosFromStatus(pid, 17, 20).c_str());//cpu
    float value = (atoi((getInfosFromProc(pid, "/statm", 1).c_str())) * 100) / (info.totalram);//mem
    mvwprintw(win, lineDisplay, 10*8, "%.2f", value);//mem
    mvwprintw(win, lineDisplay, 10 *9, "%s", getInfosFromProc(pid, "/stat", 14).c_str());//utime
    mvwprintw(win, lineDisplay, 10*10, "%s", getInfosFromProc(pid, "/cmdline", 0).c_str());//command
}

int draw(WINDOW *header, WINDOW *process, int pid, int pidUser1, int pidUser2, int i)
{
    if (pid > pidUser1 && pid < pidUser2) {
        drawHeader(header);
        drawHeaderProcesses(process);
        drawProcesses(process, pid, i + 3);
        i++;
    }
    return i;
}

int checkEnd(void)
{
    int ch = getch();
    if (ch == 'q' || ch == 4)
        return 84;
    return 0;
}

int getInfosFromProc(WINDOW *header, WINDOW *process, int pid1, int pid2)
{
    DIR *dir;
    struct dirent *ent;
    dir = opendir("/proc");

    if (dir != NULL) {
        for (int i = 0; (ent = readdir(dir)) != NULL;) {
            std::string filename = ent->d_name;
            if (filename.find(".") == std::string::npos) {
                int pid = atoi(filename.c_str());

                i = draw(header, process, pid, pid1, pid2, i);

            }
        }
        closedir(dir);
    } else {
        std::cerr << "Error opening directory: /proc" << std::endl;
        return 1;
    }
    return checkEnd();
}

int run_ncurses(int pid1, int pid2)
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    WINDOW *header = newwin(4, cols, 0, 0);
    WINDOW *processes = newwin(rows - 4, cols, 4, 0);

    while (1) {
        clear();
        if (getInfosFromProc(header, processes, pid1, pid2) == 84)
            break;

        wrefresh(header);
        wrefresh(processes);

        usleep(1000000);
    }

    endwin();
    return 0;
}