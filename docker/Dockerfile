# Build:
#   docker build --build-arg UID=$(id -u) --rm -t visp -f ./docker/Dockerfile .

FROM vispci/vispci:ubuntu-20.04

RUN apt update && apt upgrade -y

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apt-get update \
  && apt-get install -y build-essential \
      gcc \
      g++ \
      gdb \
      clang \
      make \
      ninja-build \
      cmake \
      autoconf \
      automake \
      locales-all \
      dos2unix \
      rsync \
      tar \
      python \
      python-dev \
  && apt-get clean

RUN apt-get install cmake-qt-gui cmake-curses-gui


#ARG UID=1000
#RUN useradd -m -u ${UID} -s /bin/bash builder
#USER builder

