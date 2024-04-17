#ifndef __TCPSERVERCONTROLLER__
#define __TCPSERVERCONTROLLER__

#include <stdint.h>
#include <string>

/*前向声明*/
class TcpNewConnectionAcceptor;
class TcpClientDbManager;
class TcpClientServiceManager;



class TcpServerController
{
private:
    TcpNewConnectionAcceptor* tcp_new_conn_acc; //CAS
    TcpClientDbManager* tcp_client_db_mgr;      //DBMS
    TcpClientServiceManager* tcp_client_svc_mgr;//DRS
    
public:
    TcpServerController(std::string ip, uint16_t port, std::string name);
    ~TcpServerController();

    void Start();
    void Stop();

    uint32_t ip_addr;//ip地址
    uint16_t port_no;//端口号
    std::string name;

};




#endif