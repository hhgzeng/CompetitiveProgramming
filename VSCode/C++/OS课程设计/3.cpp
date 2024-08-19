#include <iostream>
#include <filesystem>

struct node {
    int data;
    node *next;
};

void getnext(node *p) {
    node *t = new(node);
    t->data = 200;
    t->next = nullptr;
    p->next = t;
    p = t;
}

void open() {
     // 获取当前工作目录
    std::filesystem::path current_path = std::filesystem::current_path();

    // 构造完整的文件夹路径
    std::filesystem::path new_folder_path = current_path / "root";
    std::string file_path = current_path / "root" ;
    system(("open " + file_path).c_str());
}

int main() {
    open();
    return 0;
    
    node *head = new(node);
    head->data = 100;
    head->next = nullptr;

    getnext(head);
    
    while (head != nullptr) {
        std::cout << head->data << "\n";
        head = head->next;
    }

    return 0;
}