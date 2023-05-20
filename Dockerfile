FROM ubuntu:latest

ENV TZ=Europe/Moscow

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get upgrade -y

RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y

WORKDIR /root/
RUN mkdir server
WORKDIR /root/release/
COPY *.cpp /root/release/
COPY *.h /root/release/
COPY *.pro /root/release/

RUN qmake Tcp_server_v3.pro
RUN make

ENTRYPOINT ["./main"]