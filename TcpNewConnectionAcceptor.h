#ifndef __TCPNEWCONNECTIONACCEPTOR__
#define __TCPNEWCONNECTIONACCEPTOR__

class TcpServerController;

class TcpNewConnectionAcceptor
{
private:
    /* data */
public:
    TcpNewConnectionAcceptor(TcpServerController*);
    ~TcpNewConnectionAcceptor();

    TcpServerController* tcp_ctrlr;
};



#endif