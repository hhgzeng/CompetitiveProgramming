#include <bits/stdc++.h>

using i64 = long long;

void readandwrite() {
    std::fstream file("1.txt", std::ios::in | std::ios::out); // 打开文件用于读写

    if (!file.is_open()) {
        std::cerr << "无法打开文件!" << "\n";
        return;
    }

    // 首先读取一些内容
    std::string line;
    std::getline(file, line);
    std::cout << "读取的行: " << line << "\n";

    // 移动到文件末尾，准备写入
    file.seekp(0, std::ios::end);

    // 写入新的内容
    file << "\n新的一行文本。";

    file.close(); // 关闭文件
}

void read() {
    std::filesystem::path current_path = std::filesystem::current_path();
    std::string file_path = current_path / "1.txt";
    std::ifstream infile(file_path); // 创建文件流对象用于读取

    if (!infile.is_open()) {
        std::cerr << "无法打开文件进行读取!" << "\n";
        return;
    }

    std::string line;
    // 逐行读取文件内容
    while (std::getline(infile, line)) {
        std::cout << line << "\n"; // 打印读取的每一行
    }

    infile.close(); // 关闭文件
}

void write() {
    std::filesystem::path current_path = std::filesystem::current_path();
    std::string file_path = current_path / "2.txt";
    std::ofstream outfile(file_path); // 创建/打开文件用于写入

    if (!outfile.is_open()) {
        std::cerr << "无法打开文件进行写入!" << "\n";
        return;
    }

    // 写入一些文本到文件
    outfile << "Hello, World!\n";
    outfile << "这是文件写入操作的一个示例。" << "\n";

    outfile.close(); // 关闭文件
}

void rm() {
    // 指定要删除的文件名称
    std::string file_name = "2.txt";

    // 获取当前工作目录
    std::filesystem::path current_path = std::filesystem::current_path();

    // 构造完整的文件路径
    std::filesystem::path file_path = current_path / file_name;

    // 检查文件是否存在
    if (std::filesystem::exists(file_path)) {
        try {
            // 删除文件
            std::filesystem::remove(file_path);
            std::cout << "文件已被删除: " << file_path << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "删除文件时出错: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "文件不存在: " << file_path << std::endl;
    }
}

void open() {
    std::filesystem::path current_path = std::filesystem::current_path();
    std::string file_path = current_path / "2.txt";
    system(("open " + file_path).c_str());
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        // solve();
        // read();
        // readandwrite();
        // rm();
        // write();
        open();
    }

    return 0;
}