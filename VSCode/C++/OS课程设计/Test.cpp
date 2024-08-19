#include <bits/stdc++.h>

struct filenode {
    bool isdir;                 // 是否为目录
    std::string filename;       // 目录/文件名
    filenode *parent, *child;   // 父母节点和儿子节点
    filenode *pre, *next;       // 前驱节点和后驱节点
};

filenode *root, *now, *lst;             // 根节点，目录节点，当前目录下最后一个目录/文件节点
std::string path = "/", cur = "root";   // 当前路径
std::vector<std::string> cnt;           // 记录使用的命令
std::filesystem::path current_path = std::filesystem::current_path(); // 获取当前目录

// 目录操作
// mkdir : 创建目录
// rmdir : 删除目录
// mvdir : 修改目录的名字
// cd : 改变当前目录
// pwd : 显示当前目录
// ls : 显示当前目录下的内容

void mkdir() {
    std::string s;
    std::cin >> s;

    filenode *p = new(filenode);
    p->isdir = 1;
    p->parent = now;
    p->child = nullptr;
    p->pre = p->next = nullptr;
    p->filename = s;

    filenode *t = now->child;
    while (t != nullptr) {
        if (t->filename == p->filename) {
            return;
        }
        t = t->next;
    }

    if (p->filename[0] == '.') {
        std::cout << "不能以'.'作为文件开头" << "\n";
        return;
    }
    if (now->child == nullptr) {
        now->child = p;
        lst = p;
    } else {
        lst->next = p;
        p->pre = lst;
        lst = p;
    }

    // 文件夹路径
    std::filesystem::path new_folder_path = current_path / cur / s;
    // 创建文件夹
    std::filesystem::create_directory(new_folder_path);
}

void rmdir() {
    std::string s;
    std::cin >> s;

    filenode *p = now->child;
    while (p != nullptr) {
        if (p->isdir == 1 && p->filename == s) {
            if (now->child == lst) {
                now->child = nullptr;
                lst = nullptr;
            } else if (p == now->child) {
                now->child = p->next;
                p->next->pre = nullptr;
            } else if (p == lst) {
                p->pre->next = nullptr;
                lst = p->pre;
            } else {
                p->next->pre = p->pre;
                p->pre->next = p->next;
            }
            break;
        }
        p = p->next;
    }

    if (p == nullptr) {
        std::cout << "no such directory: " << s << "\n";
        return;
    }

    // 构造完整的文件夹路径
    std::filesystem::path folder_path = current_path / cur / s;
    // 移除文件夹
    std::filesystem::remove_all(folder_path);
}

void mvdir() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    filenode *p = now->child;
    while (p != nullptr) {
        if (p->isdir == 1 && p->filename == s1) {
            p->filename = s2;
            break;
        }
        p = p->next;
    }

    if (p == nullptr) {
        std::cout << "no such directory: " << s1 << "\n";
        return;
    }

    // 当前文件夹的名字
    std::filesystem::path old_folder_name = current_path / cur / s1;
    // 新文件夹的名字
    std::filesystem::path new_folder_name = current_path / cur / s2;
    // 重命名文件夹
    std::filesystem::rename(old_folder_name, new_folder_name);
}

void cd() {
    std::string s, pt = path;
    std::cin >> s;

    filenode *p = now;
    if (s[0] == '/') {
        p = root;
        pt = "/";
    }

    for (int i = 0, j = 0; i < s.size(); i = j) {
        j = i;
        std::string t;
        int cnt = 0;

        while (j < s.size() && s[j] == '/') {
            j++;
        }
        while (j < s.size() && s[j] != '/') {
            t += s[j];
            if (s[j] == '.') cnt++;
            j++;
        }
        while (j < s.size() && s[j] == '/') {
            j++;
        }

        if (t[0] == '.') {
            if (cnt == t.size()) {
                for (int i = 1; i < t.size(); i++) {
                    if (p == root) {
                        break;
                    }
                    p = p->parent;
                    while (pt[pt.size() - 1] != '/') {
                        pt.pop_back();
                    }
                    if (pt.size() > 1 && pt[pt.size() - 1] == '/') {
                        pt.pop_back();
                    }
                }
            } else {
                std::cout << "no such file or directory: " << s << "\n";
                return;
            }
        } else {
            filenode *f = p->child;
            while (f != nullptr) {
                if (f->isdir == 1 && f->filename == t) {
                    break;
                }
                f = f->next;
            }
            if (f == nullptr) {
                std::cout << "no such file or directory: " << s << "\n";
                return;
            }
            p = f;
            if (pt[pt.size() - 1] != '/') pt += "/";
            pt += t;
        }
    }
    now = p;
    path = pt;
    cur = "root" + path;
    lst = p->child;
    while (lst != nullptr && lst->next != nullptr) {
        lst = lst->next;
    }
}

void pwd() {
    std::cout << path;
}

void ls() {
    filenode *p = now->child;
    int tot1 = 0, tot2 = 0;
    while (p != nullptr) {
        if (p->isdir == 1) {
            tot1++;
        } else {
            tot2++;
        }
        if (p->isdir) {
            std::cout << "Directory\t" << p->filename << "\n";
        } else {
            std::cout << "File     \t" << p->filename << "\n";
        }

        p = p->next;
    }
    std::cout << "目录: " << tot1 << "\t\t" << "文件: " << tot2 << "\n";
}

// 文件操作
// cp : 复制文件或目录
// rm : 删除文件
// mv : 改变文件名或移动文件
// file : 显示文件类型
// write : 写文件
// read : 读文件
// touch : 创建文件
// open : 打开文件

void cp() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    filenode *p1, *p2;
    p1 = now->child;
    while (p1 != nullptr && p1->filename != s1) {
        p1 = p1->next;
    }
    p2 = now->child;
    while (p2 != nullptr && p2->filename != s2) {
        p2 = p2->next;
    }

    if (p1 == nullptr) {
        std::cout << "no such file or directory: " << s1 << "\n";
        return;
    } else if (p2 == nullptr) {
        filenode *p = new(filenode);
        p->filename = s2;
        p->isdir = p1->isdir;
        p->parent = p1->parent;
        p->child = p1->child;
        p->pre = lst;
        p->next = nullptr;
        lst->next = p;
        lst = p;
    } else {
        p2->isdir = p1->isdir;
        p2->child = p1->child;
    }

    // 原始文件/文件夹的名称
    std::filesystem::path source = current_path / cur / s1;
    // 目标文件/文件夹的名称
    std::filesystem::path target = current_path / cur / s2;
    // 复制文件/文件夹的内容
    std::filesystem::copy(source, target, std::filesystem::copy_options::recursive);
}

void rm() {
    std::string s;
    std::cin >> s;

    filenode *p = now->child;
    while (p != nullptr) {
        if (p->isdir == 0 && p->filename == s) {
            if (now->child == lst) {
                now->child = nullptr;
                lst = nullptr;
            } else if (p == now->child) {
                now->child = p->next;
                p->next->pre = nullptr;
            } else if (p == lst) {
                p->pre->next = nullptr;
                lst = p->pre;
            } else {
                p->next->pre = p->pre;
                p->pre->next = p->next;
            }
            break;
        }
        p = p->next;
    }

    if (p == nullptr) {
        std::cout << "no such file: " << s << "\n";
        return;
    }

    // 构造完整的文件路径
    std::filesystem::path file_path = current_path / cur / s;
    // 删除文件
    std::filesystem::remove(file_path);
}

void mv() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    filenode *p = now->child;
    while (p != nullptr) {
        if (p->isdir == 0 && p->filename == s1) {
            p->filename = s2;
            break;
        }
        p = p->next;
    }

    if (p == nullptr) {
        std::cout << "no such file: " << s1 << "\n";
        return;
    }
    
    // 当前文件的名字
    std::filesystem::path old_file_name = current_path / cur / s1;
    // 新文件的名字
    std::filesystem::path new_file_name = current_path / cur / s2;
    // 重命名文件
    std::filesystem::rename(old_file_name, new_file_name);
}

void file() {
    std::string s;
    std::cin >> s;

    filenode *p = now->child;
    while (p != nullptr && p->filename != s) {
        p = p->next;
    }

    if (p == nullptr) {
        std::cout << "no such file or directory: " << s << "\n";
    } else {
        if (p->isdir == 1) {
            std::cout << "文件类型: 目录" << "\n";
        } else {
            std::cout << "文件类型: 文件" << "\n";
        }
    }
}

void write() {
    std::string s, t;
    std::cin >> s;
    getchar();
    
    filenode *p = now->child;
    while (p != nullptr) {
        if (p->isdir == 0 && p->filename == s) {
            std::getline(std::cin, t);
            break;
        }
        p = p->next;
    }
    
    if (p == nullptr) {
        std::cout << "no such file: " << s << "\n";
        return;
    }

    // 获取当前文件的路径
    std::string file_path = current_path / cur / s;
    // 打开文件
    std::ofstream outfile(file_path, std::ios::app);
    // 写入一些文本到文件
    outfile << t << "\n";
    // 关闭文件
    outfile.close(); 
}

void read() {
    std::string s;
    std::cin >> s;
    
    filenode *p = now->child;
    while (p != nullptr) {
        if (p->isdir == 0 && p->filename == s) {
            break;
        }
        p = p->next;
    }

    if (p == nullptr) {
        std::cout << "no such file: " << s << "\n";
        return;
    }

    // 获取当前文件的路径
    std::string file_path = current_path / cur / s;
    // 创建文件流对象用于读取
    std::ifstream infile(file_path);

    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << "\n";
    }
    // 关闭文件
    infile.close();
}

void touch() {
    std::string s;
    std::cin >> s;

    filenode *p = new(filenode);
    p->isdir = 0;
    p->parent = now;
    p->child = nullptr;
    p->pre = p->next = nullptr;
    p->filename = s;

    filenode *t = now->child;
    while (t != nullptr) {
        if (t->filename == p->filename) {
            return;
        }
        t = t->next;
    }

    if (p->filename[0] == '.') {
        std::cout << "不能以'.'作为文件开头" << "\n";
        return;
    }
    if (now->child == nullptr) {
        now->child = p;
        lst = p;
    } else {
        lst->next = p;
        p->pre = lst;
        lst = p;
    }

    // 获取当前文件的路径
    std::string file_path = current_path / cur / s;
    // 创建文件
    std::ofstream outfile(file_path);
    // 关闭文件
    outfile.close();
}

void open() {
    std::string s;
    std::cin >> s;
    std::string file_path = current_path / cur / s;
    system(("open " + file_path).c_str());
}

// 时间操作: 
// date : 显示系统当前时间和日期
// cal : 显示日历

void date() {
    auto now = std::chrono::system_clock::now();
    
    // 将时间点转换为time_t类型
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    
    // 转换为本地时间
    std::tm* now_tm = std::localtime(&now_time_t);
    
    // 格式化日期和时间输出
    std::cout << std::put_time(now_tm, "%Y年%m月%d日 %H时%M分%S秒") << "\n";
}

void cal() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);
    
    // 获取当前年和月
    int year = now_tm.tm_year + 1900; // tm_year从1900开始计数，所以要加1900
    int month = now_tm.tm_mon + 1;    // tm_mon从0开始计数，所以要加1
    std::cout << "       " << year << "年" << month << "月" << "\n";
 
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[1] = 29; // 闰年2月29天
    }

    std::cout << " 日 一 二 三 四 五 六\n";

    // 获取指定月份的第一天是星期几
    std::tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
    std::mktime(&time_in);

    int start_day = time_in.tm_wday;
    int days_in_month = daysInMonth[month - 1];
    for (int i = 0; i < start_day; ++i) {
        std::cout << "   ";
    }

    for (int day = 1; day <= days_in_month; ++day) {
        std::cout << std::setw(3) << day;
        if ((day + start_day) % 7 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

// Korn Shell命令
// history : 列出最近执行过的几条命令(10条)

void history() {
    for (int i = 0; i < cnt.size(); i++) {
        if (i < 9) {
            std::cout << i + 1 << "  : " << cnt[i] << "\n";
        } else {
            std::cout << i + 1 << " : " << cnt[i] << "\n";
        }
    }
}

// 其他命令
// help : 显示所有命令
// clear : 清除屏幕或窗口内容
// exit : 退出

void help() {
    std::cout << "-----------------------------------\n";
    std::cout << "目录操作" << "\n";
    std::cout << "mkdir:\t 创建目录" << "\n";
    std::cout << "rmdir:\t 删除目录" << "\n";
    std::cout << "mvdir:\t 修改目录的名字" << "\n";
    std::cout << "cd:\t 改变当前目录" << "\n";
    std::cout << "pwd:\t 显示当前目录" << "\n";
    std::cout << "ls:\t 显示当前目录下的内容" << "\n";
    std::cout << "-----------------------------------\n";
    std::cout << "文件操作" << "\n";
    std::cout << "cp:\t 复制文件或目录" << "\n";
    std::cout << "rm:\t 删除文件" << "\n";
    std::cout << "mv:\t 改变文件名或移动文件" << "\n";
    std::cout << "file:\t 显示文件类型" << "\n";
    std::cout << "write:\t 写文件" << "\n";
    std::cout << "read:\t 读文件" << "\n";
    std::cout << "touch:\t 创建文件" << "\n";
    std::cout << "open:\t 打开文件" << "\n";
    std::cout << "-----------------------------------\n";
    std::cout << "时间操作" << "\n";
    std::cout << "date:\t 显示系统当前时间和日期" << "\n";
    std::cout << "cal:\t 显示日历" << "\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Korn Shell命令" << "\n";
    std::cout << "history: 列出最近执行过的几条命令(10条)" << "\n";
    std::cout << "-----------------------------------\n";
    std::cout << "其他命令" << "\n";
    std::cout << "help:\t 显示所有命令" << "\n";
    std::cout << "clear:\t 清除屏幕或窗口内容" << "\n";
    std::cout << "exit:\t 退出" << "\n";
    std::cout << "-----------------------------------\n";
}

void clear() {
    system("cls");   // Windows: cls
    system("clear"); // Unix/Linux: clear
}

void run() {
    std::cout << "-----------------------------------\n";
    std::cout << "\t虚拟文件管理系统" << "\n";
    std::cout << "      输入help查询可用命令" << "\n";
    std::cout << "-----------------------------------\n";
    
    while (true) {
        std::cout << "FileSystem:";
        pwd();
        std::cout << ">";

        std::string s;
        std::cin >> s;

        if (s == "mkdir") {
            mkdir();
        } else if (s == "rmdir") {
            rmdir();
        } else if (s == "mvdir") {
            mvdir();
        } else if (s == "pwd") {
            pwd();
            std::cout << "\n";
        } else if (s == "cd") {
            cd();
        } else if (s == "ls") {
            ls();
        } else if (s == "cp") {
            cp();
        } else if (s == "rm") {
            rm();
        } else if (s == "mv") {
            mv();
        } else if (s == "file") {
            file();
        } else if (s == "write") {
            write();
        } else if (s == "read") {
            read();
        } else if (s == "touch") {
            touch();
        } else if (s == "open") {
            open();
        } else if (s == "date") {
            date();
        } else if (s == "cal") {
            cal();
        } else if (s == "history") {
            history();
        } else if (s == "clear") {
            clear();
        } else if (s == "exit") {
            exit(0);
        } else if (s == "help") {
            help();
        } else {
            std::cout << "command not found: " << s << "\n";
        }

        if (s != "history") {
            if (cnt.size() < 10) {
                cnt.push_back(s);
            } else {
                cnt.erase(cnt.begin());
                cnt.push_back(s);
            }
        }
    }
}

void init() {
    root = new(filenode);
    root->isdir = 1;
    root->filename = "root";
    root->child = root->parent = nullptr;
    root->pre = root->next = nullptr;
    now = root;

    std::string rt = "root";
    std::filesystem::path new_folder_path = current_path / rt;
    
    if (!std::filesystem::exists(new_folder_path)) {
        std::filesystem::create_directory(new_folder_path);
    } else {
        auto dfs = [&](auto &&self, std::filesystem::path x, filenode *p) -> void {
            filenode *pt = p->child;
            for (const auto& entry : std::filesystem::directory_iterator(x)) {
                std::string s = entry.path().filename();

                if (s[0] == '.') {
                    continue;
                }
                
                filenode *t = new(filenode);
                t->child = nullptr;
                t->parent = p;
                t->pre = pt;
                t->next = nullptr;
                t->filename = s;
                
                if (entry.is_directory()) {
                    t->isdir = 1;
                } else {
                    t->isdir = 0;
                }
                
                if (pt != nullptr) {
                    pt->next = t;
                }
                pt = t;

                if (pt->pre == nullptr) {
                    p->child = pt;
                }
                
                if (entry.is_directory()) {
                    self(self, x / s, pt);
                }
            }
        };
        dfs(dfs, new_folder_path, root);
        
        now = root;
        lst = now->child;
        while (lst != nullptr && lst->next != nullptr) {
            lst = lst->next;
        }
    }
}

int main() {
    init();
    run();
    return 0;
}