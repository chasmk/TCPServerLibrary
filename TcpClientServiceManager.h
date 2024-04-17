#ifndef __TCPCLIENTSERVICEMANAGER__
#define __TCPCLIENTSERVICEMANAGER__

class TcpServerController;

class TcpClientServiceManager
{
private:
    /* data */
public:
    TcpClientServiceManager(TcpServerController*);
    ~TcpClientServiceManager();

    TcpServerController* tcp_ctrlr;
};



#endif