TEMPLATE=app
SOURCES=ChatClient.cpp	\
	ClientWindow.cpp \	
    ChatException.cpp \
    ThRecv.cpp \
    ClientSocket.cpp \
    SendMessage.cpp \
    LoginDialog.cpp \
    IpAddress.cpp \
    PrivateChatWindow.cpp \
    ClientServerSocket.cpp \
    PrivateIpAddress.cpp \
    PrivateServerWindow.cpp \
    PrivateSendMessage.cpp \
    ThPrivateRecv.cpp \
    JudgeDialog.cpp \
    ThAccept.cpp \
    PrivateClientSocket.cpp

HEADERS=ClientWindow.h \
    ChatException.h \
    ThRecv.h \
    ClientSocket.h \
    SendMessage.h \
    LoginDialog.h \
    LoginData.h \
    IpAddress.h \
    ConnectData.h \
    PrivateChatWindow.h \
    ClientServerSocket.h \
    PrivateIpAddress.h \
    PrivateServerWindow.h \
    PrivateSendMessage.h \
    PrivateConnectData.h \
    ThPrivateRecv.h \
    JudgeDialog.h \
    ThAccept.h \
    PrivateClientSocket.h

CONFIG=release qt
QT=core gui
TARGET=Client
