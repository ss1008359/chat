TEMPLATE=app
SOURCES=ChatServer.cpp		\
		ServerWindows.cpp	\
		ChatException.cpp	\
		ServerSocket.cpp	\
		ThAccept.cpp		\
		ThClient.cpp \
                IpAddress.cpp
HEADERS=ServerWindows.h		\		
		ChatException.h		\
		ServerSocket.h		\
		ThAccept.h		\
		ThClient.h \
                IpAddress.h
CONFIG=release qt
QT=core gui network
TARGET=server
