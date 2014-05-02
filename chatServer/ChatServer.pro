TEMPLATE=app
SOURCES=ChatServer.cpp		\
		ServerWindows.cpp	\
		ChatException.cpp	\
		ServerSocket.cpp	\
		ThAccept.cpp		\
		ThClient.cpp
HEADERS=ServerWindows.h		\		
		ChatException.h		\
		ServerSocket.h		\
		ThAccept.h		\
		ThClient.h
CONFIG=release qt
QT=core gui
TARGET=server
