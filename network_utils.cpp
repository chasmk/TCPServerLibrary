#include<network_utils.h>
#include <sys/socket.h>   
#include <netinet/in.h>   
#include <arpa/inet.h>   
#include <string.h>  
/*
函数将 uint32_t ip_addr 转换为 A.B.C.D 格式。
如果调用者 fn 传递 ptr 到 output_buffer（第 2 个参数），则函数在此输出缓冲区中返回结果。
如果调用者 fn 传递 NULL 作为第 2 个参数，那么函数将在本地 16B 的静态缓冲区中返回结果。
https://man7.org/linux/man-pages/man3/inet_ntop.3.html
*/
char * network_convert_ip_n_to_p(uint32_t ip_addr, char *output_buffer){
    //获取缓冲区指针
    static char buffer[16];
    char* tmp = output_buffer == nullptr ? buffer : output_buffer;

    //主机字节序->网络字节序
    uint32_t ip_addr_nl = htonl(ip_addr);
    in_addr in_addr_nl;
    in_addr_nl.s_addr = ip_addr_nl;

    //将数值格式转化为点分十进制的ip地址格式,ipv4和6都适用, 结果会存到tmp
    inet_ntop(AF_INET, &in_addr_nl, tmp, 16);

    return tmp;
}

/*
函数与 Ist fn 完全相反，它将 A.B.C.D 格式的 IP 地址转换为 uint32_t 格式。
*/
uint32_t network_covert_ip_p_to_n(const char *ip_addr) {
    uint32_t res;
    //尝试转换由strptr指针所指向的字符串，并通过addrptr指针存放二进制结果，
    //若成功则返回值为1，否则如果所指定的family而言输入字符串不是有效的表达式格式，那么返回值为0.
    inet_pton(AF_INET, ip_addr, &res);
    res = htonl(res);//主机字节序->网络字节序
    return res;
}