TEMPLATE=app
SOURCES=ChatClient.cpp	\
	ClientWindow.cpp \	
    ChatException.cpp \
    ThRecv.cpp \
    ClientSocket.cpp \
    SendMessage.cpp \
    LoginDialog.cpp

HEADERS=ClientWindow.h \
    ChatException.h \
    ThRecv.h \
    ClientSocket.h \
    SendMessage.h \
    LoginDialog.h

CONFIG=release qt
QT=core gui
TARGET=Client
