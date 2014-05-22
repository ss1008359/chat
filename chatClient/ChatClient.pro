TEMPLATE=app
SOURCES=ChatClient.cpp	\
	ClientWindow.cpp \	
    ChatException.cpp \
    ThRecv.cpp \
    ClientSocket.cpp \
    SendMessage.cpp \
    LoginDialog.cpp \
    IpAddress.cpp \
    ThPrivateChat.cpp \
    PrivateChatWindow.cpp \
    ClientServerSocket.cpp \
    ThClientAccept.cpp \
    PrivateIpAddress.cpp

HEADERS=ClientWindow.h \
    ChatException.h \
    ThRecv.h \
    ClientSocket.h \
    SendMessage.h \
    LoginDialog.h \
    LoginData.h \
    IpAddress.h \
    ConnectData.h \
    ThPrivateChat.h \
    PrivateChatWindow.h \
    ClientServerSocket.h \
    ThClientAccept.h \
    PrivateIpAddress.h

CONFIG=release qt
QT=core gui
TARGET=Client
