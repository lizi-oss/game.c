#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <queue>

using namespace std;

enum ProcessState
{
    READY,
    RUNNING,
    FINISHED
};

class PCB
{
public:
    string processName;
    int arriveTime;
    int serviceTime;
    int finishTime;
    int turnaroundTime;
    double weightedTurnaroundTime;
    ProcessState state;

public:
    PCB()
    {
        processName = "";
        arriveTime = 0;
        serviceTime = 0;
        finishTime = 0;
        turnaroundTime = 0;
        weightedTurnaroundTime = 0;
        state = READY;
    }

    PCB(string name, int arrive, int service)
    {
        processName = name;
        arriveTime = arrive;
        serviceTime = service;
        finishTime = 0;
        turnaroundTime = 0;
        weightedTurnaroundTime = 0;
        state = READY;
    }
};

class CPUManager
{
private:
    vector<PCB> processList;

public:
    // 创建进程
    void createProcess()
    {
        string name;
        int arrive, service;
        cout << "\n请输入进程名:";
        cin >> name;
        cout << "请输入到达时间:";
        cin >> arrive;
        cout << "请输入服务时间:";
        cin >> service;
        PCB p(name, arrive, service);
        processList.push_back(p);
        cout << "\n创建成功!\n";
    }

    // 查看所有进程
    void showProcess()
    {
        if (processList.empty())
        {
            cout << "\n暂无进程!\n";
            return;
        }
        cout << "\n";
        cout << left
            << setw(15) << "进程名"
            << setw(15) << "到达时间"
            << setw(15) << "服务时间"
            << endl;
        for (auto& p : processList)
        {
            cout << setw(15) << p.processName
                << setw(15) << p.arriveTime
                << setw(15) << p.serviceTime
                << endl;
        }
    }

    // 删除进程
    void deleteProcess()
    {
        if (processList.empty())
        {
            cout << "\n暂无进程!\n";
            return;
        }
        string name;
        cout << "\n请输入删除的进程名:";
        cin >> name;
        for (auto it = processList.begin(); it != processList.end(); it++)
        {
            if (it->processName == name)
            {
                processList.erase(it);
                cout << "\n删除成功!\n";
                return;
            }
        }
        cout << "\n未找到该进程!\n";
    }

    // 修改进程
    void modifyProcess()
    {
        if (processList.empty())
        {
            cout << "\n暂无进程!\n";
            return;
        }
        string name;
        cout << "\n请输入进程名:";
        cin >> name;
        for (auto& p : processList)
        {
            if (p.processName == name)
            {
                cout << "新的到达时间:";
                cin >> p.arriveTime;
                cout << "新的服务时间:";
                cin >> p.serviceTime;
                cout << "\n修改成功!\n";
                return;
            }
        }
        cout << "\n未找到该进程!\n";
    }

    // FCFS先来先服务
    void FCFS()
    {
        if (processList.empty())
        {
            cout << "\n暂无进程!\n";
            return;
        }
        vector<PCB> temp = processList;
        // 按到达时间升序
        sort(temp.begin(), temp.end(), [](PCB a, PCB b) {
            return a.arriveTime < b.arriveTime;
            });

        int currentTime = 0;
        double avgTurnaround = 0, avgWeight = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            // CPU空闲，跳转到进程到达时间
            if (currentTime < temp[i].arriveTime)
                currentTime = temp[i].arriveTime;
            currentTime += temp[i].serviceTime;
            temp[i].finishTime = currentTime;
            temp[i].turnaroundTime = temp[i].finishTime - temp[i].arriveTime;
            temp[i].weightedTurnaroundTime = (double)temp[i].turnaroundTime / temp[i].serviceTime;
            avgTurnaround += temp[i].turnaroundTime;
            avgWeight += temp[i].weightedTurnaroundTime;
        }

        cout << "\n==========FCFS调度结果==========\n";
        cout << left
            << setw(10) << "进程"
            << setw(10) << "完成时间"
            << setw(10) << "周转时间"
            << setw(15) << "带权周转时间"
            << endl;
        cout << fixed << setprecision(2);
        for (auto& p : temp)
        {
            cout << setw(10) << p.processName
                << setw(10) << p.finishTime
                << setw(10) << p.turnaroundTime
                << setw(15) << p.weightedTurnaroundTime
                << endl;
        }
        cout << "\n平均周转时间: " << avgTurnaround / temp.size() << endl;
        cout << "平均带权周转时间: " << avgWeight / temp.size() << endl;
    }

    // 修复：非抢占式SJF短作业优先
    void SJF()
    {
        if (processList.empty())
        {
            cout << "\n暂无进程!\n";
            return;
        }
        vector<PCB> temp = processList;
        vector<PCB> result;
        vector<bool> finished(temp.size(), false);
        int currentTime = 0;
        int finishedCnt = 0;

        while (finishedCnt < temp.size())
        {
            // 筛选已到达且未完成的进程
            vector<PCB*> ready;
            for (int i = 0; i < temp.size(); i++)
            {
                if (!finished[i] && temp[i].arriveTime <= currentTime)
                {
                    ready.push_back(&temp[i]);
                }
            }

            if (ready.empty())
            {
                // 无就绪进程，时间+1
                currentTime++;
                continue;
            }

            // 选服务时间最短
            PCB* select = ready[0];
            for (auto p : ready)
            {
                if (p->serviceTime < select->serviceTime)
                    select = p;
            }

            // 运行该进程
            currentTime += select->serviceTime;
            select->finishTime = currentTime;
            select->turnaroundTime = select->finishTime - select->arriveTime;
            select->weightedTurnaroundTime = (double)select->turnaroundTime / select->serviceTime;

            // 标记完成
            for (int i = 0; i < temp.size(); i++)
            {
                if (&temp[i] == select)
                {
                    finished[i] = true;
                    finishedCnt++;
                    result.push_back(temp[i]);
                    break;
                }
            }
        }

        // 输出结果
        double avgTurnaround = 0, avgWeight = 0;
        cout << "\n==========SJF非抢占短作业优先调度结果==========\n";
        cout << left
            << setw(10) << "进程"
            << setw(10) << "完成时间"
            << setw(10) << "周转时间"
            << setw(15) << "带权周转时间"
            << endl;
        cout << fixed << setprecision(2);
        for (auto& p : result)
        {
            cout << setw(10) << p.processName
                << setw(10) << p.finishTime
                << setw(10) << p.turnaroundTime
                << setw(15) << p.weightedTurnaroundTime
                << endl;
            avgTurnaround += p.turnaroundTime;
            avgWeight += p.weightedTurnaroundTime;
        }
        cout << "\n平均周转时间: " << avgTurnaround / result.size() << endl;
        cout << "平均带权周转时间: " << avgWeight / result.size() << endl;
    }

    // 进程统计
    void statistics()
    {
        cout << "\n";
        cout << "当前进程数量: " << processList.size() << endl;
        int totalService = 0;
        for (auto& p : processList)
            totalService += p.serviceTime;
        cout << "总服务时间: " << totalService << endl;
    }

    // CPU子菜单
    void menu()
    {
        int choice;
        while (true)
        {
            cout << "\n==========CPU管理==========\n";
            cout << "1.创建进程\n";
            cout << "2.查看进程\n";
            cout << "3.删除进程\n";
            cout << "4.修改进程\n";
            cout << "5.FCFS调度\n";
            cout << "6.SJF调度\n";
            cout << "7.统计信息\n";
            cout << "0.返回主菜单\n";
            cout << "请输入选择:";
            cin >> choice;
            switch (choice)
            {
            case 1: createProcess(); break;
            case 2: showProcess(); break;
            case 3: deleteProcess(); break;
            case 4: modifyProcess(); break;
            case 5: FCFS(); break;
            case 6: SJF(); break;
            case 7: statistics(); break;
            case 0: return;
            default: cout << "输入错误，请重新输入！\n";
            }
        }
    }
};

// 内存管理模块
class MemoryManager
{
private:
    vector<int> pageSequence;
    int frameCount;

public:
    MemoryManager()
    {
        frameCount = 3;
    }

    void inputPages()
    {
        pageSequence.clear();
        int n;
        cout << "\n请输入页面访问序列长度:";
        cin >> n;
        cout << "请输入页面访问序列(空格分隔):\n";
        for (int i = 0; i < n; i++)
        {
            int page;
            cin >> page;
            pageSequence.push_back(page);
        }
        cout << "请输入物理块数量:";
        cin >> frameCount;
        cout << "\n页面序列录入成功!\n";
    }

    void showPages()
    {
        if (pageSequence.empty())
        {
            cout << "\n暂无页面访问数据!\n";
            return;
        }
        cout << "\n页面访问序列: ";
        for (int p : pageSequence)
            cout << p << " ";
        cout << "\n物理块数量: " << frameCount << endl;
    }

    // 判断页面是否在页框
    bool isExist(vector<int>& frame, int page)
    {
        for (int x : frame)
            if (x == page) return true;
        return false;
    }

    // 打印当前页框
    void showFrame(vector<int>& frame)
    {
        cout << "当前页框: ";
        for (int x : frame)
            cout << x << " ";
        cout << endl;
    }

    // FIFO页面置换
    void FIFO()
    {
        if (pageSequence.empty())
        {
            cout << "\n请先录入页面访问序列!\n";
            return;
        }
        vector<int> frame;
        int ptr = 0;
        int faultCnt = 0, hitCnt = 0;
        cout << "\n==========FIFO置换算法==========\n";
        for (int page : pageSequence)
        {
            cout << "\n访问页面 " << page << " : ";
            if (isExist(frame, page))
            {
                hitCnt++;
                cout << "命中 ";
            }
            else
            {
                faultCnt++;
                cout << "缺页 ";
                if (frame.size() < frameCount)
                    frame.push_back(page);
                else
                {
                    frame[ptr] = page;
                    ptr = (ptr + 1) % frameCount;
                }
            }
            showFrame(frame);
        }
        double faultRate = (double)faultCnt / pageSequence.size();
        double hitRate = (double)hitCnt / pageSequence.size();
        cout << "\n缺页次数: " << faultCnt << "  命中次数: " << hitCnt << endl;
        cout << fixed << setprecision(2);
        cout << "缺页率: " << faultRate * 100 << "%  命中率: " << hitRate * 100 << "%" << endl;
    }

    // LRU最近最少使用置换
    void LRU()
    {
        if (pageSequence.empty())
        {
            cout << "\n请先录入页面访问序列!\n";
            return;
        }
        vector<int> frame;
        vector<int> lastUseTime;
        int faultCnt = 0, hitCnt = 0;
        cout << "\n==========LRU置换算法==========\n";
        for (int idx = 0; idx < pageSequence.size(); idx++)
        {
            int page = pageSequence[idx];
            bool hit = false;
            // 更新最近使用时间
            for (int i = 0; i < frame.size(); i++)
            {
                if (frame[i] == page)
                {
                    lastUseTime[i] = idx;
                    hit = true;
                    break;
                }
            }
            cout << "\n访问页面 " << page << " : ";
            if (hit)
            {
                hitCnt++;
                cout << "命中 ";
            }
            else
            {
                faultCnt++;
                cout << "缺页 ";
                if (frame.size() < frameCount)
                {
                    frame.push_back(page);
                    lastUseTime.push_back(idx);
                }
                else
                {
                    // 找最久未使用下标
                    int minIdx = 0;
                    for (int i = 1; i < lastUseTime.size(); i++)
                        if (lastUseTime[i] < lastUseTime[minIdx])
                            minIdx = i;
                    frame[minIdx] = page;
                    lastUseTime[minIdx] = idx;
                }
            }
            showFrame(frame);
        }
        double faultRate = (double)faultCnt / pageSequence.size();
        double hitRate = (double)hitCnt / pageSequence.size();
        cout << "\n缺页次数: " << faultCnt << "  命中次数: " << hitCnt << endl;
        cout << fixed << setprecision(2);
        cout << "缺页率: " << faultRate * 100 << "%  命中率: " << hitRate * 100 << "%" << endl;
    }

    // OPT最优置换，找到未来最久不使用的页下标
    int findOPTReplace(vector<int>& frame, int curIdx)
    {
        int farIdx = 0;
        int maxNext = -1;
        for (int i = 0; i < frame.size(); i++)
        {
            int nextPos = 999999;
            for (int j = curIdx + 1; j < pageSequence.size(); j++)
            {
                if (pageSequence[j] == frame[i])
                {
                    nextPos = j;
                    break;
                }
            }
            if (nextPos > maxNext)
            {
                maxNext = nextPos;
                farIdx = i;
            }
        }
        return farIdx;
    }

    void OPT()
    {
        if (pageSequence.empty())
        {
            cout << "\n请先录入页面访问序列!\n";
            return;
        }
        vector<int> frame;
        int faultCnt = 0;
        cout << "\n==========OPT最优置换算法==========\n";
        for (int idx = 0; idx < pageSequence.size(); idx++)
        {
            int page = pageSequence[idx];
            cout << "\n访问页面 " << page << " : ";
            if (isExist(frame, page))
            {
                cout << "命中 ";
                showFrame(frame);
                continue;
            }
            faultCnt++;
            cout << "缺页 ";
            if (frame.size() < frameCount)
                frame.push_back(page);
            else
            {
                int repIdx = findOPTReplace(frame, idx);
                frame[repIdx] = page;
            }
            showFrame(frame);
        }
        double faultRate = (double)faultCnt / pageSequence.size();
        cout << "\n缺页次数: " << faultCnt << endl;
        cout << fixed << setprecision(2) << "缺页率: " << faultRate * 100 << "%" << endl;
    }

    void analysis()
    {
        cout << "\n=================================\n";
        cout << "FIFO:先进先出，实现简单，存在Belady异常\n";
        cout << "LRU:最近最少使用，性能优秀，无Belady异常\n";
        cout << "OPT:理论最优，无法实际实现，用于参照对比\n";
        cout << "=================================\n";
    }

    void menu()
    {
        int choice;
        while (true)
        {
            cout << "\n=========内存管理=========\n";
            cout << "1.录入页面序列\n";
            cout << "2.查看页面序列\n";
            cout << "3.FIFO置换算法\n";
            cout << "4.LRU置换算法\n";
            cout << "5.OPT最优置换\n";
            cout << "6.算法对比分析\n";
            cout << "0.返回主菜单\n";
            cout << "请输入选择:";
            cin >> choice;
            switch (choice)
            {
            case 1: inputPages(); break;
            case 2: showPages(); break;
            case 3: FIFO(); break;
            case 4: LRU(); break;
            case 5: OPT(); break;
            case 6: analysis(); break;
            case 0: return;
            default: cout << "输入错误，请重新输入！\n";
            }
        }
    }
};

// 文件管理模块
class File
{
public:
    string fileName;
    int fileSize;
    string fileType;
    string createDate;

    File()
    {
        fileName = "";
        fileSize = 0;
        fileType = "";
        createDate = "";
    }

    File(string name, int size, string type)
    {
        fileName = name;
        fileSize = size;
        fileType = type;
        createDate = "2026-06-20";
    }
};

class Directory
{
public:
    string dirName;
    vector<File> files;

    Directory() { dirName = ""; }
    Directory(string name) { dirName = name; }
};

class FileManager
{
private:
    vector<Directory> directories;
    int totalDiskSize;
    int usedDiskSize;

public:
    FileManager()
    {
        totalDiskSize = 10240;
        usedDiskSize = 0;
    }

    // 创建目录
    void createDirectory()
    {
        string name;
        cout << "\n输入目录名称:";
        cin >> name;
        for (auto& dir : directories)
        {
            if (dir.dirName == name)
            {
                cout << "\n目录已存在!\n";
                return;
            }
        }
        directories.emplace_back(name);
        cout << "\n目录创建成功!\n";
    }

    // 删除目录（连带内部文件）
    void deleteDirectory()
    {
        string name;
        cout << "\n输入目录名称:";
        cin >> name;
        for (auto it = directories.begin(); it != directories.end(); it++)
        {
            if (it->dirName == name)
            {
                // 回收磁盘空间
                for (auto& f : it->files)
                    usedDiskSize -= f.fileSize;
                directories.erase(it);
                cout << "\n目录删除成功!\n";
                return;
            }
        }
        cout << "\n目录不存在!\n";
    }

    void showDirectories()
    {
        if (directories.empty())
        {
            cout << "\n暂无目录!\n";
            return;
        }
        cout << "\n目录列表:\n";
        for (int i = 0; i < directories.size(); i++)
            cout << i + 1 << ". " << directories[i].dirName << endl;
    }

    // 创建文件，增加同目录重名校验
    void createFile()
    {
        string dirName;
        cout << "\n输入所属目录名称:";
        cin >> dirName;
        for (auto& dir : directories)
        {
            if (dir.dirName == dirName)
            {
                string fileName, fileType;
                int fileSize;
                cout << "文件名称:";
                cin >> fileName;
                // 校验同目录重名
                for (auto& f : dir.files)
                {
                    if (f.fileName == fileName)
                    {
                        cout << "该目录下已存在同名文件！\n";
                        return;
                    }
                }
                cout << "文件类型:";
                cin >> fileType;
                cout << "文件大小(KB):";
                cin >> fileSize;
                if (usedDiskSize + fileSize > totalDiskSize)
                {
                    cout << "\n磁盘空间不足，创建失败!\n";
                    return;
                }
                dir.files.emplace_back(fileName, fileSize, fileType);
                usedDiskSize += fileSize;
                cout << "\n文件创建成功!\n";
                return;
            }
        }
        cout << "\n目录不存在!\n";
    }

    void deleteFile()
    {
        string dirName;
        cout << "\n输入所属目录名称:";
        cin >> dirName;
        for (auto& dir : directories)
        {
            if (dir.dirName == dirName)
            {
                string fileName;
                cout << "待删除文件名:";
                cin >> fileName;
                for (auto it = dir.files.begin(); it != dir.files.end(); it++)
                {
                    if (it->fileName == fileName)
                    {
                        usedDiskSize -= it->fileSize;
                        dir.files.erase(it);
                        cout << "\n文件删除成功!\n";
                        return;
                    }
                }
                cout << "目录内无该文件!\n";
                return;
            }
        }
        cout << "\n目录不存在!\n";
    }

    // 全局搜索文件
    void searchFile()
    {
        string target;
        cout << "\n输入要查找的文件名:";
        cin >> target;
        bool findFlag = false;
        for (auto& dir : directories)
        {
            for (auto& file : dir.files)
            {
                if (file.fileName == target)
                {
                    cout << "\n找到文件：\n";
                    cout << "所在目录: " << dir.dirName << endl;
                    cout << "文件大小: " << file.fileSize << " KB\n";
                    cout << "创建日期: " << file.createDate << endl;
                    findFlag = true;
                }
            }
        }
        if (!findFlag)
            cout << "\n未找到该文件!\n";
    }

    // 重命名文件，校验同目录重名
    void renameFile()
    {
        string oldName;
        cout << "\n输入原文件名:";
        cin >> oldName;
        for (auto& dir : directories)
        {
            for (auto& file : dir.files)
            {
                if (file.fileName == oldName)
                {
                    string newName;
                    cout << "输入新文件名:";
                    cin >> newName;
                    // 检查新名称冲突
                    for (auto& f : dir.files)
                    {
                        if (f.fileName == newName && &f != &file)
                        {
                            cout << "目录内已存在同名文件，重命名失败！\n";
                            return;
                        }
                    }
                    file.fileName = newName;
                    cout << "\n文件重命名成功!\n";
                    return;
                }
            }
        }
        cout << "\n文件不存在!\n";
    }

    // 查看指定目录所有文件
    void showFiles()
    {
        string dirName;
        cout << "\n输入目录名称:";
        cin >> dirName;
        for (auto& dir : directories)
        {
            if (dir.dirName == dirName)
            {
                if (dir.files.empty())
                {
                    cout << "\n该目录暂无文件!\n";
                    return;
                }
                cout << "\n";
                cout << left
                    << setw(20) << "文件名"
                    << setw(15) << "大小(KB)"
                    << setw(15) << "类型"
                    << setw(15) << "创建日期"
                    << endl;
                for (auto& f : dir.files)
                {
                    cout << setw(20) << f.fileName
                        << setw(15) << f.fileSize
                        << setw(15) << f.fileType
                        << setw(15) << f.createDate
                        << endl;
                }
                return;
            }
        }
        cout << "\n目录不存在!\n";
    }

    // 打印树形目录结构
    void showTree()
    {
        cout << "\n===========磁盘目录树===========\n";
        for (auto& dir : directories)
        {
            cout << "[DIR] " << dir.dirName << endl;
            for (auto& f : dir.files)
            {
                cout << "    └── " << f.fileName << "." << f.fileType
                    << " (" << f.fileSize << "KB, " << f.createDate << ")" << endl;
            }
        }
    }

    // 磁盘使用统计
    void diskStatistics()
    {
        cout << "\n=====磁盘空间统计=====\n";
        cout << "磁盘总容量: " << totalDiskSize << " KB\n";
        cout << "已使用空间: " << usedDiskSize << " KB\n";
        cout << "剩余空间: " << totalDiskSize - usedDiskSize << " KB\n";
        cout << "目录总数量: " << directories.size() << endl;
        int fileCnt = 0;
        for (auto& dir : directories)
            fileCnt += dir.files.size();
        cout << "文件总数量: " << fileCnt << endl;
    }

    void menu()
    {
        int choice;
        while (true)
        {
            cout << "\n=======文件管理=======\n";
            cout << "1.创建目录\n";
            cout << "2.删除目录\n";
            cout << "3.查看目录列表\n";
            cout << "4.创建文件\n";
            cout << "5.删除文件\n";
            cout << "6.查看目录内文件\n";
            cout << "7.全局搜索文件\n";
            cout << "8.重命名文件\n";
            cout << "9.打印目录树\n";
            cout << "10.磁盘空间统计\n";
            cout << "0.返回主菜单\n";
            cout << "请输入选择:";
            cin >> choice;
            switch (choice)
            {
            case 1: createDirectory(); break;
            case 2: deleteDirectory(); break;
            case 3: showDirectories(); break;
            case 4: createFile(); break;
            case 5: deleteFile(); break;
            case 6: showFiles(); break;
            case 7: searchFile(); break;
            case 8: renameFile(); break;
            case 9: showTree(); break;
            case 10: diskStatistics(); break;
            case 0: return;
            default: cout << "输入错误，请重新输入！\n";
            }
        }
    }
};

// 主菜单
void showMainMenu()
{
    cout << "\n========================================\n";
    cout << "      操作系统课程设计模拟系统\n";
    cout << "========================================\n";
    cout << "1.CPU进程调度模块\n";
    cout << "2.内存页面置换模块\n";
    cout << "3.文件目录管理模块\n";
    cout << "0.退出系统\n";
    cout << "========================================\n";
    cout << "请选择功能模块:";
}

int main()
{
    CPUManager cpuManager;
    MemoryManager memoryManager;
    FileManager fileManager;
    int choice;
    while (true)
    {
        showMainMenu();
        cin >> choice;
        switch (choice)
        {
        case 1: cpuManager.menu(); break;
        case 2: memoryManager.menu(); break;
        case 3: fileManager.menu(); break;
        case 0:
            cout << "\n系统正常退出，再见！\n";
            return 0;
        default:
            cout << "\n输入选项不存在，请重新输入！\n";
        }
    }
    return 0;
}