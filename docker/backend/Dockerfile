FROM debian:12.5
COPY .    /opt/study-test/
RUN apt update
RUN apt install -y libqt5core5a libqt5network5
WORKDIR /opt/study-test/
EXPOSE 7500
CMD /opt/study-test/cpp-qt-qhttpengine-server
