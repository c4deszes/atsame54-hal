# Base image
FROM resin/rpi-raspbian

WORKDIR /usr/dev
RUN apt-get update

# Install base tools
RUN apt-get install \
            git \
            autoconf \
            libtool \
            wget \
            lbzip2 \
            build-essential \
            autoconf autogen \
            bison dejagnu flex \
            flip gawk gperf \
            gzip nsis openssh-client \
            p7zip-full perl python-dev \
            libisl-dev scons tcl \
            tofrodos wget zip libncurses5-dev \
            pkg-config \
            python3-pip

# Install GCC
RUN apt-get install \
            gcc \
            g++ \
            make \
            gdb

# Install CMake
#   Install openssl
RUN sudo apt-get install libssl-dev
RUN export OPENSSL_ROOT_DIR=/usr/bin/openssl
#   Clone repository
RUN git clone https://github.com/Kitware/CMake.git cmake-source
#   Build from source
WORKDIR /usr/dev/cmake-source
RUN git checkout v3.20.2
RUN ./bootstrap && make && sudo make install

# Install ARM GCC
#   Download
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-src.tar.bz2
RUN tar -xf gcc-arm-none-eabi-10.3-2021.07-src.tar.bz2
#   Build
WORKDIR /usr/dev/gcc-arm-none-eabi-10.3-2021.07
RUN ./install-sources.sh --skip_steps=mingw32
RUN ./build-prerequisites.sh --skip_steps=mingw32
RUN ./build-toolchain.sh --skip_steps=mingw32,manual

# Install OpenOCD
#   Clone from xpack
# RUN apt-get install libusb-1.0-0 libusb-1.0-0-dev
# 

CMD [ "/bin/sh" ]
