#ifndef __TCPCLIENTDBMANAGER__
#define __TCPCLIENTDBMANAGER__

#include<list>

class TcpClient;
class TcpServerController;

class TcpClientDbManager
{
private:
    std::list<TcpClient*> tcp_client_db;
    
public:
    TcpClientDbManager(TcpServerController*);
    ~TcpClientDbManager();

    TcpServerController* tcp_ctrlr;
};



#endif