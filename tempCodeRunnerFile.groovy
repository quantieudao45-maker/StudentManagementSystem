#include <stdio.h>
#include <string.h>

// Định nghĩa struct lưu trạng thái đăng nhập
typedef struct {
    char password[10]; // Chỉ dành 10 ký tự cho mật khẩu
    int isAdmin;       // Biến cờ: 0 là user thường, 1 là Admin
} UserContext;

int main() {
    UserContext user;
    
    // Mặc định không phải admin
    user.isAdmin = 0; 
    
    printf("Enter password: ");
    // LỖI CHẾT NGƯỜI Ở ĐÂY: gets() không kiểm tra độ dài chuỗi nhập vào
    gets(user.password); 

    // Kiểm tra mật khẩu (giả sử mật khẩu đúng là "secure")
    if (strcmp(user.password, "secure") == 0) {
        user.isAdmin = 1;
    }

    // Logic kiểm tra quyền
    if (user.isAdmin != 0) {
        printf("\n[+] ACCESS GRANTED: Welcome Admin!\n");
        printf("Secret Data: Hom nay troi rat dep.\n");
    } else {
        printf("\n[-] ACCESS DENIED: Wrong password.\n");
    }

    return 0;
}