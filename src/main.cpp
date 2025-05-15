
#include "module.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello, World!" << endl;
    cout << "init modules" << endl;
    const auto ret = InitModules();
    if (ret != SUCCESS)
    {
        cout << "Failed to initialize modules" << endl;
        return ret;
    }

    cout << "activate modules" << endl;
    ActivateModules();

    // Test();

    string line{};
    string res{};
    while (true)
    {
        // this_thread::sleep_for(chrono::seconds(1));

        // auto now = chrono::system_clock::now();
        // std::time_t now_time = chrono::system_clock::to_time_t(now);
        // std::cout << "current time: " << std::ctime(&now_time);

        cout << ">>";
        cin >> line;
        if (line == "Q" || line == "q" || line == "Quit" || line == "quit")
        {
            break;
        }

        res = SyncInputCommand(line);
        cout << res << endl;
    }

    return 0;
}