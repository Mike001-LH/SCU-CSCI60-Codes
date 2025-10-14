// …（说明：这份文件专门“定义/实现”duration.h 里声明过的函数）
#include "duration.h" // 一定要先包含头文件，确保签名一致

// “桩实现”：先返回 mins 的字符串形式
string Duration::toString() {      // 注意这里的 Duration::（作用域解析）在类体外定义要使用域限定符"::"
    // TODO：以后把格式改成 "x hrs, y mins"
    return to_string(mins);        // 把 int 转成 string
}
