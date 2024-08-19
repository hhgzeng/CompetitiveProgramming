#include <bits/stdc++.h>

using i64 = long long;

void mkdir() {
    std::string folder_name = "root";

    // 获取当前工作目录
    std::filesystem::path current_path = std::filesystem::current_path();

    // 构造完整的文件夹路径
    std::filesystem::path new_folder_path = current_path / folder_name;

    // 检查文件夹是否已存在
    if (!std::filesystem::exists(new_folder_path)) {
        // 创建文件夹
        if (std::filesystem::create_directory(new_folder_path)) {
            std::cout << "文件夹已创建在：" << new_folder_path << "\n";
        } else {
            std::cerr << "创建文件夹失败。" << "\n";
        }
    } else {
        std::cout << "文件夹已存在：" << new_folder_path << "\n";
    }
}

void rmdir() {
    // 指定要删除的文件夹名称
    std::string folder_name = "file/";

    // 获取当前工作目录
    std::filesystem::path current_path = std::filesystem::current_path();

    // 构造完整的文件夹路径
    std::filesystem::path folder_path = current_path / folder_name;

    // 检查文件夹是否存在
    if (std::filesystem::exists(folder_path) && std::filesystem::is_directory(folder_path)) {
        try {
            // 删除文件夹及其所有内容
            std::filesystem::remove_all(folder_path);
            std::cout << "文件夹及其内容已被删除: " << folder_path << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "删除文件夹时出错: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "文件夹不存在或提供的路径不是一个文件夹: " << folder_path << std::endl;
    }

}

void mvdir() {
    // 当前文件夹的名字
    std::filesystem::path old_folder_name = "old_directory_name";

    // 新文件夹的名字
    std::filesystem::path new_folder_name = "new_directory_name";

    // 检查旧文件夹是否存在
    if (std::filesystem::exists(old_folder_name) && std::filesystem::is_directory(old_folder_name)) {
        try {
            // 重命名文件夹
            std::filesystem::rename(old_folder_name, new_folder_name);
            std::cout << "文件夹已重命名为: " << new_folder_name << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "重命名文件夹时出错: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "旧文件夹不存在或不是一个目录: " << old_folder_name << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        rmdir();
    }

    return 0;
}