FROM ubuntu:16.04
MAINTAINER Oskar Østby

RUN apt-get update -qq && apt-get install -qqy \
    build-essential \
    cmake \
    make \
    git \
    libsfml-dev \
    gcc \
    g++ \
    clang
    


COPY ./ /workspace
WORKDIR /workspace
RUN /bin/bash ./build.sh
